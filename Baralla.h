//HEADER de la classe BARALLA

#ifndef BARALLA_H
#define BARALLA_H
#include <iostream>
#include <vector>
#include "Carta.h"

using namespace std;

class Baralla
{
    //DESCRIPCIO: conté un vector de 52 cartes de poker
public:

    //CONSTRUCTORS
    Baralla(); //Constructor per defecte. Pre:--; Post: baralla buida

    //CONSULTORS
    void mostra() const; //Pre:--; Post: mostra la baralla
    Carta last() const; //Pre:baralla no buida; Post:retorna l'ultima carta de la baralla
    bool buida() const;//Pre:--; Post:retorna cert si la baralla es buida

    //MODIFICADORS
    void omple(); //Pre:--; Post: omple la baralla
    void barreja(unsigned llavor); //Pre:baralla no buida, Post:barreja una baralla de cartes
    void elimina_last(); //Pre:baralla no buida; Post: elimina l'ultima carta

private:
    vector<Carta> a_vec; //Vector de cartes

    //AUXILIARS
    int aleatori(unsigned& llavor); //Pre:--; Post:genera un nombre aleatori, actualitza la llavor
    void intercanvi(Carta& a, Carta& b); //Pre:a=A i b=B; Post: a=B i b=A
    static const int N_CARTES = 52; //Nombre de cartes que conté la baralla
};

#endif // BARALLA_H

