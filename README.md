# Vous trouverez ici mon TP de Synthèse ENSEASH

Mon binome de TP est Sammy GROS, j'ai pu atteindre et terminer l'étape d'implémentation de la redirection vers stdin et stdout.

## Organisation de mes fichiers :

  J'ai décidé de ne pas organiser mes fichiers sous la forme de "questionX.c" car le fait de diviser les fonctions me permet de plus facilement venir sur mon code et de l'amender afin de répondre à la question suivante, cela en facilite aussi la révision et la compréhension par un tiers.

## Méthode de travail :

  J'ai pu réaliser ce TP en m'appuyant non seulement sur le cours de M. PAPAZOGLOU sur la pogrammation système mais aussi en faisant recours à la base de connaissance des différents clients d'intelligenc artificielle.
Cette combinaison m'a permis de mieux approfondir les différentes fonctions abordées dans le cours, de m'apporter quelques éléments clés à la réalisation de certaines fonctions, notamment la fonction strcmp() ou les token mais aussi la nécéssité de définir un struct XXXX pour le bon fonctionnement du get_timeXX.
Cependant cela n'est pas sans faille, les IA génératives sont capables grace à leurs bases de connaissances de fournir des fonctions intéréssantes et d'en expliquer extensivement le fonctionnement, cela n'en assure pas nécéssairement le bon fonctionnement et nécéssite parfois un plongeon dans bibliotheques en question afin de correctement utiliser la fonction. De plus les exemples d'implémentation proposés présentent parfois une structure non optimale.

## Difficultés rencontrées :

  Ma plus grande difficulté a été l'implémentation du retour du temps d'exécution de ma commande, spoiler alert -> l'erreur se situait dans le fait que mon getTimeStart se trouvait dans le processus fils et le getTimeEnd se situait dans le processus père, il aurait donc du utiliser un pipe pour que cela fonctionne, mais c'est une solution bien trop complexe pour le problème réel. Il m'a suffit d'appeler le getTimeStart juste avant le fork et le getTimeEnd dans le processus pere suite au waitpid, il m'a fallu une heure de réécriture de mon fichier getTime.c pour comprendre que l'erreur se situait dans le fichier Prompt.c. J'ai aussi du implémenter la possibilité d'appeler des fonctions complexes, notamment le sleep X, afin de valider le bon fonctionnement de mon retour de temps d'exécution.

## Ce que j'en ai retenu / appris : 

  Au cours de ce tp j'ai pu apprendre de nouvelles fonctions indispensables, je fais référence au token ert au execvp en particulier, mais d'autres fonctions telles que le strcmp, et le strok, leur fonctionnement et la manière dont il fallait les implémenter. J'ai aussi pu progresser dans la structuration du code et la séparation des fonctions, notamment en appliquant les méthodes de structuration utilisées lors du projet java, soit correctement scinder les différentes fonctions afin d'en faciliter la relecture, dans ce cas peu complexe on pourrait éventuellement répondre dans des fichiers "QX.c" mais le code deviendrait tout de meme cahotique assez rapidement, mais ca permet tout de meme de valider assez facilement le bon fonctionnement des différentes fonctionnalités implémentées au fur et à mesure. J'ai aussi pu faire l'expérience de l'importance de la structure lorsque l'on travaille avec des fork, il faut bien comprendre la différenciation des processus.
