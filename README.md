main.h =
une structure qui associe un spécificateur de format (comme 'c', 's', '%') à la fonction qui gère ce spécificateur.

print_char.c / print_string.c / print_percent.c
Chaque fonction de support prendra un va_list en paramètre pour extraire les arguments nécessaires.

printf.c =
 un tableau de structures pour associer chaque spécificateur à sa fonction correspondante. Parcourez ce tableau pour trouver la fonction appropriée.

print_integer.c =
des spécificateurs supplémentaires (comme %d, %i, %u, %x, etc.), créez des fonctions de support correspondantes et ajoutez-les au tableau specs dans _printf.c.


(void)args;
/* Pour éviter un warning sur les paramètres non utilisés */


