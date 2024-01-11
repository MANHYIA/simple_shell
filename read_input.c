#include "shell.h"

/**
 * read_line - Read a line from stdin
 *
 * Return: Pointer that points to a string with the line content
 */
char *read_line(void)
{
	char *word = NULL;  /* Pointer to store the input line */
	size_t bufsize = 0; /* Initial size for getline to allocate memory */

	/* Read a line from stdin using getline */
	if (getline(&word, &bufsize, stdin) == -1) { /* If getline fails */
		if (feof(stdin)) { /* Test for the EOF */
			free(word); /* Avoid memory leaks when ctrl + d */
			exit(EXIT_SUCCESS); /* We received an EOF */
		} else {
			free(word); /* Avoid memory leaks when getline fails */
			perror("Error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}

	return (word); /* Return the pointer to the input line */
}
