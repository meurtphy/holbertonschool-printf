#include <unistd.h>

/**
 * _putchar - Écrit un caractère sur la sortie standard
 * @c: Le caractère à écrire
 *
 * Return: 1 en cas de succès, -1 en cas d'échec
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

