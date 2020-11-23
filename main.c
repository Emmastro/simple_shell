#include "holberton.h"

/**
 * execute - executes the command
 * @cmd: command to run
 * Return: 0 on success1 -1 if cmd is exit and 1 on any other error
 */
int execute(char *cmd)
{

	pid_t child_pid;

	if (strncmp("exit", cmd, 4) == 0)
		return (-1);

	child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		char *argv[] = {"", NULL};

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
			exit(-1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}

/**
 * main - main simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0, -1 on error.
 */

int main(int argc, char const *argv[])
{

	char *buffer;
	int response;

	if (argc == 2)
	{
		char buffer[strlen(argv[1])];

		strcpy(buffer, argv[1]);
		execute(buffer);
		return (1);
	}

	const char separator[] = " ";
	char *token;
	/*What should be the max bufsize?*/
	size_t bufsize = 32;
	int isPipe = 0;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	do {
		if (isatty(fileno(stdin)))
		{
			isPipe = 1;
			printf("cisfun#: ");
		}

		getline(&buffer, &bufsize, stdin);
		token = strtok(buffer, separator);
		buffer[strlen(buffer) - 1] = '\0';
		response = execute(token);
	} while (isPipe && response != -1);

	return (0);
}
