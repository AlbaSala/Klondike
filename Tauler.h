//HEADER de la classe TAULER

#ifndef TAULER_H
#define TAULER_H
#include <iostream>
#include "Baralla.h"
#include <vector>
using namespace std;

class Tauler
{
    //DESCRIPCIO: conté una matriu dinàmica corresponent al tauler transposat
public:

    //CONSTRUCTOR
    Tauler(); //Pre:--; Post:tauler buit

    //CONSULTORS
    void mostra() const;//Pre:--; Post: mostra el tauler
    Carta cim_col(int col) const;//Pre: columna no buida, 0<=col<NC; Post:retorna la carta al cim de col
    bool col_buida(int col) const;//Pre:0<=col<NC; Post:cert si la columna es buida, fals altrament
    void espia() const;//Pre:--; Post: mostra totes les cartes del tauler com a visibles

    //MODIFICADORS
    void omple(Baralla& b);//Pre:b no buida; Post: es reparteix la baralla i s'omple el tauler
    void posar_carta(int col, const Carta& c); //Pre:0<=col<NC; Pre:Posa c al cim de col, s'actualitza la capacitat de col
    void treure_carta(int col);//Pre:0<=col<NC; Post: es treu la carta del cim de col, s'actualitza ña capacitat de col
    void mou_cartes_tauler(int f,int c);//Pre:tauler omplert, 0<=f,c, c<NC; Post:Mou les cartes dins del tauler
    void fes_darrera_visible(int col); //Pre:0<=col<NC; Post:fa l'ultima carta de la columna visible

    //CONSTANTS
    static const int NC = 7; //Nombre de columnes

private:
    //ATRIBUTS
    vector<vector<Carta> > a_t; //vector de vectors
    int caps_col[NC]; //Capacitat de cada columna
    static const int FMAX = 19; //Màxim nombre de files

    //AUXILIARS
    void inicialitza_caps_col();//Pre:--; Post:Inicialitza la capacitat de cada columna
};

#endif // TAULER_H

