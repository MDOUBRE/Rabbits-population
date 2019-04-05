/*	Inclusion des bibliothèques ainsi que du fichier header "matsumoto.h"	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "matsumoto.h"


/*	Définition de la taille max de notre tableau qui contiendra dans chaque case un lapin.	*/
#define NBLAPINMAX 100000000


/********************************************************************************************
 *  Lapin               Initialise mes lapins sous forme de structure                       *
 *                                                                                          *
 *  La structure comprend un age "age", un age de maturite "mature",                        *
 *  un compteur de mise à bas"cmp", un nombre de mise à bas "enceinte"                      *
 *  et un id sous forme d'entiers.                                                          *
 *                                                                                          *
 *  Elle comprend pour finir, un sexe "sexe" sous frorme de caractère :                     *
 *  'f' puor femelle, 'm' pour male, 'b' pour bebe et 'd' pour mort.                        *
 ********************************************************************************************/
struct Lapin
{
    int     age;
    char    sexe;
    int     mature;     /*  l'age de maturite du lapin auquel il aura son nouveau sexe	*/
    int     cmp;        /*  le nombre de mise a bas deja effectue dans l'annee			*/
    int     enceinte;   /*  le nombre de mise a bas que la femelle aura dans l'annee	*/
    int     id;
};


/*******************************************************************************************
 *  nombremois          Converti un nombre d'années en nombre de mois                       *
 *                                                                                          *
 *  En entrée : annee une entier qui correspond au nombre d'années de la simulation.        *
 *                                                                                          *
 *  En sortie : La valeur retournée est le nombre de mois équivalent aux nombre d'annee     *
 *  en entrée.                                                                              *
 ********************************************************************************************/
int NombreMois(int annee)
{
    int     nombre_mois;

    nombre_mois = 12 * annee;

    return nombre_mois;
}


/********************************************************************************************
 *  maturite            Génère un age de maturite aléatoire                                 *
 *                                                                                          *
 *  En entrée : la fonction ne prend rien en entrée.                                        *
 *                                                                                          *
 *  En sortie : La valeur entère retournée est soit 5, 6, 7 ou 8.                           *
 *  Elle correspond à un nombre de mois.                                                    *
 ********************************************************************************************/
int Maturite()
{
    double	mature_tmp;	/*	on utilise une variable temporaire qui sera un nombre aléatoire	*/
    int 	mature;
    mature = genrand_real1();
    
	/*
	*	On fait un test d'intervalle à partir de notre valeur aléatoire
	*	pour définir un âge de maturité pour notre lapin.
	*/
    if(mature_tmp >= 0 && mature_tmp < 0.25)
    {
        mature = 5;
    }
    else if(mature_tmp >= 0.25 && mature_tmp < 0.5)
    {
        mature = 6;
    }
    else if(mature_tmp >= 0.5 && mature_tmp < 0.75)
    {
        mature = 7;
    }
    else if(mature_tmp >= 0.75 && mature_tmp <=1)
    {
        mature = 8;
    }

    return mature;
}


/********************************************************************************************
 *  nbmisebas           Génère un nombre aléatoire de mise à bas pour l'année               *
 *                                                                                          *
 *  En entrée : Lapin lapin une structure qui correspond à un lapin.                        *
 *                                                                                          *
 *  En sortie : La valeur entière retournée est soit 4, 5, 6, 7 ou 8.                       *
 *  Il y a plus de chances de tomber sur 5, 6 ou 7.                                         *
 *  Elle correspond au nombre de mise à bas qu'aura une femelle au cours d'une année.       *
 ********************************************************************************************/
int NbMiseBas(struct Lapin lapin)
{
    double	nb_portee;	/*	on utilise une variable temporaire qui sera un nombre aléatoire		*/
    nb_portee = genrand_real1();

    /*
	*	On fait un test d'intervalle à partir de notre valeur àléatoire
	*	pour définir un nombre de mises à bas pour notre femelle.
	*/
	if(nb_portee >= 0 || nb_portee < 0.1)
    {
        lapin.enceinte = 4;
    }
    else if(nb_portee >= 0.1 || nb_portee < 0.37)
    {
        lapin.enceinte = 5;
    }
    else if(nb_portee >= 0.37 || nb_portee < 0.64)
    {
        lapin.enceinte = 6;
    }
    else if(nb_portee >= 0.64 || nb_portee < 0.9)
    {
        lapin.enceinte = 7;
    }
    else if(nb_portee >= 0.9 || nb_portee <= 1)
    {
        lapin.enceinte = 8;
    }

    return lapin.enceinte;
}


