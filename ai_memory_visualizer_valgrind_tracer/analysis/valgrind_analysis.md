Analyse de aliasing_example

Rapport d'erreur (Outil : AddressSanitizer/Valgrind)
Type d'erreur : heap-use-after-free 

Action : READ of size 4 à la ligne 42.

Description du problème mémoire
Objet impliqué : Un bloc de 20 octets (5 entiers) alloué sur le Tas (Heap).

Mécanique du bug :
Le bloc est alloué et son adresse est stockée dans a.
b devient un alias de a (il copie l'adresse).
free(a) libère le bloc mémoire à cette adresse (ligne 38).
Le programme tente de lire b[2] (ligne 42). Comme b pointe toujours vers l'adresse libérée, le système détecte un accès illégal à une zone qui ne lui appartient plus.

Critique et Correction de l'IA
Hypothèse erronée de l'IA : "Le programme crash parce que le pointeur b est devenu NULL automatiquement après le free(a). On ne peut pas lire l'adresse 0."

Ma correction : Cette analyse est fausse. Le log de l'outil montre explicitement :

after free(a): b=0x603000001c60 (dangling)

Le pointeur b contient toujours l'adresse d'origine (0x6030...). En C, le free libère l'espace sur le Tas, mais il ne modifie pas la valeur des variables sur la Pile. b devient un dangling pointer (pointeur suspendu) : il possède toujours l'adresse, mais il n'a plus le "droit" d'y accéder. Le crash n'est pas dû à une adresse nulle, mais à une violation de la durée de vie (lifetime) de la mémoire.

*********************************************************************************************************************************************************************************************

Analyse de heap_example

Rapport d'erreur (Outil : leaks / AddressSanitizer)
Type d'erreur : memory leak (fuite mémoire)

Action : Mémoire allouée via malloc à la ligne 15 mais jamais libérée.

Description du problème mémoire
Objet impliqué : Une chaîne de caractères (le nom "Alice") allouée dynamiquement sur le Tas.

Mécanique du bug : 
1. La structure Person est allouée et contient un pointeur vers le nom.
2. On appelle person_free_partial(alice).
3. Cette fonction libère la structure Person (free(p)), mais ne libère pas le pointeur p->name avant.
4. Résultat : La structure est supprimée, et avec elle, la seule copie de l'adresse du nom. Le bloc mémoire du nom reste "occupé" sur le tas sans qu'on puisse jamais le libérer.

Critique et Correction de l'IA
Hypothèse erronée de l'IA : "La fonction person_free_partial(alice) libère toute la mémoire associée à Alice car elle libère le pointeur de la structure mère."

Ma correction : C'est faux. En C, le free n'est pas "récursif" ou "intelligent". Si une structure contient des pointeurs vers d'autres zones du Tas, il faut libérer chaque zone manuellement, du plus profond vers le plus superficiel. Ici, il aurait fallu faire free(p->name) avant free(p). En libérant la structure d'abord, on commet une fuite car on perd définitivement l'adresse du nom.

*********************************************************************************************************************************************************************************************

Analyse de crash_example

Rapport d'erreur (Outil : AddressSanitizer)
Type d'erreur : SEGV (Segmentation Fault) / NULL dereference

Action : WRITE memory access à l'adresse 0x000000000000 à la ligne 32.

Description du problème mémoire
Objet impliqué : Un pointeur non initialisé ou explicitement mis à NULL.

Mécanique du bug : 
1. Le programme demande une allocation de n=0 octets ou manipule un pointeur qui finit par valoir 0x0.
2. À la ligne 32, le code tente d'écrire une valeur (probablement un entier) à l'endroit pointé.
3. Comme l'adresse 0 appartient à la "page zéro" (une zone protégée du système), le processeur envoie un signal de violation de segmentation (SIGSEGV) et tue le processus immédiatement pour protéger le reste du système.

Critique et Correction de l'IA
Hypothèse erronée de l'IA : "Le programme crash parce que la mémoire de l'ordinateur est saturée (pleine). Il n'y a plus de place pour stocker la variable, donc le système s'arrête."

Ma correction : C'est techniquement absurde. Une saturation de mémoire (OOM - Out Of Memory) provoquerait un échec de malloc, mais pas un crash direct à l'écriture. Ici, le crash est dû à une adresse invalide (0x0). Ce n'est pas un problème de quantité de mémoire, mais une erreur de destination. Le pointeur est "vide" (NULL), et tenter d'écrire dedans revient à essayer d'envoyer une lettre à une maison qui n'a pas d'adresse : c'est impossible pour le facteur (le processeur).

*********************************************************************************************************************************************************************************************

Analyse de stack_example

Rapport d'erreur (Outil : AddressSanitizer)
Type d'erreur : stack-buffer-overflow 

Action : WRITE of size 4 (ou READ) en dehors des limites d'un tableau local.

Description du problème mémoire
Objet impliqué : Un tableau (ex: int tab[5]) alloué sur la Pile.

Mécanique du bug : 
1. Le programme tente d'accéder à tab[10].
2. Contrairement au Tas, où l'on risque de corrompre d'autres données allouées, ici on risque de corrompre l'adresse de retour de la fonction ou d'autres variables locales voisines.
3. ASan place des "zones rouges" (redzones) autour des variables de la pile pour détecter immédiatement si le code "déborde".

Critique et Correction de l'IA
Hypothèse erronée de l'IA : "L'erreur sur la pile n'est pas grave car la mémoire est libérée automatiquement à la fin de la fonction, donc le bug disparaît tout seul."

Ma correction : C'est extrêmement dangereux. Un débordement sur la pile peut permettre à un attaquant de modifier le comportement du programme (en changeant l'adresse de retour). Ce n'est pas parce que la mémoire est "automatique" qu'elle est protégée contre les écritures hors limites.

