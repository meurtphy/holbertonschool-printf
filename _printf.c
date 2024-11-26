#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints formatted output like printf
 * @format: Format string containing the specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
int i = 0, printed = 0;
va_list args;

if (!format)
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

/**
 * handle_specifier - Handles format specifiers
 * @specifier: The format specifier
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
if (specifier == 'c')
return (print_char(args));
if (specifier == 's')
return (print_string(args));
if (specifier == '%')
return (_putchar('%'));

return (_putchar('%') + _putchar(specifier));
}

