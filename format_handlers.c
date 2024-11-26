#include "main.h"

/**
 * handle_format - Handles the format string and prints accordingly
 * @format: The format string
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args)
{
int i, printed_chars = 0;

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
printed_chars += handle_specifier(format[i], args);
}
else
{
write(1, &format[i], 1);
printed_chars++;
}
}

return (printed_chars);
}

/**
 * handle_specifier - Handles a single format specifier
 * @specifier: The format specifier character
 * @args: The list of arguments
 * Return: Number of characters printed for this specifier
 */
int handle_specifier(char specifier, va_list args)
{
if (specifier == 'c')
return (write_char(va_arg(args, int)));
else if (specifier == 's')
return (write_string(va_arg(args, char *)));
else if (specifier == '%')
return (write_char('%'));


return (0);
}




