#include "holberton.h"

/**
 * *nbr_spaces - return the number of occurent of a string
 * @s: string to check
 * Return: int
 */

unsigned int nbr_spaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i]  == ' ')
			cmpt++;
	}

	return (cmpt);
}


/**
  *stringToTokens - split a sentence into multiple words.
  *@str: the string passed as argument.
  *Return: tokens
  */
char **stringToTokens(char *str)
{
int i = 0;
const char separator[] = " ";
int spaces = nbr_spaces(str);
char **tokens = malloc(sizeof(char *) * (spaces + 1));
char *token;

if (!tokens)
{
	fprintf(stderr, "sh: allocation error\n");
	exit(1);
}

token = strtok(str, separator);

while (token != NULL)
{
	tokens[i] = token;
	token = strtok(NULL, separator);
	i++;
}
tokens[i] = NULL;

return (tokens);
}
