#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>


int _printf(const char *format, ...);
int _putchar(char c);
int handle_specifier(char specifier, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_pointer(va_list args);

#endif
