//HEADER de la classe PILACARTA

#ifndef PILACARTES_H
#define PILACARTES_H
#include "Carta.h"
#include "Baralla.h"
#include <iostream>
using namespace std;

class PilaCartes
{
    // DESCRIPCIO: una pila de cartes
public:
    //CONSTRUCTORS I DESTRUCTOR
    PilaCartes();//Constructor per defecte. Pre:--; Post:pila de cartes buida
    PilaCartes(const PilaCartes& o);// Pre: --; Post: la pila actual es copia de la pila o
    ~PilaCartes();// Pre: --; Post: memoria alliberada (inclosa la dinamica)

    //CONSULTORS
    bool buida() const;// Pre: -- ; Post: retorna cert si la pila es buida, fals altrament
    Carta cim() const;// Pre: pila no buida; Post: retorna el valor del cim de la pila
    void mostra() const;//Pre:--; Post: mostra el cim de la pila

    //MODIFICADORS
    void empila(const Carta& c);// Pre: --; Post: ha afegit c a dalt de la pila
    void desempila();// Pre: pila no buida; Post: ha eliminat element de dalt de la pila
    void recicla(Baralla& c);//Pre:c no buida;Post: la pila actual es resultat de capgirar la baralla
    void recicla_pila(PilaCartes& b);//Pre:b no buida, Post:la pila actual és resultat de reciclar b

    //OPERADORS
    PilaCartes& operator=(const PilaCartes& o);
    //Pre:--;Post: pila actual es copia de la pila o i la seva mem˜oria dinamica ha estat previament alliberada

private:
    struct Node
    {
        Carta valor;
        Node* seg;
    };

    // ATRIBUTS
    Node* a_cim; // punter al cim de la pila

    // AUXILIARS
    void copia(const PilaCartes& o);// Pre: pila buida; Post: pila actual es copia de la pila o
    void allibera();// Pre: --; Post: memoria dinamica alliberada
};

#endif // PILACARTES_H
