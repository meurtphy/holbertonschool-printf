#include "main.h"

/**
 * _putchar - Écrit un caractère sur la sortie standard
 * @c: Le caractère à afficher
 * Return: 1 en cas de succès, -1 en cas d'erreur
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

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

#include "main.h"

/**
 * print_string - Affiche une chaîne de caractères (%s)
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

#include "main.h"

/**
 * print_percent - Affiche un pourcentage (%%)
 * @args: Liste des arguments (non utilisé)
 * Return: Nombre de caractères imprimés
 */
int print_percent(va_list args)
{
(void)args; /* Argument inutilisé */
return (_putchar('%'));
}

#include "main.h"

/**
 * print_number - Affiche un entier positif ou non signé
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

#include "main.h"

/**
 * handle_specifier - Gère les spécificateurs de format
 * @specifier: Le caractère du spécificateur
 * @args: Liste des arguments
 * @specifiers: Tableau des spécificateurs
 * Return: Nombre de caractères imprimés
 */
int handle_specifier(const char specifier, va_list args,
format_specifier_t specifiers[])
{
int i;

for (i = 0; specifiers[i].specifier != '\0'; i++)
{
if (specifiers[i].specifier == specifier)
return (specifiers[i].func(args));
}


_putchar('%');
_putchar(specifier);
return (2);
}


