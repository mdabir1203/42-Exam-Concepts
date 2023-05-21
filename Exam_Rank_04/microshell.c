#include "microshell.h"

int	write_error(char *string, char *argv)
{
	while (string && *string)
		write(2, string++, 1);
	if (argv)
		while(*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}


/**
 * Used to execute a command passed to it
-> The function denotes like cooking a dish in the kitchen. And:
  av -> list of ingredients -> i -> current ingredient
  tmp_fd -> cutting board  to prepare the ingredient
  dup2 (tmp_fd, STDIN_FILENO) -> is moving the ingredient to the stove or oven
  close -> keep the board away
  execve -> actual cooking process. Takes the instruction(cmd) and prepares the ingredient(the argument)
  and kitchen tools(envp) to execute.
  If an error -> oven not working -> calls the write_error function to print

*/
int	ft_exe(char **argv, int i, int temporary_file_descriptor, char **environment_variables)
{
	argv[i] = NULL;
	dup2(temporary_file_descriptor, STDIN_FILENO);
	close(temporary_file_descriptor);
	execve(argv[0], argv, environment_variables);
	return (write_error("error: cannot execute ", argv[0]));
}

/**
 *Imagine running a restaurant and having a list of customer orders to fullfil. 
  Each order consists of series of dishes to prepare and serve. In order to comple
  each order follow specific workflow <_>

  1. Setup the kitchen with necessary utensils, ingredients and equipment ->initial setup
   of shell environment and file descriptor.
  2. Break the dishes into smaller sub-tasks to be executed sequentially. Breaking down of 
   cmd arguments and separating them into individual cmd to be executed one by one.
  3. For every cmd -> the type of tasks needs to be determined.
     -> includes : preparing a specific dish  / cleaning set of utensils -> (for ex: builtin "cd" 
	 or system command to be executed.
  4. If cmd builtin -> execute directly and move to the next like serving glass of water and
     move on to the next item in the order.
  5. If cmd is system cmd -> we have to determine if executed alone or part of pipeline
   IF alone executed -> fork the child process and execute command in child process 

  6. Otherwise -> create new pipe and fork a child to execute first cmd in pipeline ->then
    pass output of that cmd to the next cmd in the pipeline. 
	Its like preparing a dish requiring multiple steps, like cooking a pasta dish requiring 
	boiling water and preparing the sauce separately.
  7. Once all executed -> clean up the kitchen and prepare the next order.
    _> closing of the fd and freeing allocated memory.
*/


int	main(int argc, char **argv, char **environment_variables)
{
	int	i;
	int fd[2];
	int temporary_file_descriptor;
	(void)argc;

	i = 0;
	temporary_file_descriptor = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0) //cd
		{
			if (i != 2)
				write_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				write_error("error: cd: cannot change directory to ", argv[1]	);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if ( fork() == 0)
			{
				if (ft_exe(argv, i, temporary_file_descriptor, environment_variables))
					return (1);
			}
			else
			{
				close(temporary_file_descriptor);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				temporary_file_descriptor = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if ( fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exe(argv, i, temporary_file_descriptor, environment_variables))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(temporary_file_descriptor);
				temporary_file_descriptor = fd[0];
			}
		}
	}
	close(temporary_file_descriptor);
	return (0);
}



// int main(int ac,char **av,char **envp)
// {
// 	int i;
// 	int fd[2];
// 	int tmp_fd;
// 	(void)ac;

// 	i = 0;
// 	tmp_fd = dup(STDIN_FILENO);
// 	while(av[i] && av[i + 1])
// 	{
// 		av = &av[i + 1];
// 		i = 0;
// 		while (av[i] && strcmp(av[i], ';') && strcmp(av[i], '|') == 0)
// 			i++;
// 		if (strcmp(av[0], "cd") == 0)
// 		{
// 			if (i != 2)
// 				write_error("error:cd bad arguments", NULL);
// 			else if (chdir(av[1] != 0))
// 				write_error("error: cd: cannot change directory to", av[1]);
// 		}
// 		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ';') == 0))
// 		{
// 			if (fork() == 0)
// 			{
// 				if (ft_exe(av, i, tmp_fd, envp))
// 					return (1);
// 			}
// 			else
// 			{
// 				close(tmp_fd);
// 				while(waitpid(-1, NULL, WUNTRACED) != -1)
// 					;
// 				tmp_fd = dup(STDIN_FILENO);
// 			}
// 		}
// 		else if (i != 0 && strcmp(av[i], "|") == 0)
// 		{
// 			pipe(fd);
// 			if (fork() == 0)
// 			{
// 				dup2(fd[1], STDOUT_FILENO);
// 				close(fd[0]);
// 				close(fd[1]);
// 				if (ft_exe(av, i, tmp_fd, envp));
// 					return (1);
// 			}
// 			else
// 			{
// 				close(fd[1]);
// 				close(tmp_fd);
// 				tmp_fd = fd[0];
// 			}
// 		}
// 	}
// 	close(tmp_fd);
// 	return (0);
// }



