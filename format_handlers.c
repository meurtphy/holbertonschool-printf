#include "main.h"
#include <unistd.h>

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
else if (specifier == 'd' || specifier == 'i')
return (write_number(va_arg(args, int)));
else
{
write(1, "%", 1);
write(1, &specifier, 1);
return (2);
}
}

/**
 * handle_format - Handles the format string and prints accordingly
 * @format: The format string
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args)
{
int i, printed_chars = 0;

if (!format)
return (-1);

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
 * write_number - Écrit un entier sur stdout
 * @num: L'entier à afficher
 * Return: Nombre de caractères affichés
 */
int write_number(int num)
{
char buffer[12];
int i = 0, count = 0;
unsigned int n;

if (num < 0)
{
write(1, "-", 1);
count++;
n = -num;
}
else
n = num;


do
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
while (n > 0);


while (--i >= 0)
{
write(1, &buffer[i], 1);
count++;
}

return (count);
}

