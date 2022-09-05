//////////DESCRIPTION : //////////

In this folder there are all necessary files to execute the simulation.

Source codes : lapin.c et mt19937ar.c en language C.
Object files : lapin.o et mt19937ar.o
Header files : matsumoto.h
The executive file : exeSimu


To compile put the following commands into a terminal : 

gcc -c lapin.c
gcc -c mt19937ar.c
gcc lapin.o mt19937ar.o -o exeSimu


Style guide : 

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


Functions :

Lapin : rabbit strcture composed of variables defining rabbits.

NombreMois() : transform the number of year of the rabbit into number of month.

Maturite() : generate a random age of maturity for each rabbit.

NbMiseBas() : generate a random number of litter in the year for a female.

Portee() : generate a random number of babies during a litter.

CreerLapin() : create a new rabbit and init its variables.

Sexe() : determine the rabbit sex when in maturity age.

Naissance() : create new babies wwhen litter of a female.

Tuer() : kill the rabbit by changing his sex to 'd'. 

Mort() : choose if the rabbit sie or not.


Main : 

---------------------------------------FIRST PART----------------------------------------

Initialisation of the Matsumoto function

Définition of all variables and allocation of all rabbit strcture tables.

Ask to the user of the number of year for the simulation duration, the number of rabbits and the number of female at the beginning of the simulation.

Transformation of the number of year into number of month with the function NombreMois().

First loop 'for' in which we create  rabbits asked for the beginning of the simulation with the function CreerLapin(). 
Increment of the number of rabbits and the number of alive rabbits.

Second loop 'for' in which we define the sexe for all female asked at the beginning.

Third loop 'for' in which we define the sexe for all othe rabbits asked at the beginning.

------------------------------------END FIRST PART---------------------------------------

--------------------------------------SECOND PART----------------------------------------

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
maxime.doubre@gmail.com
M2 SIAME (Systèmes Informatiques Ambiants, Mobiles et Embarqués)
Université Paul Sabatier UT3 - Toulouse
Au moment de ce projet : L2 Informatique - Université Clermont Auvergne - UCA
