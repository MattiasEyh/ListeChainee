#include <string>
#include <iostream>
#include "liste.h"
#include "liste.cc"

int main() {
    Liste<string> lst;

    lst.ajouter("Baleze Bruno");
    lst.ajouter("Costaud Claude");
    lst.ajouter("Doue Damien");
    lst.ajouter("Vaillant Veronique");

    Iterateur<string> pos;

    cout << "----------------\nListe de départ\n----------------" << endl;

    for (pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant()) {
        cout << pos.get() << endl;
    }

    cout << endl << "----------------\nInsertion\n----------------" << endl;
    pos = lst.debut();

    pos.suivant();

    lst.inserer(pos, "Mattias Eyherabide");

    for (pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant()) {
        cout << pos.get() << endl;
    }


    cout << endl << "----------------\nSuppression\n----------------" << endl;
    pos = lst.debut();

    pos.suivant();

    cout << "Pos actuelle : " << pos.get() << endl;

    lst.supprimer(pos);

    for (pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant()) {
        cout << pos.get() << endl;
    }

    return 0;
}