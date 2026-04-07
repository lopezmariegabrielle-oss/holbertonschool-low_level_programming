Analyse de aliasing_example

Description du crash
Outil : AddressSanitizer

Type d'erreur : heap-use-after-free

Action : READ of size 4 à la ligne 42.

Analyse de la cause profonde
Le déclencheur : Le programme crée un alias : deux pointeurs, a et b, pointent vers la même adresse mémoire sur le Tas (Heap). 🏗️

La rupture : On appelle free(a), ce qui informe le système que la mémoire à cette adresse est désormais disponible. Cependant, le pointeur b n'est pas mis à jour.

L'accès invalide : À la ligne 42, le programme tente de lire b[2]. Comme b est un dangling pointer (pointeur suspendu), il essaie d'accéder à une zone mémoire qui a déjà été officiellement libérée.

Pourquoi l'accès est-il invalide ?
En C, free libère le bloc sur le Tas mais ne "nettoie" pas les variables sur la Pile. Le pointeur b contient toujours l'ancienne adresse. Tenter de lire cette adresse après le free est un comportement indéfini car cette zone mémoire peut déjà avoir été réattribuée à une autre partie du programme par le système.

Critique de l'IA
L'erreur de l'IA : Prétendre que b devient NULL automatiquement.

Correction : C'est faux. Le pointeur conserve sa valeur (l'adresse). Le crash ne vient pas d'une adresse nulle, mais d'une violation de la durée de vie (lifetime) de la mémoire.

*********************************************************************************************************************************************************************************************

Analyse de heap_example

Rapport d'erreur
Outil : leaks (ou AddressSanitizer avec l'option LeakSanitizer). 🛠️

Type d'erreur : memory leak.

Action : Allocation via malloc à la ligne 15 (pour le champ name) jamais libérée.

Analyse de la cause profonde
Le déclencheur : Le programme alloue une structure Person sur le Tas, puis alloue séparément une chaîne de caractères pour le nom (p->name).

La rupture : On appelle une fonction de libération incomplète (par exemple person_free_partial). Cette fonction libère le "contenant" (la structure Person) mais oublie le "contenu" (le nom).

L'accès perdu : Une fois que free(p) est exécuté, l'adresse de p->name est perdue à jamais. Le bloc de mémoire du nom reste marqué comme "occupé" sur le tas, mais plus aucun pointeur dans le programme ne connaît son adresse pour le libérer.

Pourquoi est-ce un comportement indéfini ?
Techniquement, une fuite n'est pas un "comportement indéfini" qui fait planter le programme tout de suite, mais c'est une faille de gestion des ressources. Si cette fonction est appelée des milliers de fois (par exemple dans une boucle), le programme va consommer toute la RAM disponible jusqu'à ce que le système d'exploitation finisse par tuer le processus (Out Of Memory).

Critique de l'IA
L'erreur de l'IA : "Libérer la structure parente libère automatiquement tout ce qui est à l'intérieur."

Correction : En C, le free n'est absolument pas récursif. Il ne libère que le bloc dont on lui donne l'adresse. Si ce bloc contient d'autres adresses vers le tas, c'est au programmeur de les libérer avant.

*********************************************************************************************************************************************************************************************

Analyse de stack_example

Rapport d'erreur 
Outil : AddressSanitizer

Type d'erreur : stack-buffer-overflow

Action : WRITE of size 4 (ou READ) en dehors des limites d'un tableau local.

Analyse de la cause profonde
Le déclencheur : Le programme déclare un tableau fixe sur la pile (par exemple int tab[5]).

La rupture : Le code utilise un index trop grand (comme tab[10]) pour écrire ou lire une valeur.

L'accès invalide : En dépassant la taille du tableau, le programme "déborde" sur les cases voisines de la pile. Ces cases contiennent des informations vitales : d'autres variables, ou pire, l'adresse de retour qui permet à la fonction de savoir où elle doit revenir quand elle a fini.

Pourquoi l'accès est-il invalide ? 
La pile est organisée de manière très stricte. En écrivant en dehors du tableau, on corrompt les données des autres fonctions. L'AddressSanitizer détecte cela grâce à des "redzones" (zones de garde) qu'il place autour de ton tableau. Si tu touches à une zone rouge, le programme s'arrête net pour éviter que le comportement devienne totalement imprévisible.

Critique de l'IA
L'erreur de l'IA : "Ce n'est pas grave car la pile est nettoyée automatiquement à la fin de la fonction."

Correction : C'est une analyse très dangereuse. Un débordement de pile est une faille de sécurité majeure (exploit). Si un utilisateur malveillant peut contrôler ce qui est écrit dans le débordement, il peut détourner le programme pour lui faire exécuter n'importe quel code.

********************************************************************************************************************************************************************************************

Analyse de crash_example

Description du crash 
Outil : AddressSanitizer

Type d'erreur : SEGV (Segmentation Fault) / NULL dereference.

Action : WRITE memory access à l'adresse 0x000000000000 à la ligne 32.

Analyse de la cause profonde
Le déclencheur : Le programme appelle une fonction d'allocation allocate_numbers(n). Si cette fonction échoue ou si n est égal à 0, elle renvoie la valeur 0x0 (NULL).

La propagation : La variable nums reçoit cette adresse nulle. Le programme continue de s'exécuter sans vérifier si l'allocation a réussi.

L'accès invalide : À la ligne 32, le code tente d'écrire une valeur dans nums[0]. Comme nums vaut 0x0, il essaie d'accéder à la "Page Zéro" de la mémoire.

Pourquoi l'accès est-il invalide ?
L'adresse 0 est une zone protégée par le système d'exploitation. Elle est réservée justement pour que tout accès accidentel déclenche un crash immédiat. C'est un mécanisme de sécurité pour éviter que le programme ne corrompe des données vitales. Ce n'est pas un manque de place, c'est une erreur de destination.

Critique de l'IA
L'erreur de l'IA : "Le programme plante car la mémoire vive (RAM) de l'ordinateur est saturée."

Correction : C'est faux. Si la mémoire était saturée, malloc échouerait, mais le crash n'arriverait qu'au moment où l'on essaie d'utiliser ce résultat nul. Le crash est dû au déréférencement d'un pointeur nul, pas à la saturation de la RAM elle-même.

