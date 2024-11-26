#include "main.h"

/**
 * write_char - Writes a character to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int write_char(char c)
{
return (write(1, &c, 1));
}

/**
 * write_string - Writes a string to stdout
 * @str: The string to print
 * Return: Number of characters printed
 */
int write_string(char *str)
{
int i = 0;

if (!str)
str = "(nil)";

while (str[i])
{
write(1, &str[i], 1);
i++;
}

return (i);
}

