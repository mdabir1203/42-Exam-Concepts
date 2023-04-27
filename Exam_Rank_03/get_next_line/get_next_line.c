#include "get_next_line.h"

/*
 * To read a book with long sentences, I came up with a way to remember each sentence one at a time. I use a special notebook
 with pages(buffer with malloc) that can only hold a certain number of words.
 I start by writing the first page of the book in the notebook.
 Then I read the words in the notebook one at a time and keep track of where I am.
 When I reach the end of a sentence (marked by a period), I write down how many words were in the sentence.
 I then create a new space in my memory with exactly enough room to remember that sentence.
 I copy the words from the notebook into my memory and then erase those words(free(buffer)) from the notebook.
 I keep doing this until I finish the book. This way, I can read the book a little bit at a time and remember each sentence as I go.
 It's like taking small bites of a big sandwich so that you can enjoy it all without getting too full at once.
 */






#include "get_next_line.h"

int	ft_strchr(char *str)
{
	while (str && *str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	i = 0, j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}




char	*get_reminder(char *tmp)
{
	char *rem;
	int i = 0, j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	rem = malloc(ft_strlen(tmp) - i);
	if (!rem)
		return (NULL);
	i++;
	while (tmp[i + j])
	{
		rem[j] = tmp[i + j];
		j++;
	}
	rem[j] = '\0';
	free(tmp);
	return (rem);
}

char	*get_new_line(char *tmp)
{
	char *line;
	int	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i += 1;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	char *buff;
	int	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(tmp) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > UINT_MAX)
		return (NULL);
	tmp = read_file(fd, tmp);
	if (!tmp)
		return (NULL);
	if (!(*tmp))
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = get_new_line(tmp);
	tmp = get_reminder(tmp);
	return (line);
}

//
//#include<stdio.h>
//#include <fcntl.h>
//
//int main(int ac, char **av) {
//	int fd;
//	char *line;
//
//	if (ac != 2) {
//		printf("Argument check: %s\n", av[0]);
//		return (1);
//	}
//	fd = open(av[1], O_RDONLY);
//	if (fd == -1)
//	{
//		perror("didn't open");
//		return (1);
//	}
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//
//
//}