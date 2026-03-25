Analyse de l'Efficacité Énergétique : Mon Rapport d'Instrumentation
Méthodologie de Mesure
Pour ce projet, j'ai dû mesurer précisément le temps d'exécution de mon code C. Pour y arriver, j'ai utilisé la fonction clock() de la bibliothèque <time.h>. Mon objectif était de capturer uniquement le temps processeur (CPU) pour éviter que les autres logiciels qui tournent sur mon Mac ne faussent mes résultats.

J'ai découpé mon programme en quatre parties pour les chronométrer. J'ai d'abord lancé un compteur global (TOTAL) au tout début du main. Ensuite, j'ai isolé les trois étapes du programme : la création des données (BUILD_DATA), le traitement (PROCESS) et le calcul final (REDUCE). Pour chaque étape, j'ai enregistré le temps de départ et de fin. En divisant la différence par CLOCKS_PER_SEC, j'ai obtenu des résultats très précis en secondes, avec six chiffres après la virgule. Cela m'a permis de voir exactement où mon code était le plus lent.

Différences de Performance Observées
Après avoir compilé et lancé mon programme sur mon MacBook Air, j'ai obtenu les résultats suivants :

TOTAL seconds : 0.001172

BUILD_DATA seconds : 0.000393

PROCESS seconds : 0.000514

REDUCE seconds : 0.000259

En analysant ces chiffres, j'ai remarqué une grosse différence entre les phases. C'est la partie PROCESS qui prend le plus de temps, soit environ 44% du total. C'est logique car cette fonction fait beaucoup de calculs mathématiques (multiplications, divisions, modulos) sur 50 000 éléments. La phase BUILD_DATA arrive ensuite (environ 33%), et enfin REDUCE qui est la plus rapide (22%) car elle ne fait qu'une simple addition de tout le tableau. Mes mesures prouvent que c'est la complexité des calculs qui ralentit le plus le programme.

Relation entre Temps d'Exécution et Consommation d'Énergie
J'ai compris qu'il y a un lien direct entre le temps de calcul et l'électricité consommée par mon processeur. Dans le domaine du "Green Computing", on apprend que plus un processeur travaille longtemps à fond (état C0), plus il vide la batterie et consomme de l'énergie.

Grâce à mes mesures, j'ai identifié que c'est la phase PROCESS qui consomme le plus d'énergie. Si je voulais rendre mon programme plus "écologique", c'est cette partie que je devrais optimiser en priorité. En réduisant le temps de calcul de cette fonction, le processeur pourrait repasser plus vite en mode repos (idle), ce qui réduirait l'empreinte carbone globale du logiciel. Pour moi, optimiser le code, c'est aussi faire un geste pour l'environnement.

Limites de l'Expérience
Même si mes résultats sont clairs, mon expérience a quelques limites :

La précision de clock() : Sur un processeur moderne très rapide, les fonctions s'exécutent parfois en moins d'une milliseconde. La fonction clock() peut donc avoir de petites variations d'un lancement à l'autre.

La mémoire et les sorties : Mon instrumentation mesure le temps CPU, mais elle ne compte pas l'énergie utilisée par la mémoire RAM ou le temps d'affichage du texte à l'écran.

Le matériel utilisé : Les résultats que j'ai obtenus sur mon architecture Apple Silicon seraient probablement différents sur un vieux PC ou sur un serveur de l'école.

Enseignement Pratique pour l'Ingénierie
Ce que je retiens de cet exercice, c'est qu'on ne peut pas améliorer ce qu'on ne mesure pas. Avant de commencer, j'aurais pu penser que le remplissage du tableau était le plus long, mais mes mesures m'ont prouvé le contraire. Maintenant, je sais que si je dois optimiser mon code, je ne dois pas perdre de temps sur la fonction REDUCE. Je dois concentrer mes efforts sur PROCESS. C'est cette méthode de travail, basée sur des preuves réelles, qui permet de créer des logiciels performants et efficaces énergétiquement.