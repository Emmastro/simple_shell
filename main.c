#include <stdio.h>
#include <stdlib.h>

int isExit(char *buffer)
{
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

int main(void)
{

	size_t line, bufsize = 32;
	char *buffer;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	do
	{
		printf("cisfun#: ");
		line = getline(&buffer,&bufsize,stdin);
		printf("%zu characters were read.\n",line);
		printf("You typed: %s", buffer);

	} while (isExit(buffer));

	return(0);
}
