#include "liste.h"

using namespace std;

template<typename T>
class Element {
public:
    // constructeur
    Element<T>(const T &s);

private:
    T valeur;

    // pointeurs vers les voisins
    Element<T> *precedent;
    Element<T> *suivant;

    friend class Liste<T>;

    friend class Iterateur<T>;
};

template<typename T>
void Liste<T>::ajouter(const T &s) {
    Element<T> *elt = new Element<T>(s);

    elt->suivant = nullptr;
    elt->precedent = this->dernier;

    if (this->premier == nullptr) {
        this->premier = this->dernier = elt;
    } else
        this->dernier->suivant = elt;

    this->dernier = elt;

}

template<typename T>
void Liste<T>::inserer(Iterateur<T> &pos, const T &s) {
    Element<T> *elt = new Element<T>(s);

    elt->suivant = pos.position;

    pos.precedent();

    if (pos.position != nullptr) {
        elt->precedent = pos.position;
        elt->precedent->suivant = elt;
        elt->suivant->precedent = elt;
    } else {
        this->premier = elt;
    }
}

template<typename T>
void Liste<T>::supprimer(Iterateur<T> &pos) {

    if (pos.position != nullptr) {
        if (pos.position->precedent == nullptr) {
            pos.suivant();
            pos.position->precedent = nullptr;
            this->premier = pos.position;
        } else if (pos.position->suivant == nullptr) {
            pos.precedent();
            pos.position->suivant = nullptr;
            this->dernier = pos.position;
        } else if (pos.position->suivant == nullptr && pos.position->precedent == nullptr)
            this->premier = this->dernier = nullptr;
        else {
            pos.position->suivant->precedent = pos.position->precedent;
            pos.position->precedent->suivant = pos.position->suivant;
        }
    }
}

// Préfixe
template<typename T>
Iterateur<T> &Iterateur<T>::operator++() {
    if (this->position->suivant == nullptr) {
        this->position = this->dernier;
    }
    position = position->suivant;

    return *this;
}

// Suffixe
template<typename T>
Iterateur<T> &Iterateur<T>::operator++(int) {
    if (this->position->suivant == nullptr) {
        this->position = this->dernier;
    }
    position = position->suivant;

    return *this;
}

template<typename T>
Element<T>::Element(const T &s) {
    valeur = s;
    precedent = suivant = NULL;
}

template<typename T>
Iterateur<T>::Iterateur() {
    position = dernier = NULL;
}

template<typename T>
T &Iterateur<T>::get() const {
    return position->valeur;
}

template<typename T>
void Iterateur<T>::suivant() {
    position = position->suivant;
}

template<typename T>
void Iterateur<T>::precedent() {
    if (position == NULL) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
}

template<typename T>
bool Iterateur<T>::egal(const Iterateur &b) const {
    return position == b.position;
}

template<typename T>
Liste<T>::Liste() {
    premier = dernier = NULL;
}

template<typename T>
Iterateur<T> Liste<T>::debut() const {
    Iterateur<T> it;
    it.position = premier;
    it.dernier = dernier;
    return it;
}

template<typename T>
Iterateur<T> Liste<T>::fin() const {
    Iterateur<T> it;
    it.position = NULL;
    it.dernier = dernier;
    return it;
}
