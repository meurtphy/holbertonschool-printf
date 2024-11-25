#include "main.h"

/**
 * print_string - Imprime une chaîne de caractères
 * @args: Liste d'arguments variadiques
 *
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
_putchar(*str);
str++;
count++;
}
return (count);
}

