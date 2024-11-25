#include "main.h"

/**
 * print_char - Imprime un caractère
 * @args: Liste d'arguments variadiques
 *
 * Return: Nombre de caractères imprimés (toujours 1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}



