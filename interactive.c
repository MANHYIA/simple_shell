#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *word;
	char **args;
	int status = -1;

	do {
		printf("$ "); 
		word = read_line(); 
		args = split_line(word);
		status = execute_args(args);
		/* Avoid memory leaks */
		free(word);
		free(args);
		/* Exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
