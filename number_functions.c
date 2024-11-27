#include "main.h"

/**
 * print_number - Affiche un entier non signé
 * @num: Le nombre à afficher
 * Return: Nombre de caractères imprimés
 */
int print_number(unsigned int num)
{
int count = 0;

if (num / 10)
count += print_number(num / 10);

count += _putchar((num % 10) + '0');
return (count);
}

/**
 * print_int - Affiche un entier signé (%d, %i)
 * @args: Liste des arguments
 * Return: Nombre de caractères imprimés
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
int count = 0;

if (num < 0)
{
count += _putchar('-');
num = -num;
}

count += print_number((unsigned int)num);
return (count);
}
