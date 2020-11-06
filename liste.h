/**
 * \file liste.h
 * \brief Header pour la calsse liste.
 * \author Mattias Eyherabide
 * \version 2.0
 * \date 6 novembre 2020
 *
 * Permet de définir toutes les méthodes et classes pour
 * les classes Element, Iterateur et liste.
 */

#ifndef LISTE_H

#define LISTE_H

#include <string>

/*!
 * \class Element
 * \brief classe pour les éléments de la liste
 * @tparam T
 *
 * La classe gere les éléments contenus dans la
 * liste chaînée. Le type est générique.
 */
template<typename T>
class Element;


/*!
 * \class Iterateur
 * \brief classe pour les itérateurs de la liste
 * @tparam T
 *
 * La classe gere les itérateurs pointants les éléments
 * de la liste chaînée. Le type est générique.
 */
template<typename T>
class Iterateur;


/*!
 * \class Liste
 * \brief classe de la liste
 * @tparam T
 *
 * La classe gere la totalité du fonctionnement de la liste.
 */
template<typename T>
class Liste {
public:
    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Liste
    */
    Liste<T>();

    /*!
     * \brief Constructeur par recopie
     * Constructeur par recopie de la classe Liste.
     */
    Liste(const Liste<T>&);

    /*!
     * \brief Destructeur
     * Destructeur de la classe Liste.
     */
    ~Liste();

    /*!
     * \brief Copie d'une liste
     * @param l
     * Permet la copie d'une liste, est utilisé
     * dans le constructeur par recopie
     */
    void copy(const Liste<T> &l);

    /*!
     * \brief Libération de la mémoire
     * Permet de libérer la mémoire dans une liste.
     * Est utilisé dans le déstructeur.
     */
    void free();

    /*!
     * \brief Opérateur d'affectation
     * @param l
     * @return
     */
    Liste<T> & operator=(const Liste<T> & l);

    /*!
     * \brief Ajout d'une valeur s
     * @param l
     * @return
     * Ajout une valeur générique dans un élément
     */
    void ajouter(const T &s);

    /*!
     * \brief Insértion d'une valeur s
     * @param l
     * @return
     * Ajout une valeur générique dans un élément par insérsion
     */
    void inserer(Iterateur<T> &pos, const T &s);

    /*!
    * \brief Supression d'un élément
    * @param l
    * @return
    * Supression d'un élément dans la liste
    */
    void supprimer(Iterateur<T> &pos);

    /*!
     * \brief Itérateur du premier élément
     * @return
     * Itérateur pointant sur le premier élément de la liste.
     */
    Iterateur<T> debut() const;

    /*!
     * \brief Itérateur du dernier élément
     * @return
     * Itérateur pointant sur le dernier élément de la liste +1.
     */
    Iterateur<T> fin() const;

private:
    // pointeurs vers le premier et le dernier element
    Element<T> *premier; /*!< Premier élément de la liste */
    Element<T> *dernier; /*!< Dernier élément de la liste */
};

template<typename T>
class Iterateur {
public:

    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Itérateur
    */
    Iterateur<T>();

    /*!
    *  \brief Getter
    *  Méthode pour retourner la valeur de l'élément pointé par l'itérateur.
    */
    T &get() const;

    /*!
    *  \brief Incrémentation de l'itérateur dans la liste
    *  Méthode pour incrémenter l'itérateur dans la liste
    */
    void suivant();

    /*!
    *  \brief Décrémentation de l'itérateur dans la liste
    *  Méthode pour décrémenter l'itérateur dans la liste
    */
    void precedent();

    /*!
     * \brief Comparateur
     * @param b
     * @return Retourne si l'itérateur est égal au courant.
     * Permet de comparer un itérateur avec l'itérateur courant
     * en renvoyant un booléen.
     */
    bool egal(const Iterateur<T> &b) const;

    /*!
     * \brief Comparateur (surcharge d'opérateur)
     * @param b
     * @return Retourne si l'itérateur est égal au courant.
     * Permet de comparer un itérateur avec l'itérateur courant
     * en renvoyant un booléen.
     */
    bool operator==(const Iterateur<T> &b) const;

    /*!
     * \brief Comparateur (surcharge d'opérateur)
     * @param b
     * @return Retourne si l'itérateur est différent au courant.
     * Permet de comparer un itérateur avec l'itérateur courant
     * en renvoyant un booléen.
     */
    bool operator!=(const Iterateur<T> &b) const;

    /*!
     *  \brief Getter
     *  Méthode pour retourner la valeur de l'élément pointé par l'itérateur.
     * @return La valeur de l'élement pointé par l'itérateur courant.
     */
    T&  operator*() const;

    /*!
    *  \brief Incrémentation de l'itérateur dans la liste (Surcharge d'opérateur postfixe)
    *  \return Nouvel itérateur courant.
    *  Méthode pour incrémenter l'itérateur dans la liste
    */
    Iterateur<T> &operator++();

    /*!
    *  \brief Incrémentation de l'itérateur dans la liste (Surcharge d'opérateur préfixe)
    *  \return Nouvel itérateur courant.
    *  Méthode pour incrémenter l'itérateur dans la liste
    */
    Iterateur<T> &operator++(int);

    /*!
    *  \brief Décrémentation de l'itérateur dans la liste (Surcharge d'opérateur postfixe)
    *  \return Nouvel itérateur courant.
    *  Méthode pour décrémenter l'itérateur dans la liste
    */
    Iterateur<T> &operator--();

    /*!
    *  \brief Décrémentation de l'itérateur dans la liste (Surcharge d'opérateur préfixe)
    *  \return Nouvel itérateur courant.
    *  Méthode pour décrémenter l'itérateur dans la liste
    */
    Iterateur<T> &operator--(int);

private:

    Element<T> *position; /*!< Elément courant de la liste */
    Element<T> *dernier; /*!< Dernier élément de la liste */

    friend class Liste<T>;
};

#endif
