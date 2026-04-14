#include <stdio.h>

int main(void)
{
    
    int wololo;
    int compteur = 0;
    
    printf("Hello world,\n");


    //Utilisé quand on sait exactement le nombre de fois que l'on execute une instruction
    for(wololo = 0 ; wololo <= 5; wololo++)
    {
        printf("yaaaaa");
    }

    //Quand le nombre d'execution dépend d'une condition
    while(compteur <= 5)
    {
        printf("hello");
        compteur = compteur + 1;
    }


return (0);
}

