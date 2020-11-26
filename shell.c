#include "holberton.h"

/**
 * execute - executes the command
 * @cmd: command to run
 * Return: 0 on success1 -1 if cmd is exit and 1 on any other error
 */
int execute(char **cmd)
{

	pid_t child_pid;
	int status;

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);

	return (0);
}


/**
 * main - main simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0, -1 on error.
 */

int main(int argc, char **argv)
{

	int response;
	char **tokens;
	size_t bufsize = BUFSIZ;
	int isPipe = 0;
	char *buffer;

	if (argc >= 2)
	{
		/*TODO: Handle cases where there is no argument, only the command*/
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

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
			_puts("cisfun#: ");
		}

		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = stringToTokens(buffer);
		response = execute(tokens);
	} while (isPipe && response != -1);

	return (0);
}
