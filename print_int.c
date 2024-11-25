#include "main.h"
#include <stdio.h> /* Inclure stdio.h pour snprintf */

/**
 * print_int - Imprime un entier
 * @args: Liste d'arguments variadiques
 *
 * Return: Nombre de caractères imprimés
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
int count = 0;
char buffer[12];
int i;

if (num < 0)
{
_putchar('-');
count++;
num = -num;
}

snprintf(buffer, sizeof(buffer), "%d", num);
for (i = 0; buffer[i] != '\0'; i++)
{
_putchar(buffer[i]);
count++;
}
return (count);
}

