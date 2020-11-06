#ifndef LISTE_H

#define LISTE_H

#include <string>

template<typename T>
class Element;

template<typename T>
class Iterateur;

template<typename T>
class Liste {
public:
    // constructeur
    Liste<T>();

    Liste(const Liste<T>&);

    // constructeur par recopie
    void copy(const Liste<T> &l);

    // libération de la mémoire
    void free();

    // destructeur
    ~Liste();

    // Operateur d'affectation
    Liste<T> & operator=(const Liste<T> & l);

    // ajouter s a la fin de la liste
    void ajouter(const T &s);

    // ajouter s avant la position pos
    void inserer(Iterateur<T> &pos, const T &s);

    // supprimer l'element a la position pos
    void supprimer(Iterateur<T> &pos);

    // la premiere position
    Iterateur<T> debut() const;

    // la fin de la liste (apres la derniere position)
    Iterateur<T> fin() const;

private:
    // pointeurs vers le premier et le dernier element
    Element<T> *premier;
    Element<T> *dernier;
};

template<typename T>
class Iterateur {
public:
    // constructeur
    Iterateur<T>();

    // retourne la valeur dans cette position
    T &get() const;

    // avance a la position suivante
    void suivant();

    // recule a la position precedente
    void precedent();

    // compare deux iterateurs
    bool egal(const Iterateur<T> &b) const;

    bool operator==(const Iterateur<T> &b) const;
    bool operator!=(const Iterateur<T> &b) const;


    // Surcharges d'opérateurs
    T&  operator*() const;

    Iterateur<T> &operator++();
    Iterateur<T> &operator++(int);

    Iterateur<T> &operator--();
    Iterateur<T> &operator--(int);

private:
    // pointeur vers l'element courant
    Element<T> *position;

    // pointeur vers le dernier element de la liste
    Element<T> *dernier;

    friend class Liste<T>;
};

#endif
