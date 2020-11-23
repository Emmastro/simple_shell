#include "../holberton.h"

/**
  *tokenaization - split a sentence into multiple words.
  *@str: the string passed as argument.
  *Return: pointer holding words.
  */
char **tokenaization(char *str)
{
int i = 0;
const char s[2] = " ";
int len_str = strlen(str);
//for a 4 words sentence, we only need 4 + 1 (for the NULL) memory address to point to all
// the strings we need, not the whole strlen
char **tokens = malloc(sizeof(char *) * (6));
char *token;
printf("%i\n", len_str);

if (!tokens)
{
fprintf(stderr, "sh: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(str, s);

while( token != NULL )
{
tokens[i] = token;
token = strtok(NULL, s);
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