/**
 * \file liste.cc
 * \brief Classe liste
 * \author Mattias Eyherabide
 * \version 2.0
 * \date 6 novembre 2020
 *
 * Permet de créer toutes les méthodes et classes pour
 * les classes Element, Iterateur et liste.
 */


#include "liste.h"

using namespace std;

/*!
 * \class Element
 * \brief classe pour les éléments de la liste
 * @tparam T
 *
 * La classe gere les éléments contenus dans la
 * liste chaînée. Le type est générique.
 */
template<typename T>
class Element {
public:
    /*!
    *  \brief Constructeur
    *  \param valeure générique à insérer dans l'élément.
    *  Constructeur de la classe Element
    */
    Element<T>(const T &s);

private:
    T valeur; /*!< Valeur de l'élément courant de la liste */

    Element<T> *precedent; /*!< Pointeur vers le voisin précédent*/
    Element<T> *suivant;  /*!< Pointeur vers le voisin suivant */

    friend class Liste<T>; /*!< Classe amie de Liste<T> */

    friend class Iterateur<T>; /*!< Classe amie de Iterateur<T> */
};

/*!
 * \brief Libération de la mémoire
 * Permet de libérer la mémoire dans une liste.
 * Est utilisé dans le déstructeur.
 */
template<typename T>
void Liste<T>::free() {
    delete premier;
    delete dernier;
}

/*!
 * \brief Copie d'une liste
 * @param l
 * Permet la copie d'une liste, est utilisé
 * dans le constructeur par recopie
 */
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

/*!
 * \brief Constructeur par recopie
 * Constructeur par recopie de la classe Liste.
 */
template<typename T>
Liste<T>::Liste(const Liste<T> &l) {
    copy(l);
}

/*!
 * \brief Destructeur
 * Destructeur de la classe Liste.
 */
template<typename T>
Liste<T>::~Liste() {
    free();
}

/*!
 * \brief Opérateur d'affectation
 * @param l
 * @return
 */
template<typename T>
Liste<T> & Liste<T>::operator=(const Liste<T> &l) {
    if (this != &l){
        free();
        copy(l);
    }

    return *this;
}

/*!
 * \brief Ajout d'une valeur s
 * @param l
 * @return
 * Ajout une valeur générique dans un élément
 */
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

/*!
 * \brief Insértion d'une valeur s
 * @param l
 * @return
 * Ajout une valeur générique dans un élément par insérsion
 */
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

/*!
* \brief Supression d'un élément
* @param l
* @return
* Supression d'un élément dans la liste
*/
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

/*!
 * \brief Comparateur (surcharge d'opérateur)
 * @param b
 * @return Retourne si l'itérateur est égal au courant.
 * Permet de comparer un itérateur avec l'itérateur courant
 * en renvoyant un booléen.
 */
template<typename T>
bool Iterateur<T>::operator==(const Iterateur<T> &b) const {
    return position == b.position;
}

template<typename T>
bool Iterateur<T>::operator!=(const Iterateur<T> &b) const {
    return position != b.position;
}

/*!
 * \brief Comparateur (surcharge d'opérateur)
 * @param b
 * @return Retourne si l'itérateur est différent au courant.
 * Permet de comparer un itérateur avec l'itérateur courant
 * en renvoyant un booléen.
 */
template<typename T>
T& Iterateur<T>::operator*() const {
    return this->position->valeur;
}

/*!
*  \brief Incrémentation de l'itérateur dans la liste (Surcharge d'opérateur prefixe)
*  \return Nouvel itérateur courant.
*  Méthode pour incrémenter l'itérateur dans la liste
*/

template<typename T>
Iterateur<T> & Iterateur<T>::operator++(){
    if (this->position->suivant != NULL )
        position = position->suivant;

    return *this;
}

/*!
*  \brief Incrémentation de l'itérateur dans la liste (Surcharge d'opérateur suffixe)
*  \return Nouvel itérateur courant.
*  Méthode pour incrémenter l'itérateur dans la liste
*/
template<typename T>
Iterateur<T> & Iterateur<T>::operator++(int) {
    if (this->position->suivant != NULL )
        position = position->suivant;

    return *this;
}

/*!
*  \brief Décrémentation de l'itérateur dans la liste (Surcharge d'opérateur préfixe)
*  \return Nouvel itérateur courant.
*  Méthode pour décrémenter l'itérateur dans la liste
*/
template<typename T>
Iterateur<T> & Iterateur<T>::operator--(){
    if (this->position->precedent  != NULL) // debut de la liste
        this->position = this->position->precedent;

    return *this;
}

/*!
*  \brief Décrémentation de l'itérateur dans la liste (Surcharge d'opérateur postfixe)
*  \return Nouvel itérateur courant.
*  Méthode pour décrémenter l'itérateur dans la liste
*/
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

/*!
*  \brief Constructeur
*  Constructeur de la classe Itérateur
*/
template<typename T>
Iterateur<T>::Iterateur() {
    position = dernier = nullptr;
}

/*!
*  \brief Getter
*  Méthode pour retourner la valeur de l'élément pointé par l'itérateur.
*/
template<typename T>
T &Iterateur<T>::get() const {
    return position->valeur;
}

/*!
*  \brief Incrémentation de l'itérateur dans la liste
*  Méthode pour incrémenter l'itérateur dans la liste
*/
template<typename T>
void Iterateur<T>::suivant() {
    position = position->suivant;
}

/*!
*  \brief Décrémentation de l'itérateur dans la liste
*  Méthode pour décrémenter l'itérateur dans la liste
*/
template<typename T>
void Iterateur<T>::precedent() {
    if (position == nullptr) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
}

/*!
 * \brief Comparateur
 * @param b
 * @return Retourne si l'itérateur est égal au courant.
 * Permet de comparer un itérateur avec l'itérateur courant
 * en renvoyant un booléen.
 */
template<typename T>
bool Iterateur<T>::egal(const Iterateur &b) const {
    return position == b.position;
}

template<typename T>
Liste<T>::Liste() {
    premier = dernier = nullptr;
}

/*!
 * \brief Itérateur du premier élément
 * @return
 * Itérateur pointant sur le premier élément de la liste.
 */
template<typename T>
Iterateur<T> Liste<T>::debut() const {
    Iterateur<T> it;
    it.position = premier;
    it.dernier = dernier;
    return it;
}

/*!
 * \brief Itérateur du dernier élément
 * @return
 * Itérateur pointant sur le dernier élément de la liste +1.
 */
template<typename T>
Iterateur<T> Liste<T>::fin() const {
    Iterateur<T> it;
    it.position = dernier;
    it.dernier = dernier;
    return it;
}
