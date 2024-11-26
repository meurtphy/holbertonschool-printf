#include <unistd.h>

/**
 * write_char - Écrit un caractère sur stdout
 * @c: Le caractère à afficher
 * Return: 1 (nombre de caractères écrits)
 */
int write_char(char c)
{
return (write(1, &c, 1));
}

/**
 * write_string - Écrit une chaîne de caractères sur stdout
 * @str: La chaîne à afficher
 * Return: Nombre de caractères affichés
 */
int write_string(char *str)
{
int i = 0;

if (!str)
str = "(null)";

while (str[i])
{
write(1, &str[i], 1);
i++;
}

return (i);
}