/********************************************************************************************
 *  portee              Génère un nombre aléatoire de bebes lors d'une mise à bas           *
 *                                                                                          *
 *  En entrée : la fonction ne prend rien en entrée.                                        *
 *                                                                                          *
 *  En sortie : La valeur entière retournée est 3, 4, 5 ou 6.                               *
 *  Elle correspond au nombre de bebes qu'une femelle aura lors de sa mis à bas.            *
 ********************************************************************************************/
int Portee()
{
    double	babies;	/*	on utilise une variable temporaire qui sera un nombre aléatoire		*/
    babies = genrand_real1();

    /*
	*	On fait un test d'intervalle à partir de notre valeur aléatoire
	*	pour définir un nombre de bébés lors de la mise à bas de notre femelle.
	*/
	if(babies >= 0 && babies < 0.25)
    {
        babies = 3;
    }
    else if(babies >= 0.25 && babies < 0.5)
    {
        babies = 4;
    }
    else if(babies >= 0.5 && babies < 0.75)
    {
        babies = 5;
    }
    else if(babies >= 0.75 && babies <=1)
    {
        babies = 6;
    }

    return babies;
}


/********************************************************************************************
 *  creerlapin          Crée un nouveau lapin et initialise ses variables                   *
 *                                                                                          *
 *  En entrée : numero un entier qui correspond à l'id du lapin.                            *
 *                                                                                          *
 *  En sortie : la fonction retourne la structre du lapin                                   *
 ********************************************************************************************/
struct Lapin CreerLapin(int numero)
{
    /*
	*	On crée un nouveau lapin et initialise ses variables.
	*	Son âge, son compteur de mise à bas et nombre de mise à bas dans l'année à 0.
	*	Son âge de maturité grâce à la fonction maturite() et son id grâce au numéro en paramètre.
	*	
	*	Enfin son sexe lui correspondant :
	*	'b' pour baby
	*	'f' pour female
	*	'm' pour male 
	*	'd' pour dead
	*/
	struct  Lapin lapin;
    lapin.age       = 0;
    lapin.sexe      = 'b';
    lapin.mature    = Maturite();
    lapin.cmp       = 0;
    lapin.enceinte  = 0;
    lapin.id        = numero;
    return lapin;
}


/********************************************************************************************
 *  sexe                Determine le sexe du lapin en âge de maturité                       *
 *                                                                                          *
 *  En entrée : lapin une structure correspondant à un lapin                                *
 *                                                                                          *
 *  En sortie : le caractère retourné est soit 'm' pour male soit 'f' pour female.          *
 *  Il y a 50% de chances pour qu'un lapin est un sexe ou l'autre .                         *
 ********************************************************************************************/
char Sexe(struct Lapin lapin)
{
    double	genre;	/*	on utilise une variable temporaire qui sera un nombre aléatoire		*/

    /*
	*	On fait un test d'intervalle pour définir un nouveau sexe à notre lapin mature.
	*/
	if(lapin.age == lapin.mature)
    {        
        genre = genrand_real1();
        if(genre >= 0 && genre < 0.5)
        {
            lapin.sexe = 'm';
        }
        else
        {
            lapin.sexe = 'f';
        }
    }

    return lapin.sexe;
}


/********************************************************************************************
 *  naissance           Crée les nouveaux lapins en cas de mise à bas d'une femelle         *
 *                                                                                          *
 *  En entrée : lapin une structure, *tab un tableau de structures,                         *
 *  nblapins un entier, numero un entier, nouveauxbebes un entier.                          *
 *                                                                                          *
 *  En sortie : la valeur entière retournée est le nombre de nouveaux bebes                 *
 *  mis à bas au cours du mois.                                                             *
 ********************************************************************************************/
