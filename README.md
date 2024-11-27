Fonction principales de format_handlers.c

1.handle_specifier

C est la fonction qui gère les types de données apres uun % et decide comment  les affihcer.

pour mieu vous expliquer cela je vais vous donner une ligne d exemple asser simple pour le commun des mortels :

%c -> affiche un caractere (char)
%s -> affiche un texte (string)
%d ou %i -> affiche un nombre entier (int)
%% -> affiche le caractère %

vous avez tout compris ?  si oui on peut continuer.

(point bonus++)

si le specifier est inconu ma fonction affichera % suivi du caractère inconnu.

par exemple:

appelé avec %c et 'A', elle affichera A.

/////////////////////////////////////
Voici encore une autre fonction importante le handle_format

C est la fonction principale du code (j aurai du commencer par elle :)

Pour vous l expliquer d une facon asser simple elle sert a parcourir un texte fournis elle repere tout les % et utilise la fonction handle_specifier que je vous est decrite precedament pour les traiter.
Les caractère normaux sans les % sont afficher directement par exemple:

si vous ou moi tapper une chaine de caractere avec les arguments comme par exemple "Hello %s, age: %d avec des arguments comme par exemple "Patrick" pour le %s et "60" pour le %d elle affichera:

Hello bébé Patrick, age: 60

///////////////////////////
Vous me suivez encore ?

La fonction suivante c est write_number

Pour commencer on va faire la chose la plus simple afficher - si le chiffre est negatif

simple efficace nan on va un peu corcer la suite c est en sois asser simple a comprendre je vais vous l expliquer d une facon asser simple car je voudrais pas vous perdre :)

alors je vous est deja expliquer pour le nombres negatif c etais simple maintenant je vais vous expliquer la suite:

Alors elle divise le nombre par 10 pour extraire chaque chiffre, qu'elle stocke dans un tableau temporaire (buffer)

Pourquoi on divise les nombre par 10 ?

Car quand on divise un nombre par 10 on obtient:
Le reste avec % et le dernier chiffre
le quotient avec / le nombre sans le dernier chiffre.

Par exemple 1234 % 10 :
le dernier chiffre = 4
ensuite 1234/1à = 123 les chiffre restants
ainsi de suite...
jusqua 1 % 10 = 1, puis 1/10 = 0

Le probleme que vous avez remarquer c est que c est dans le mauvais par rapport au chiffre 4, 3, 2, 1, puis 0 mais Le 0 est pris en compte correctement grâce à la boucle do...while, qui garantit qu’un chiffre est toujours traité


c est donc cette partie de code qui remet le resultat dans le sens attendu
do {
    buffer[i++] = (n % 10) + '0'; // Extrait le dernier chiffre, convertit en caractère, et le met dans buffer
    n /= 10; // Réduit le nombre pour passer au prochain chiffre
} while (n > 0);


Chaque chiffre extrait est converti en caractère (+ '0') avant d’être mis dans buffer.
Par exemple, pour 1234, le tableau contiendra : ['4', '3', '2', '1'].


Étape 2 : Afficher les chiffres dans le bon ordre

while (--i >= 0) { // Parcourt le tableau de la fin au début
    write(1, &buffer[i], 1); // Affiche chaque chiffre
}

Cela affiche les chiffres dans l’ordre correct : 1, 2, 3, 4.

La grande question de la plupart des apotre est sur le fais de la necissiter du tableau temporaire (buffer)

Le tableau temporaire (buffer) est nécessaire car les chiffres sont extraits dans l’ordre inverse, mais doivent être affichés dans le bon ordre. C’est un simple espace de stockage pour tout organiser avant d’afficher.


/////////////////////////////////
////////////////////////////////
Bon on va faire une petite pause mais le plus long et le plus dur a comprendre pour certain est passé mais c etais un passage desagrable mais obligatoire pour vous detailler le code d une facon asser simple et detailler !!!

/////////////////////////////////
////////////////////////////////

maintenant je vais passer au main.h c est simpe efficace il contient toute les fonction a appeller
et il y a aussi le _putchar.c c est negligeable si vous ne savez pas pourquoi je les cree et utiliser bonne chance que le sort puisse vous etre favorable <3

/////////////////////////////////
////////////////////////////////

et pour finir le bouquet final nous avonz le printf.c
           * * * *  * * *
           !!!!!!!!!!!!!!


Cette fonction est une version simplifiée de printf en C. Elle permet d'afficher du texte formaté sur la sortie standard (stdout), en interprétant des spécificateurs comme %d, %s, %c, etc

if (!format)
    return (-1);
Si la chaîne format est nulle (vide ou invalide), la fonction retourne -1 pour signaler une erreur.


va_list args;
va_start(args, format);
va_list args : Une structure spéciale pour manipuler des arguments variables (comme ceux après "Hello %s, age: %d").
va_start : Initialise la liste args pour pouvoir récupérer les arguments supplémentaires passés à _printf.

printed_chars = handle_format(format, args);
handle_format : Une autre fonction (probablement dans le fichier handler.c) qui s’occupe de :
Parcourir la chaîne format.
Repérer les % pour détecter les spécificateurs (%d, %s, etc.).
Utiliser args pour récupérer les valeurs associées (par exemple, "Patrick" pour %s ou 60 pour %d).
Afficher le texte formaté.
printed_chars : Contient le nombre total de caractères affichés.


va_end(args);
Libère les ressources utilisées par args. C’est une bonne pratique pour éviter les fuites de mémoire.
                        bisous :)

return (printed_chars);
La fonction retourne le nombre total de caractères affichés.
Exemple : Si _printf affiche "Hello John", il retourne 10 (car il y a 10 caractères).


int len = _printf("Name: %s, Age: %d\n", "Patrick", 60);
Fonctionnement :
format contient : "Name: %s, Age: %d\n".
Les arguments variables sont :
%s → "Patrick".
%d → 60.
handle_format :
Parcourt la chaîne et remplace %s par "Patrick".
Remplace %d par 60.
Affiche : "Name: Patrick, Age: 60\n".
La fonction retourne 23 (nombre total de caractères affichés).


Voila jespere vous avez passer un bon moment et que vous ayer compris ou en partie mon explication global optimal superman de la creation de mon propre printf


            au plaisir de nous revoir ♡


                         meurtphy








                         et dimdim ♡