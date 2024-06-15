//IMPLEMENTACIÓ de la classe CARTA

#include "Carta.h"
#include <iostream>
#include <cassert>
using namespace std;

//CONSTRUCTORS

Carta::Carta()
{
    //Pre:--, Post: s'ha inicialitzat una carta. Constructor per defecte
    a_valor = 0;
    a_pal = ' ';
    a_visible = false;
}

Carta::Carta(int valor, char pal)
{
    //Pre:1<=valor<=13, pal==P,c,d,T; Post: a_valor = valor, a_pal = pal, a_visible = FALSE
    assert(valor >= 1 && valor <= 13 && "Valor de la carta no valid");//Per assegurar que només s'utilitzen els valors valids
    assert(pal == 'P' or pal == 'c' or pal == 'd' or pal == 'T' && "Pal no valid");//Només pals vàlids

    a_valor = valor;
    a_pal = pal;
    a_visible = false;
}

//CONSULTORS

void Carta::mostra() const
{
//Pre:--; Post: mostra una carta
    if (a_visible)
    {
        //Els valors no numèrics cal codificar-los
        if (a_valor == 1) cout << 'A';
        else if (a_valor == 10) cout << 'D';
        else if (a_valor == 11) cout << 'J';
        else if (a_valor == 12) cout << 'Q';
        else if (a_valor == 13) cout << 'K';
        else cout << a_valor;//Pels valors numèrics
        cout << a_pal << " ";
    }
    else
    {
        cout << "** ";//si no és visible
    }
}

bool Carta::es_visible() const
{
//Pre: --; Post: retorna cert si es visible, fals altrament
    return a_visible;
}

bool Carta::colors_alternate(char pal1, char pal2) const
{
//Pre:--; Post: cert si pal1 i pal2 son de colors diferents.
//Negre: majúscula; Vermell: minúscula
    return ((pal1 == 'P' or pal1 == 'T') and (pal2 == 'c' or pal2 == 'd')) or
           ((pal1 == 'c' or pal1 == 'd') and (pal2 == 'P' or pal2 == 'T'));
}

bool Carta::casen(const Carta& c) const
{
//Pre:--; Post:cert si la carta actual pot anar damunt la c, fals altrament
    return a_valor == c.a_valor - 1 and colors_alternate(c.a_pal, a_pal);
}

char Carta::pal() const
{
//Pre:--; Post:retorna el pal de la carta
    return a_pal;
}

int Carta::valor() const
{
//Pre:cert; Post:retorna el valor de la carta
    return a_valor;
}

//MODIFICADORS

void Carta::fes_visible()
{
//Pre:--; Post: fa la carta visible
    a_visible = true;
}

void Carta::fes_no_visible()
{
//Pre:--; Post: fa la carta no visible
    a_visible = false;
}