int Naissance(struct Lapin lapin, struct Lapin *tab, int nb_lapins, int numero, int nouveaux_bebes)
{
    int     j, nb_babies;
    int     i=0;

    if(lapin.sexe == 'f')
    {
        if(lapin.cmp < lapin.enceinte)
        {
            nb_babies = Portee();	/*	on utilise portee() pour le nombre de nouveaux nées	*/
            nouveaux_bebes = nouveaux_bebes + nb_babies;
            
            for(j = 0; j < nb_babies; j++)
            {
                /*
                *	On crée nos nouveaux nés avec la fonction creerlapin().
                */
                tab[numero-1] = CreerLapin(numero);
                numero = numero + 1;
            }

            lapin.cmp = lapin.cmp + 1;/* On incrément le nombre de mise à bas de la femelle	*/	
        }
    }

    return nouveaux_bebes;
}



/********************************************************************************************
 *  tuer                Change les sexe du lapin en cas de mort                             *
 *                                                                                          *
 *  En entrée : lapin une structure.                                                        *
 *                                                                                          *
 *  En sortie : le caractère retourné est 'd'.                                              *
 ********************************************************************************************/
char Tuer(struct Lapin lapin)
{
    lapin.sexe = 'd';
    return lapin.sexe;
}


/********************************************************************************************
 *  mort                Fait mourir les lapins ou non                                       *
 *                                                                                          *
 *  En entrée : lapin une structure.                                                        *
 *                                                                                          *
 *  En sortie : le caractère retourné est 'd' si le lapin est mort, son sexe actuel sinon.  *
 ********************************************************************************************/
char Mort(struct Lapin lapin)
{
    double	en_vie;	/*	on utilise une variable temporaire qui sera un nombre aléatoire		*/

    /*
	*	On fait un test d'intervalle pour définir si notre lapin va mourir ou rester en vie.
	*	On fait le test selon l'âge de notre lapin pour que les bon pourçcentages de survie
	*	lui soient associé.
	*	
	*	Si le lapin doit mourir, on appelle la fonction tuer() qui changera son sexe à 'd'.
	*/
	if(lapin.sexe == 'b' && lapin.age%12 == 1)
    {
        en_vie = genrand_real1();

        if(en_vie >= 0.2 && en_vie < 0.4)
        {
            lapin.sexe = lapin.sexe;
            return lapin.sexe;
        }
        else
        {
            lapin.sexe = Tuer(lapin);
            return lapin.sexe;
        }
    }
    if((lapin.sexe == 'm' || lapin.sexe == 'f') && lapin.age < 132 && lapin.age%12 == 0)
    {
        en_vie = genrand_real1();

        if(en_vie >= 0 && en_vie < 0.5)
        {
            lapin.sexe = lapin.sexe;
            return lapin.sexe;
        }
        else
        {
            lapin.sexe = Tuer(lapin);
            return lapin.sexe;
        }
    }
    if(lapin.age >= 132 && lapin.age%12 == 0)
    {
        if(lapin.age == 132)
        {
            en_vie = genrand_real1();

            if(en_vie >= 0 || en_vie < 0.4)
            {
                lapin.sexe = lapin.sexe;
                return lapin.sexe;
            }
            else
            {
                lapin.sexe = Tuer(lapin);
                return lapin.sexe;
            }
        }
        if(lapin.age == 144)
        {
            en_vie = genrand_real1();

            if(en_vie >= 0 || en_vie < 0.3)
            {
               lapin.sexe = lapin.sexe;
               return lapin.sexe;
            }
            else
            {
                lapin.sexe = Tuer(lapin);
                return lapin.sexe;
            }
        }
        if(lapin.age == 156)
        {
            en_vie = genrand_real1();

            if(en_vie >= 0 || en_vie < 0.2)
            {
                lapin.sexe = lapin.sexe;
                return lapin.sexe;
            }
            else
            {
                lapin.sexe = Tuer(lapin);
                return lapin.sexe;
            }
        }
        if(lapin.age == 168)
        {
            en_vie = genrand_real1();

            if(en_vie >= 0 || en_vie < 0.1)
            {
                lapin.sexe = lapin.sexe;
                return lapin.sexe;
            }
            else
            {
                lapin.sexe = Tuer(lapin);
                return lapin.sexe;
            }
        }
        if(lapin.age == 180)
        {
            lapin.sexe = Tuer(lapin);
            return lapin.sexe;
        }
    }

    return lapin.sexe;
}


