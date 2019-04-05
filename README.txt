//////////DESCRIPTION : //////////

Dans le dossier il y a tous les fichiers nécessaires à l'éxécution de la simulation.

Les codes sources lapin.c et mt19937ar.c en language C.
Les fichiers objets lapin.o et mt19937ar.o
Le fichier header matsumoto.h
Le fichier éxécutif exe1 de la simulation


Pour la compilation j'ai effectué les commandes suivantes : 

gcc -c lapin.c
gcc -c mt19937ar.c
gcc lapin.o mt19937ar.o -o exeSimu


Guide de Style : 

NASA : 

- Indentation.
- Readability, blank lines, spacing.
- Statement paragraphing, inline comment, boxed comment prelog, block comment, short comment.
- Capitalisation.
- Return statement.
- Variables, Constants, Structures, Automatic variables, Pointer Conversions, Operator formatting.
- Statements and control flow.
- README_File.


//////////PROGRAMME : //////////


Fonctions :

Lapin : structure lapin composé des variables définissant les lapins.

NombreMois() : transforme le nombre d'année de simulation en nombre de mois.

Maturite() : génère un age de maturite aléatoire pour chaque lapin.

NbMiseBas() : génère un nombre aléatoire de mise à bas pour l'année pour une femelle.

Portee() : génère un nombre aléatoire de bébés lors d'une mise à bas.

CreerLapin() : crée un nouveau lapin et initialise ses variables.

Sexe() : détermine le sexe du lapin en âge de maturité.

Naissance() : crée les nouveaux lapins en cas de mise à bas d'une femelle.

Tuer() : change le sexe du lapin a 'd' en cas de mort. 

Mort() : fait mourir les lapins ou non.


Main : 

---------------------------------PREMIERE PARTIE------------------------------------

Initialisation de la fonction de Matsumoto

Définition de toutes les variables et allocation pour le tableau de structures de lapin.

Demande à l'utilisateur du nombre d'années de la simulation, du nombre de lapins ainsi que du nombre de femelles qu'il veut au début de la simulation.

Transformation du nombre d'années en nombre de mois grace à la fonction NombreMois().

Première boucle 'for' dans laquelle on crée les lapins demandés au début avec la fonction CreerLapin(). 
Incrémentation du numéro de lapin et du nombre de lapins en vies

Deuxième boucle 'for' dans laquelle on définit pour le nombre de femelles demandé à l'utilisateur leur sexe sur 'f'.

Troisième boucle 'for' dans laquelle on définit pour le reste des lapins demandés à l'utilisateur leur sexe sur 'm'.

--------------------------------FIN PREMIERE PARTIE----------------------------------

----------------------------------DEUXIEME PARTIE------------------------------------

Première boucle 'for' dans laquelle on boucle sur le nombre de mois.
{

Deuxième boucle 'for' dans laquelle on boucle sur le nombre de lapins
{

Test de l'âge des lapins comparé avec leur âge de maturité. Si == définition du nouveau sexe avec la fonction Sexe().
Si nouvelle femelle, génération d'un nombre de mise à bas pour l'année avec la fonction NbMiseBas().
Incrémentation du nombre de males ou de femelles et décrémentation du nombres de bébés s'il y a changement de sexe.

Test de mort sur le lapin en cours. Si le lapin est mort incrémentation du nombre de lapins morts et décrémentation du nombre de lapins en vie et de femelles, males ou bebes.

Test de naissance. Si la femelle n'a pas atteint son nombre de mise à bas pour l'année et que c'est un mois ou elle doit mettre bas, on appelle la fonction Naissance() qui fait appelle la fonction CreerLapin() pour créer les nouveaux nées.
On incrémente le nombre de nouveaux bébés pour par la suite incrémenter le nombre de lapins.
On incrémente aussi le numéro de lapin.

Test de l'age des lapin et du sexe. Si le lapin est une femelle et qu'elle a un ans de plus, on lui génère un nouveau nombre de mise à bas pour l'année qui arrive.

}
FIN BOUCLE 'for' sur le nombre de lapins.

Incrémentation du nombre de lapins, de lapins en vie et de bébés avec les nouveaux nées crées dans la boucle terminée précédemment.

Boucle 'for' sur tous les lapins pour incrémenter l'âge des lapins.

Affichage du nombre de lapins vivants, morts, de femelles, males et bébés chaque mois.

Endormissement du programme pendant 2 secondes pour avoir le temps de regarder l'affichage du mois.

}
FIN BOUCLE 'for' sur le nombre de mois.

--------------------------------FIN DEUXIEME PARTIE----------------------------------

----------------------------------TROISIEME PARTIE-----------------------------------

Comptage du nombre total de lapins grâce aux variables females et males.

Affichage en fin de simulation du nombre total de lapins, de lapins en vie, de lapin morts, de femelles, de males et de bébés.

'return 0' pour sortir du programme une fois terminé.

--------------------------------FIN TROISIEME PARTIE---------------------------------


////////////////////


DOUBRE MAXIME
maxime.doubre@etu.uca.fr
L2 Informatique
Université Clermont Auvergne - UCA
