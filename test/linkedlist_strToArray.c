#include "../holberton.h"


/**
 * *nbr_spaces - return the number of occurent of a string
 * @s: string to check
 * @c: character to match
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
  *tokenaization - split a sentence into multiple words.
  *@str: the string passed as argument.
  *Return: pointer holding words.
  */
char **tokenaization(char *str)
{
int i = 0;
const char separator[] = " ";
int spaces = nbr_spaces(str);
//for a 4 words sentence, we only need 4 + 1 (for the NULL) memory address to point to all
// the strings we need, not the whole strlen
char **tokens = malloc(sizeof(char *) * (spaces + 1));
char *token;
printf("spaces: %i\n", spaces);

if (!tokens)
{
fprintf(stderr, "sh: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(str, separator);

while( token != NULL )
{
tokens[i] = token;
token = strtok(NULL, separator);
i++;
}
tokens[i] = NULL;

return tokens;
}

int main(int argc, char const *argv[])
{
    
    char str[] = "this is a test";
    char **tokens = tokenaization(str);
    for (int i = 0; tokens[i] != NULL; i++)
    {
        printf("%s\n", tokens[i]);
    }
    free(tokens);  
    return 0;
}

//TODO: Do the same with linked lists