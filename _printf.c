#include "main.h"

/**
 * _printf - Produit une sortie formatée
 * @format: La chaîne de format
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)

{

format_specifier_t specifiers[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{'\0', NULL}
};

va_list args;
int printed_chars = 0, i;

if (!format)
return (-1);

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
printed_chars += handle_specifier(format[i], args, specifiers);
}
else
{
printed_chars += _putchar(format[i]);
}
}
va_end(args);
return (printed_chars);
}






