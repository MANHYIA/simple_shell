#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - Take prompt from the user
 *
 * Return: 0.
 */
int main(void)
{
	char *get_line = NULL;
	size_t len = 0;
	ssize_t input;

	while (input != EOF)
	{
		printf("$ ");
		input = getline(&get_line, &len, stdin);
		if (input != -1)
		{
			printf("%s", get_line);
		}
		else
		{
			perror("getline");
		}
	}
	free(get_line);
	return (0);
}
