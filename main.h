#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
/**
 * struct format_specifier - Structure pour gérer les spécificateurs
 * @specifier: Le caractère du spécificateur
 * @func: Pointeur vers la fonction associée
 */
typedef struct format_specifier
{
char specifier;
int (*func)(va_list);
}
format_specifier_t;
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_number(unsigned int num);
int handle_specifier(const char specifier, va_list args,
format_specifier_t specifiers[]);
#endif
