#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string containing the characters and the specifiers
 * Return: Length of the formatted output string
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars;

if (!format)
return (-1);

va_start(args, format);
printed_chars = handle_format(format, args);
va_end(args);

return (printed_chars);
}
