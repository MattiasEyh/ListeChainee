#include <string>
#include <list>
#include <iostream>
#include "liste.h"
#include "liste.cc"

using namespace std;

int main() {
    /*list<string> personnel;

    // ajouter 4 elements
    personnel.push_back("Baleze Bruno");
    personnel.push_back("Costaud Claude");
    personnel.push_back("Doue Damien");
    personnel.push_back("Vaillant Veronique");

    // ajouter un element a la quatrieme position
    list<string>::iterator pos = personnel.begin();
    pos++; pos++; pos++;
    personnel.insert(pos, "Sage Stephane");

    // supprimer l'element a la deuxieme position
    pos = personnel.begin();
    pos++;
    personnel.erase(pos);

    // afficher tous les elements
    for (pos = personnel.begin(); pos != personnel.end(); pos++)
        cout << *pos << endl;*/

    Liste<string> lst;

    lst.ajouter("Baleze Bruno");
    lst.ajouter("Costaud Claude");
    lst.ajouter("Doue Damien");
    lst.ajouter("Vaillant Veronique");

    Iterateur<string> pos;

    cout << "----------------\nListe de départ\n----------------" << endl;

    for(pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant())
    {
        cout << pos.get() << endl;
    }

    cout << endl << "----------------\nInsertion\n----------------" << endl;
    pos = lst.debut();

    pos.suivant();

    lst.inserer(pos, "Mattias Eyherabide");

    for(pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant())
    {
        cout << pos.get() << endl;
    }


    cout << endl << "----------------\nSuppression\n----------------" << endl;
    pos = lst.debut();

    pos.suivant();

    cout << "Pos actuelle : " <<pos.get() << endl;

    lst.supprimer(pos);

    for(pos = lst.debut(); !pos.egal(lst.fin()); pos.suivant())
    {
        cout << pos.get() << endl;
    }

    return 0;
}