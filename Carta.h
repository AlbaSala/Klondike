//HEADER de la classe CARTA

#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta
{
    //DESCRIPCIO: conté la informació d'una carta
public:

    //CONSTRUCTORS
    Carta();//Per defecte. Pre:--, Post: s'ha inicialitzat una carta
    Carta(int valor, char pal);//Pre:1<=valor<=13, pal==P,c,d,T; Post: a_valor = valor, a_pal = pal, a_visible = FALSE

    //CONSULTORS
    void mostra() const; //Pre:--; Post: mostra una carta
    bool es_visible() const; //Pre: --; Post: retorna cert si es visible, fals altrament
    bool casen(const Carta& c) const;//Pre:--; Post:cert si casen, fals altrament
    char pal() const;//Pre:--; Post:retorna el pal de la carta
    int valor() const;//Pre:cert; Post:retorna el valor

    //MODIFICADORS
    void fes_visible(); //Pre:--; Post: visible = true
    void fes_no_visible(); //Pre:--; Post: visible = false

private:
    int a_valor;
    char a_pal;
    bool a_visible;

    //AUXILIARS
    bool colors_alternate(char pal1, char pal2) const;
    //Pre:--; Post: cert si pal1 i pal2 son de colors diferents
};

#endif // CARTA_H

