#include "main.h"

/**
 * _printf - Fonction principale pour formater et imprimer une chaîne
 * @format: La chaîne de format
 *
 * Return: Nombre total de caractères imprimés
 */
int _printf(const char *format, ...)
{
int printed = 0, i = 0;
va_list args;

if (format == NULL)
return (-1);

va_start(args, format);

while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
return (-1);
printed += handle_specifier(format[i], args);
}
else
{
_putchar(format[i]);
printed++;
}
i++;
}

va_end(args);
return (printed);
}

