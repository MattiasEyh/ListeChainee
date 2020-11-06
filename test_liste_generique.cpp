#include <string>
#include <iostream>
#include "liste.h"
#include "liste.cc"

int main() {


    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
            "| Création de plusieurs listes avec différents types : |\n"
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;


    cout << "\tCHAINE DE CARACTERE\n------------\n";

    Liste<string> lstString;
    Iterateur<string> posString;

    lstString.ajouter("Baleze Bruno");
    lstString.ajouter("Costaud Claude");
    lstString.ajouter("Doue Damien");
    lstString.ajouter("Vaillant Veronique");

    for (posString = lstString.debut(); !posString.egal(lstString.fin()); posString.suivant()) {
        cout << "-" << posString.get() << endl;
    }
    cout << "------------" << endl;


    cout << "\n\tCARACTERE\n------------\n";

    Iterateur<char> posChar;

    Liste<char> lstChar;

    lstChar.ajouter('a');
    lstChar.ajouter('e');
    lstChar.ajouter('b');
    lstChar.ajouter('c');

    for (posChar = lstChar.debut(); !posChar.egal(lstChar.fin()); posChar.suivant()) {
        cout << "-" << posChar.get() << endl;
    }
    cout << "------------" << endl;


    cout << "\n\tENTIER\n------------\n";

    Iterateur<int> posEntier;

    Liste<int> lstEntier;

    lstEntier.ajouter(1);
    lstEntier.ajouter(5);
    lstEntier.ajouter(6);
    lstEntier.ajouter(9);

    for (posEntier = lstEntier.debut(); !posEntier.egal(lstEntier.fin()); posEntier.suivant()) {
        cout << "-" << posEntier.get() << endl;
    }
    cout << "------------" << endl;


    cout << "\n\tREELS\n------------\n";

    Iterateur<double> posDouble;

    Liste<double> lstDouble;

    lstDouble.ajouter(1.67);
    lstDouble.ajouter(5.7845);
    lstDouble.ajouter(6.221);
    lstDouble.ajouter(9.154);

    for (posDouble = lstDouble.debut(); !posDouble.egal(lstDouble.fin()); posDouble.suivant()) {
        cout << "-" << posDouble.get() << endl;
    }
    cout << "------------" << endl;

    cout << "\n\tLISTE VIDE\n------------\n";

    Iterateur<string> posVide;

    Liste<string> lstVide;


    for (posVide = lstVide.debut(); !posVide.egal(lstVide.fin()); posVide.suivant()) {
        cout << "-" << posVide.get() << endl;
    }
    cout << "------------" << endl;


    cout << "\n\n- - - - - - - -\n"
            "| Test de base : : |\n"
            "- - - - - - - - - -\n" << endl;


    cout << "Acceder à une liste vide (get) : impossible" << endl;
    cout << "Pos d'une liste vide (get) : impossible" << endl;


    /**
     * STRING
     */
    cout << endl << "\t\nInsertion (STRING)\n----------------" << endl;

    cout << "Ajout d'un élément 'Mattias Eyherabide' :\n" << endl;

    posString = lstString.debut();

    posString.suivant();

    lstString.inserer(posString, "Mattias Eyherabide");

    for (posString = lstString.debut(); !posString.egal(lstString.fin()); posString.suivant()) {
        cout << posString.get() << endl;
    }


    cout << endl << "\t\nSuppression (STRING)\n----------------" << endl;



    posString = lstString.debut();

    posString.suivant();

    cout << "Pos actuelle : " << posString.get() << "\n" << endl;

    lstString.supprimer(posString);

    for (posString = lstString.debut(); !posString.egal(lstString.fin()); posString.suivant()) {
        cout << posString.get() << endl;
    }



    /**
     * CARACTERE
     */
    cout << endl << "\t\nInsertion (CARACTERE)\n----------------" << endl;

    cout << "Ajout d'un élément 'X' :\n" << endl;

    posChar = lstChar.debut();

    posChar.suivant();

    lstChar.inserer(posChar, 'X');

    for (posChar = lstChar.debut(); !posChar.egal(lstChar.fin()); posChar.suivant()) {
        cout << posChar.get() << endl;
    }


    cout << endl << "\t\nSuppression (CARACTERE)\n----------------" << endl;



    posChar = lstChar.debut();

    posChar.suivant();

    cout << "Pos actuelle : " << posChar.get() << "\n" << endl;

    lstChar.supprimer(posChar);

    for (posChar = lstChar.debut(); !posChar.egal(lstChar.fin()); posChar.suivant()) {
        cout << posChar.get() << endl;
    }



    /**
     * ENTIER
     */
    cout << endl << "\t\nInsertion (ENTIER)\n----------------" << endl;

    cout << "Ajout d'un élément 123456 :\n" << endl;

    posEntier = lstEntier.debut();

    posEntier.suivant();

    lstEntier.inserer(posEntier, 123456);

    for (posEntier = lstEntier.debut(); !posEntier.egal(lstEntier.fin()); posEntier.suivant()) {
        cout << posEntier.get() << endl;
    }


    cout << endl << "\t\nSuppression (ENTIER)\n----------------" << endl;



    posEntier = lstEntier.debut();

    posEntier.suivant();

    cout << "Pos actuelle : " << posEntier.get() << "\n" << endl;

    lstEntier.supprimer(posEntier);

    for (posEntier = lstEntier.debut(); !posEntier.egal(lstEntier.fin()); posEntier.suivant()) {
        cout << posEntier.get() << endl;
    }


    /**
     * REELS
     */
    cout << endl << "\t\nInsertion (REEL)\n----------------" << endl;

    cout << "Ajout d'un élément 123,456 :\n" << endl;

    posDouble = lstDouble.debut();

    posDouble.suivant();

    lstDouble.inserer(posDouble, 123.456);

    for (posDouble = lstDouble.debut(); !posDouble.egal(lstDouble.fin()); posDouble.suivant()) {
        cout << posDouble.get() << endl;
    }

    cout << endl << "\t\nSuppression (REEL)\n----------------" << endl;

    posDouble = lstDouble.debut();

    posDouble.suivant();

    cout << "Pos actuelle : " << posDouble.get() << "\n" << endl;

    lstDouble.supprimer(posDouble);

    for (posDouble = lstDouble.debut(); !posDouble.egal(lstDouble.fin()); posDouble.suivant()) {
        cout << posDouble.get() << endl;
    }

    cout << endl << "\t\nConstructeur par recopie\n----------------" << endl;

    cout << "Liste origine : " << "\n"<< endl;

    Liste<string> lstOrig;
    Liste<string> lstRecopie;

    lstOrig.ajouter("Element 1");
    lstOrig.ajouter("Element 2");
    lstOrig.ajouter("Element 3");
    lstOrig.ajouter("Element 4");

    Iterateur<string> posOrig;

    for (posOrig = lstOrig.debut(); !posOrig.egal(lstOrig.fin()); posOrig.suivant()) {
        cout << posOrig.get() << endl;
    }

    cout << "\nListe par recopie : " << "\n"<< endl;

    lstRecopie = lstOrig;

    for (posOrig = lstRecopie.debut(); !posOrig.egal(lstRecopie.fin()); posOrig.suivant()) {
        cout << posOrig.get() << endl;
    }

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
            "| Opérateurs de surcharge :                           |\n"
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;

    cout << "Operateur ++ : décaller de deux dans la liste" << endl;

    posString = lstString.debut();

    cout << "Préfix : "  << posString++.get() << endl;
    
    ++posString;
    cout << "Suffixe : " << posString.get() << endl;


    cout << endl << "\t\nBornes : \n----------------" << endl;

    posString = lstString.debut();

    cout << "Element du début : " << posString.get() << endl;
    cout << "\nTest pour aller en position -1 : " << endl;

    posString--;

    cout << "elt : " << posString.get() << ". La position est la même, le test de la borne inférieur à fonctionné." << endl;


    posString = lstString.fin();


    cout << "\n\nElement de fin : " << posString.get() << endl;
    cout << "\nTest pour aller en position +1 : " << endl;

    posString++;

    cout << "elt : " << posString.get() << ". La position est la même, le test de la borne supérieur à fonctionné." << endl;


    return 0;
}