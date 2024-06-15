//IMPLEMENTACIÓ de la classe BARALLA

#include <iostream>
#include <vector>
#include "Carta.h"
#include "Baralla.h"
#include<cassert>
using namespace std;

//CONSTRUCTOR

Baralla::Baralla()
{
//Pre.--; Post: baralla buida
    //no cal
}

//CONSULTORS

void Baralla::mostra() const
{
    //Pre:--; Post: mostra la baralla
    //No s'utilitza en el codi final, pero facilita el debugging
    unsigned i = 0;
    while (i < a_vec.size())
    {
        for (unsigned j = 0; j < 13 && i < a_vec.size(); j++)
        {
            a_vec[i].mostra();
            i++;
        }
        cout << endl;
    }
}

Carta Baralla::last() const
{
//Pre:baralla no buida; Post:retorna l'ultima carta de la baralla
    assert(!buida()); //Assegura que la baralla no es buida
    return a_vec.back();
}

bool Baralla::buida() const
{
//Pre:--; Post:retorna cert si la baralla es buida
    return a_vec.empty();
}

//MODIFICADORS

void Baralla::omple()
{
    //Pre:--; Post: omple la baralla
    const char pals[] = {'P', 'c', 'd', 'T'};//Pals de les cartes
    for (char pal : pals) //Per cada pal
    {
        for (int j = 1; j <= 13; j++)//Per cada valor
        {
            Carta c(j, pal);
            a_vec.push_back(c);
        }
    }
}

void Baralla::intercanvi(Carta& a, Carta& b)
{
    //Pre: a=A i b=B; Post: a=B i b=A
    Carta aux = a;
    a = b;
    b = aux;
}

//AUXILIARS

int Baralla::aleatori(unsigned& x)
{
    //Pre:x = llavor; Post: retorna un nombre pseudoaleatori, actualitza la llavor
    int a = 1103515245;
    int c = 12345;
    int m = 32768;
    x = a*x + c; //Actualitzar llavor
    return (x/32) % m; //Nombre pseudoaleatori
}

void Baralla::barreja(unsigned llavor)
{
//Pre:baralla no buida, Post: barreja una baralla de cartes amb Fisher-Yates amb implementació de Durstenfeld
    for(int i=a_vec.size()-1; i>0; i--)
    {
        int pos = aleatori(llavor)%(1+i);
        intercanvi(a_vec[pos], a_vec[i]);
    }
}

void Baralla::elimina_last()
{
//Pre:baralla no buida; Post: elimina l'ultima carta
    assert(!buida()); // Assegura que la baralla no es buida
    a_vec.pop_back();
}

