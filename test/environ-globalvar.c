#include <unistd.h>
#include <stdio.h>

extern char **environ;

/**
 * main - prints the environment using the global variable environ
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}