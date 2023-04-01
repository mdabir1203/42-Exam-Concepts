#include "get_next_line.h"

/**
 * Saved memory and unnecessary copying by -> line 14
 * Read character one at a time
 * Prevents reading more than the buffer can hold
 * More robust and safe as it checks for allocation,read error
 */

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


char *get_next_line(int fd)
{
	int i = 0;
	int reading = 0;
	char character;
	char *buffer = malloc(BUFFER_SIZE + 1);

	if (BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	while ((reading = read(fd, &character, 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n' || i == BUFFER_SIZE)
			break;
	}
	if (reading == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
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