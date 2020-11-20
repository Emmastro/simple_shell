#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int isExit(char *buffer)
{
	//Make the last \n a \0 to check if it's exit
	char *exit = "exit";
	for (int i = 0; i < 4; i++)
	{
		if (exit[i] != buffer[i])
		{
			return (1);
		}
	}
	return (0);	
}


/**
 * execute - executes the command
 * @forked: number of child processes
 * Return: Always 0, -1 on error.
 */
int execute(char *cmd)
{

	pid_t child_pid;
	//parameters
	char *argv[] = {"", NULL};
	//Storing the command and adding the full path to bin will allow the user to 
	//only type the command, without having to type the full path
	//char command[100]; //TODO: 100 should be the maximum number of character we allow
	child_pid = fork();
	int status;

	//strcpy(bin, "/bin/");

	if (child_pid == -1)
	{
		perror("Error::");
		return (1);
	}
	else if (child_pid == 0)
	{
		//strcat(bin, cmd);
		if (execve(cmd, argv, NULL) == -1)
			perror("Error:");
	}
	else
	{
		wait(&status);
	}

	//my_pid = getpid();

	return (0);
}

int main(int argc, char const *argv[])
{

	char *buffer;
	if (argc == 2)
	{
		//If we have arguments, execute them without prompting the shell input
		char buffer[strlen(argv[1])];
		strcpy(buffer, argv[1]);
		execute(buffer);
		return (1);
	}


	const char separator[] = " ";
	char *token;
	size_t bufsize = 32;
	//size_t line;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	do
	{
		printf("cisfun#: ");
		//getline: get return value of getline to handle errors) return type: size_t
		getline(&buffer,&bufsize,stdin);
		token = strtok(buffer, separator);
		/**Change the end of line character (\n) to a null character as execve expects
		 * null termitated strings
		*/

		buffer[strlen(buffer) - 1] = '\0';
		execute(token);

		//printf("The command is: %s, %lu", token, strlen(token));

	} while (isExit(buffer));

	return(0);
}
