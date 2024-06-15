//HEADER de la classe JOC

#ifndef JOC_H
#define JOC_H
#include <iostream>
#include "Baralla.h"
#include "Tauler.h"
#include "PilaCarta.h"
using namespace std;

class Joc
{
    //DESCRIPCIO: taulell, baralla i piles de cartes
public:
    //CONSTRUCTOR
    Joc(Baralla& baralla); //Pre:baralla no esta barrejada; Post:el joc està preparat per iniciar la partida

    //CONSULTORS
    void mostra(bool guanyat) const; //Pre:--; Post:mostra l'estat actual del joc
    void espia_tauler(bool guanyat) const; //Pre:--; Post: mostra el tauler amb totes les cartes visibles
    bool joc_guanyat() const;//Pre--; Post:cert si s'ha guanyat la partida, fals altrament

    //MODIFICADORS
    void obrir_carta(); //Pre:--; Post: fa la carta de la ma visible i la posa a la de descartades
    void posar_carta_tauler(); //Pre:--; Post: Si es pot posa l'ultima carta oberta al tauler, altrament mostra missatge
    void posar_carta_ma_pila();//Pre:--; Post: Si es pot posa l'ultima carta oberta a la pila, altrament mostra missatge
    void mou_tauler_tauler();//Pre:--; Post: Mou carta tauler->tauler, altrament mostra missatge
    void mou_tauler_pila();//Pre: --; Post:Mou carta tauler -> pila, altrament mostra missatge
    void recupera_carta();//Pre:--; Post:recupera la carta d'una pila i la torna al joc, altrament mostra missatge

private:
    Tauler a_tauler;
    PilaCartes a_ma;
    PilaCartes a_descartades;
    static const int N_PALS = 4;//nombre de pals
    PilaCartes a_pals[N_PALS];//Piles de pals
};

#endif // JOC_H