/********************************************************************************************
 *                                                                                          *
 *                                                                                          *
 *                                                                                          *
 *                                                                                          *
 *                                          MAIN                                            *
 *                                                                                          *
 *                                                                                          *
 *                                                                                          *
 *                                                                                          *
 ********************************************************************************************/


int main()
{
    /*
    *	On initialise la fonction de Matsumoto pour les générations de nombres aléatoires
    */
    unsigned long init[3]={0x123, 0x234, 0x345}, length=3;
    init_by_array(init, length);    
    
    /*
    *	On commence par définir toutes les variables dont on aura besoin dans le programme.
    *	
    *	m et i pour incrémenter nos boucles et nblapin et nbmois pour les utiliser. 
    *	
    *	annee_t, nblapin_t et nbfemales_t les trois données que l'on demande à l'utilisateur.
    *
    *	nouveauxbebes, nouvportee, nbtot, anciennouveauxbebes et nouveaux des variables utilisés 
    *	dans les fonctions.
    *	
    *	numerolapin qui servira d'id à cahque lapin.
    *	
    *	females, males, babies, morts et envie qui seront des compteurs de lapins. 	
    */   
    int     m, i;
    int		annee_t, nb_lapin_t, nb_females_t;
    int 	nb_lapin, nb_mois,  nb_tot;
    int		nouveaux_bebes, nouv_portee;
    int     numero_lapin = 1;
    int     females = 0;
    int     males = 0;
    int     babies = 0;
    int     morts = 0;
    int     en_vie = 0;
    int     ancien_nouveaux_bebes = 0;
    int     nouveaux = 0;
    struct  Lapin *tab = malloc(sizeof(int)*NBLAPINMAX);

    /*
    *	On demande sur combien d'années on veut faire la simulation, avec combien de lapins et
    * combiens de femelles au debut.
    */
    printf("simulation sur combien d'annees ?\n");    
    scanf("%d" , &annee_t);
    printf("Combien de lapins au debut ?\n");    
    scanf("%d" , &nb_lapin_t);
    printf("Combien de femelles au debut ?\n");    
    scanf("%d" , &nb_females_t);
    printf("\n");
    
    nb_mois = NombreMois(annee_t);	/*on transforme notre nombre d'années en nombre de mois*/
    nb_lapin = nb_lapin_t;			/*on change de variable pour le bon fonctionnement du programme*/
    
    
    /****************************************************************************************************/


	/*
	*	Dans la première boucle, on commence par créer tous les lapins rentrés par l'utilisateur
	*
	*	Dans la deuxième et la troisième, on assigne un sexe aux lapins crées selon le nombre de femelles
	*	demandés par l'utilisateur.
	*/
    for(i = 0; i < nb_lapin; i++)
    {
        tab[i] = CreerLapin(numero_lapin);
        numero_lapin = numero_lapin + 1;
        en_vie = en_vie + 1;
    }
    for(i = 0; i < nb_females_t; i++)
    {
        tab[i].mature = 0;
        tab[i].age = 1;
        tab[i].sexe = 'f';
        tab[i].enceinte = NbMiseBas(tab[i]);
        females = females + 1;        
    }
    for(i = nb_females_t; i < nb_lapin; i++)
    {
        tab[i].mature = 0;
        tab[i].age = 1;
        tab[i].sexe = 'm';
        males = males + 1;
    }
    
    
    /****************************************************************************************************/
    
    
    /*
    *	On démarre la simulation pendant m mois après création des premiers lapins
    */    
    for(m = 1; m <= nb_mois; m++)
    {
        nouveaux_bebes = 0;

        for(i = 0; i < nb_lapin; i++)
        {

            /*
            *	On test l'age des lapins pour voir s'ils sont mature.
            *	On leur donne un sexe et un nombre d'accouchelent pour l'annee si ce sont des femelles.
            *	Seulement un sexe sinon.
            */
            if(tab[i].age == tab[i].mature && tab[i].sexe != 'd')
            {
                tab[i].sexe = Sexe(tab[i]);
                if(tab[i].sexe == 'f')
                {
                    tab[i].enceinte = NbMiseBas(tab[i]);
                    females = females + 1;		/*  On incrémente le nombre de femelles	*/
                }
                else
                {
                    males = males + 1;			/*  On incrémente le nombre de males	*/
                }
                babies = babies - 1;			/*  On décrémente le nombre de bébés	*/
            }

            
            /*
            *	On test si le lapin est vivant et si c'est le cas on lance la fonction mort().
            *	Si le lapin meurt, on réalise les opérations sur les compteurs.
            */
            if(tab[i].sexe == 'f' || tab[i].sexe == 'm' || tab[i].sexe == 'b')
            {
                if(tab[i].sexe == 'f')
                {
                    tab[i].sexe = Mort(tab[i]);
                    if(tab[i].sexe == 'd')
                    {
                        females = females - 1;	/*  On décrémente le nombre de femelles	*/
                        en_vie = en_vie - 1;	/*  On décrémente le nombre de vivants	*/
                        morts = morts + 1;		/*  On incrémente le nombre de morts	*/
                    }
                }
                else if(tab[i].sexe == 'm')
                {
                    tab[i].sexe = Mort(tab[i]);
                    if(tab[i].sexe == 'd')
                    {
                        males = males - 1;		/*  On décrémente le nombre de males	*/
                        en_vie = en_vie - 1;	/*  On décrémente le nombre de vivants	*/
                        morts = morts + 1;		/*  On incrémente le nombre de morts	*/
                    }
                }
                else if(tab[i].sexe == 'b')
                {
                    tab[i].sexe = Mort(tab[i]);
                    if(tab[i].sexe == 'd')
                    {
                        babies = babies - 1;	/*  On décrémente le nombre de bébés	*/
                        en_vie = en_vie - 1;	/*  On décrémente le nombre de vivants	*/
                        morts = morts + 1;		/*  On incrémente le nombre de morts	*/
                    }
                }
            }
            
            
            /*
            *	Dans ce test, on regarde si les lapins doivent accoucher lors du mois.
            *	Si c'est le cas, on les fait mettre bas avec la fonction naissance().
            *
            *	Les males ne rentreront pas car leur nombre de mises à bas dans l'annee est égale à 0.
            */
            if(tab[i].enceinte == 4)
            {
                /*
                *	Dans chaque test, on répartie le nombre de mise à bas afin que les femèles ne mettent 
                *	pas à bas seulement pendant les premiers mois de l'année.
                */
                if(tab[i].age%12 == 1 || tab[i].age%12 == 4 || tab[i].age%12 == 7 || tab[i].age%12 == 10)
                {
                    nouveaux_bebes = Naissance(tab[i],tab,nb_lapin,numero_lapin,nouveaux_bebes);
                    if(nouveaux_bebes > ancien_nouveaux_bebes)
                    {
                        numero_lapin = numero_lapin + (nouveaux_bebes - ancien_nouveaux_bebes);
                    }
                }                
            }
            else if(tab[i].enceinte == 5)
            {
                if(tab[i].age%12 == 1 || tab[i].age%12 == 3 || tab[i].age%12 == 7 || tab[i].age%12 == 9 || tab[i].age%12 == 11)
                {
                    nouveaux_bebes = Naissance(tab[i],tab,nb_lapin,numero_lapin,nouveaux_bebes);
                    if(nouveaux_bebes > ancien_nouveaux_bebes)
                    {
                        numero_lapin = numero_lapin + (nouveaux_bebes - ancien_nouveaux_bebes);
                    }
                }                
            }
            else if(tab[i].enceinte == 6)
            {
                if(tab[i].age%12 == 1 || tab[i].age%12 == 3 || tab[i].age%12 == 5 || tab[i].age%12 == 7 || tab[i].age%12 == 9 || tab[i].age%12 == 11)
                {
                    nouveaux_bebes = Naissance(tab[i],tab,nb_lapin,numero_lapin,nouveaux_bebes);
                    if(nouveaux_bebes > ancien_nouveaux_bebes)
                    {
                        numero_lapin = numero_lapin + (nouveaux_bebes - ancien_nouveaux_bebes);
                    }
                }                
            }
            else if(tab[i].enceinte == 7)
            {
                if(tab[i].age%12 == 1 || tab[i].age%12 == 2 || tab[i].age%12 == 4 || tab[i].age%12 == 6 || tab[i].age%12 == 7 || tab[i].age%12 == 8 || tab[i].age%12 == 11)
                {
                    nouveaux_bebes = Naissance(tab[i],tab,nb_lapin,numero_lapin,nouveaux_bebes);
                    if(nouveaux_bebes > ancien_nouveaux_bebes)
                    {
                        numero_lapin = numero_lapin + (nouveaux_bebes - ancien_nouveaux_bebes);
                    }
                }                
            }
            else if(tab[i].enceinte == 8)
            {
                if(tab[i].age%12 == 1 || tab[i].age%12 == 2 || tab[i].age%12 == 3 || tab[i].age%12 == 4 || tab[i].age%12 == 5 || tab[i].age%12 == 7 || tab[i].age%12 == 9 || tab[i].age%12 == 10)
                {
                    nouveaux_bebes = Naissance(tab[i],tab,nb_lapin,numero_lapin,nouveaux_bebes);
                    if(nouveaux_bebes > ancien_nouveaux_bebes)
                    {
                        numero_lapin = numero_lapin + (nouveaux_bebes - ancien_nouveaux_bebes);
                    }
                }                
            }           
            
            
            /*
            *	Si ce sont des femeles et qu'elles ont 1 ans de plus, 
            *	on leur donne un nombre d'accouchement pour leur prochaine année.     
            */
            if(tab[i].sexe == 'f' && tab[i].age%12 == 0)
            {
                tab[i].enceinte = NbMiseBas(tab[i]);
                tab[i].cmp = 0;
            }
			
			
			/*
			*	On compte les bébés mis à bas pour leur faire les opérations le prochain mois.
			*/
            ancien_nouveaux_bebes = nouveaux_bebes;	
        }

        nb_lapin = nb_lapin + nouveaux_bebes;	/*  On ajoute les nouveaux nées aux lapins	*/
        en_vie = en_vie + nouveaux_bebes;		/*  On ajoute les nouveaux nées aux vivants	*/
        babies = babies + nouveaux_bebes;		/*  On ajoute les nouveaux nées aux bébés	*/

        
        /*
        *	Dans cette boucle on incrémente l'âge de tous les lapins avant de changer de mois.
        */
        for(i = 0; i < nb_lapin; i++)
        {
            tab[i].age = tab[i].age + 1;
        }
        
        
        /*
        *	On réalise un affichage à chaque fin de mois.
        *	Elle contient le nombre de vivants, morts, femelles, males et bébés à la fin du mois.
        */
        printf("Mois no %d\n" , m);
        printf("-------------------------------------\n");
        printf("Nombre total de lapins en vie   : %d.\n" , en_vie);
        printf("Nombre total de lapins morts    : %d.\n" , morts);
        printf("Nombre total de femelles        : %d.\n" , females);
        printf("Nombre total de males           : %d.\n" , males);
        printf("Nombre total de bebes           : %d.\n" , babies);
        printf("-------------------------------------\n\n");

        
        sleep(2);	/*	On utilise sleep() afin d'endormir le programme à chaque affichage	*/        
	}
	
	
	/****************************************************************************************************/
	

	/*
	*	On compte le nombre total de lapins à la fin de la simulation.	
	*/
    nb_tot = en_vie + morts;

	
	/*
	*	On termine par faire un affichage en fin de simulation.
	*	On affiche le nombre total de lains, de vivants, de morts, de femelles, de males et de bébés.
	*/
    printf("\n");
    printf("-------------------------------------\n");
    printf("Simulation terminee.\n");
    printf("Nombre total de lapins          : %d.\n" , nb_tot);
    printf("Nombre total de lapins en vie   : %d.\n" , en_vie);
    printf("Nombre total de lapins morts    : %d.\n" , morts);
    printf("Nombre total de femelles        : %d.\n" , females);
    printf("Nombre total de males           : %d.\n" , males);
    printf("Nombre total de bebes           : %d.\n" , babies);    
    printf("-------------------------------------\n\n");
    
    
    return 0;
}
