Analyse pour le stack_example

Schéma de la Pile (Stack Map)
Utilise un tableau pour montrer l'état au moment du depth=3 (le point le plus profond). C'est là que la structure est la plus parlante.
Adresse (Hex),Variable,Frame (Fonction),Valeur
0x16d982e24,marker,walk_stack(0),0
0x16d982dc8,local_int,dump_frame(0),100
0x16d982de4,marker,walk_stack(1),10
0x16d982d88,local_int,dump_frame(1),101
0x16d982da4,marker,walk_stack(2),20
0x16d982d48,local_int,dump_frame(2),102
0x16d982d64,marker,walk_stack(3),30
0x16d982d08,local_int,dump_frame(3),103
Analyse Technique
Croissance de la pile : Les adresses passent de ...e24 à ...d08. On observe une diminution des valeurs, ce qui confirme que la pile grandit vers le bas (adresses mémoires inférieures). 📉

Durée de vie (Lifetime) : Les variables sont automatiques. Elles ne sont valides que tant que leur fonction est active. Par exemple, le marker de depth=0 reste en mémoire tant que tous les appels récursifs ne sont pas terminés.
Critique et Correction de l'IA (Le point crucial du projet)
C'est ici que tu montres ton expertise. Voici l'erreur que tu peux documenter :
Hypothèse erronée de l'IA : L'IA a affirmé que p_local et local_int occupent le même emplacement mémoire car ils partagent la même adresse dans les logs (0x16d982dc8).

Ma correction : C'est une confusion entre l'adresse stockée et l'adresse de stockage. local_int est un entier situé à 0x...dc8. p_local est un pointeur qui possède sa propre adresse sur la pile (qu'on pourrait voir avec &p_local), mais sa valeur est l'adresse de local_int. Ils ne "sont" pas au même endroit, l'un désigne l'autre.

*********************************************************************************************************************************************************************************************

Analyse pour le aliasing_example

Phénomène d'Aliasing
Dans ce programme, nous observons que deux pointeurs, a et b, manipulent le même espace mémoire :

a = make_numbers(n) : Alloue un bloc sur le tas.

b = a : Copie l'adresse de a dans b.

Pointeur,Adresse stockée (Contenu),Cible en mémoire
a,0x555...,Bloc de 5 entiers
b,0x555...,Le même bloc de 5 entiers

Critique et Correction de l'IA
Hypothèse erronée de l'IA : L'IA a affirmé que puisque nous n'avons libéré que a (free(a)), le pointeur b restait valide et que la mémoire devait être libérée une seconde fois via free(b).

Ma correction : C'est une erreur de compréhension de l'aliasing. On ne peut pas libérer deux fois la même zone mémoire. Comme a et b pointent vers le même bloc, l'appel à free(a) détruit l'accès pour les deux. Tenter de lire b[2] ou de libérer b après cela provoque une erreur de type Use-After-Free ou Double Free, car le "coffre-fort" mémoire a déjà été rendu au système.
il aurai fallut faire a = NULL et b = NULL apres le free

*********************************************************************************************************************************************************************************************

Anlyse pour le heap_example

Dans ce code, une structure Person est allouée sur le tas. Cette structure contient elle-même un pointeur (name) qui pointe vers une autre zone du tas. On a donc une allocation imbriquée.
Schéma de la mémoire pour Alice
Au moment du printf, voici l'état du Tas :

Bloc Mémoire,Type,Contenu
0x6000...100,Person (Alice),"{ name: 0x6000...200, age: 30 }"
0x6000...200,char[] (Name),"""Alice\0"""

Critique et Correction
Hypothèse erronée de l'IA : "La fonction person_free_partial(alice) libère toute la mémoire associée à Alice car elle libère le pointeur de la structure." 

Ma correction : C'est faux. La fonction person_free_partial ne fait qu'un free(p). Elle libère le "contenant" (la structure), mais elle oublie de libérer le "contenu" (la chaîne name).
Du coup le bloc 0x600...200 contenant "Alice" reste bloqué sur le Tas. C'est une fuite mémoire.

*********************************************************************************************************************************************************************************************

Analyse pour le crash_example

Ce fichier illustre un Segmentation Fault provoqué par un accès interdit à la mémoire.

Mécanique de l'erreur
Le programme définit n = 0. Lorsqu'il appelle allocate_numbers(0), la fonction retourne NULL. Le programme tente ensuite d'écrire dans ce pointeur vide.

Pointeur,Valeur (Adresse),État de la cible
nums,0x0 (NULL),Inaccessible (Zone système)

Critique et Correction de l'IA
Hypothèse erronée de l'IA : L'IA a affirmé que le programme crashait à cause d'un manque de ressources (mémoire RAM insuffisante).

Ma correction : C'est une erreur d'analyse. Le crash est purement logique. Ce n'est pas que la mémoire est pleine, c'est que le pointeur nums est égal à NULL (adresse 0x0). En C, tenter d'écrire à l'adresse 0x0 déclenche immédiatement une violation de segmentation par le système d'exploitation. Le programme aurait crashé de la même façon avec 128 Go de RAM.