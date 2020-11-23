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


char **tokenaization(char *str)
{
int i = 0;
const char *s = " ";
char *txt = "this is a text\n";
int len_str = strlen(str);
//char **tokens = (char **)malloc(sizeof(char *) * (len_str));
char *token;

printf("%i \n", len_str);

/*if (!tokens)
{
fprintf(stderr, "sh: allocation error\n");
exit(EXIT_FAILURE);
}*/
printf("tokens\n");
token = strtok(txt, s);
printf("Printing\n");

return 0; //tokens;
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
		char buffer[_strlen(argv[1])];

		_strcpy(buffer, argv[1]);
		execute(buffer);
		return (1);
	}

	const char separator[] = " ";
	char *token;
	size_t bufsize = BUFSIZ; 
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
			_puts("cisfun#: ");
		}

		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		token = strtok(buffer, separator);
		response = execute(token);
	} while (isPipe && response != -1);

	return (0);
}
