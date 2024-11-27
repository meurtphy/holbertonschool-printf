#include "main.h"

/**
 * print_char - Affiche un caractère (%c)
 * @args: Liste des arguments
 * Return: Nombre de caractères imprimés
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
 * print_string - Affiche une chaîne (%s)
 * @args: Liste des arguments
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

if (!str)
str = "(null)";

while (str[len])
_putchar(str[len++]);

return (len);
}

/**
 * print_percent - Affiche un pourcentage (%%)
 * @args: Liste des arguments
 * Return: Nombre de caractères imprimés
 */
int print_percent(va_list args)
{
(void)args;
return (_putchar('%'));
}
