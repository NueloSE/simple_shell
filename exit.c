#include "main.h"

void myExit(const char *input)
{
    char *built_in = "exit";
    char *newline = "\n";

    if (strcmp(input, built_in) == 0)
    {
        write(1, input, strlen(input));
        write(1, newline, 1);
        exit(EXIT_FAILURE);
    }
}
