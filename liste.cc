#include "liste.h"

using namespace std;

class Element {
public:
   // constructeur
   Element(const string& s);

private:
   string valeur;

   // pointeurs vers les voisins
   Element* precedent;
   Element* suivant;

friend class Liste;
friend class Iterateur;
};

void Liste::ajouter(const std::string &s) {
    Element * elt = new Element(s);

    elt->suivant = nullptr;
    elt->precedent = this->dernier;

    if (this->premier == nullptr)
    {
        this->premier = this->dernier = elt;
    }
    else
        this->dernier->suivant = elt;

    this->dernier = elt;

}

void Liste::inserer(Iterateur &pos, const std::string &s) {
    Element * elt = new Element(s);

    elt->suivant = pos.position;

    pos.precedent();

    if (pos.position != nullptr)
    {
        elt->precedent = pos.position;
        elt->precedent->suivant = elt;
        elt->suivant->precedent = elt;
    }
    else
    {
        this->premier = elt;
    }
}

void Liste::supprimer(Iterateur &pos) {

    if (pos.position != nullptr )
    {
        if (pos.position->precedent == nullptr)
        {
            pos.suivant();
            pos.position->precedent = nullptr;
            this->premier = pos.position;
        }
        else if(pos.position->suivant == nullptr)
        {
            pos.precedent();
            pos.position->suivant = nullptr;
            this->dernier = pos.position;
        }
        else if(pos.position->suivant == nullptr && pos.position->precedent == nullptr)
            this->premier = this->dernier = nullptr;
        else
        {
            pos.position->suivant->precedent = pos.position->precedent;
            pos.position->precedent->suivant = pos.position->suivant;
        }
    }
}

// Préfixe
Iterateur & Iterateur::operator++(){
    if (this->position->suivant == nullptr )
    {
        this->position = this->dernier;
    }
    position = position->suivant;

    return *this;
}

// Suffixe
Iterateur & Iterateur::operator++(int) {
    if (this->position->suivant == nullptr )
    {
        this->position = this->dernier;
    }
    position = position->suivant;

    return *this;
}

Element::Element(const string& s) {
   valeur = s;
   precedent = suivant = NULL;
}


Iterateur::Iterateur() {
   position = dernier = NULL;
}


string& Iterateur::get() const {
   return position->valeur;
}


void Iterateur::suivant() {
   position = position->suivant;
}


void Iterateur::precedent() {
   if (position == NULL) // fin de la liste
      position = dernier;
   else
      position = position->precedent;
}


bool Iterateur::egal(const Iterateur& b) const {
   return position == b.position;
}


Liste::Liste() {
   premier = dernier = NULL;
}


Iterateur Liste::debut() const {
   Iterateur it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}


Iterateur Liste::fin() const {
   Iterateur it;
   it.position = NULL;
   it.dernier = dernier;
   return it;
}
