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
void Liste<T>::free() {
    delete premier;
    delete dernier;
}

template<typename T>
void Liste<T>::copy(const Liste<T> &l) {
    premier = dernier = NULL;
    Iterateur<T> it;
    it = l.debut();
    while (it.position->suivant != NULL)
    {
        ajouter(*it);
        it++;
    }

    ajouter(*it++);
}

template<typename T>
Liste<T>::Liste(const Liste<T> &l) {
    copy(l);
}

template<typename T>
Liste<T>::~Liste() {
    free();
}

template<typename T>
Liste<T> & Liste<T>::operator=(const Liste<T> &l) {
    if (this != &l){
        free();
        copy(l);
    }

    return *this;
}

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

template<typename T>
bool Iterateur<T>::operator==(const Iterateur<T> &b) const {
    return position == b.position;
}

template<typename T>
bool Iterateur<T>::operator!=(const Iterateur<T> &b) const {
    return position != b.position;
}

template<typename T>
T& Iterateur<T>::operator*() const {
    return this->position->valeur;
}

/**
 * Operateur ++ (pour remplacer le suivant() )
 * @return
 */
// Préfixe
template<typename T>
Iterateur<T> & Iterateur<T>::operator++(){
    if (this->position->suivant != NULL )
        position = position->suivant;

    return *this;
}

// Suffixe
template<typename T>
Iterateur<T> & Iterateur<T>::operator++(int) {
    if (this->position->suivant != NULL )
        position = position->suivant;

    return *this;
}

/**
 * Operateur -- (pour remplacer le suivant() )
 * @return
 */
// Préfixe
template<typename T>
Iterateur<T> & Iterateur<T>::operator--(){
    if (this->position->precedent  != NULL) // debut de la liste
        this->position = this->position->precedent;

    return *this;
}

// Suffixe
template<typename T>
Iterateur<T> & Iterateur<T>::operator--(int) {
    if (this->position->precedent  != NULL) // debut de la liste
        this->position = this->position->precedent;

    return *this;
}

template<typename T>
Element<T>::Element(const T &s) {
    valeur = s;
    precedent = suivant = nullptr;
}

template<typename T>
Iterateur<T>::Iterateur() {
    position = dernier = nullptr;
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
    if (position == nullptr) // fin de la liste
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
    premier = dernier = nullptr;
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
    it.position = dernier;
    it.dernier = dernier;
    return it;
}
