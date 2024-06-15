//IMPLEMENTACIO de la classe TAULER

#include "Tauler.h"
#include <iostream>
#include "Baralla.h"
#include <vector>
#include <cassert>
using namespace std;

//CONSTRUCTOR
Tauler::Tauler()
{
//Pre:cert; Post: tauler buit
    inicialitza_caps_col();//Columnes buides
}

//AUXILIAR
void Tauler::inicialitza_caps_col()
{
    //Pre:--; Post: omple el vector de capacitats amb 0's
    for (int i = 0; i < NC; ++i)
    {
        caps_col[i] = 0; //Capacitats de les columnes
    }
}

//MODIFICADORS

void Tauler::omple(Baralla& b)
{
    //Pre:tauler buit, b no buida; Post: s'omple el tauler amb les cartes de b
    assert(!b.buida()); //Terminacio del programa si la baralla es buida

    for (int i = 0; i < NC; ++i)
    {
        caps_col[i] = i + 1;//primera col capacitat=1, segona col capacitat=2...
        a_t.push_back(vector<Carta>(caps_col[i]));//Afegir columna al tauler
        for (int j = 0; j < caps_col[i]; ++j)
        {
            a_t[i][j] = b.last();//repartir des del final de la baralla
            b.elimina_last();//treu de la baralla la carta repartida
            if (j == caps_col[i] - 1) a_t[i][j].fes_visible();//fes visible l'ultima carta de cada columna
        }
    }
}

void Tauler::posar_carta(int col, const Carta& c)
{
    //Pre:col >= 0 i col < nombre de columnes; Post:c es posa al cim de la columna col
    assert(col >= 0 and col < NC);//Terminació del programa si l'index no es valid

    a_t[col].push_back(c);//Afegir carta
    caps_col[col]++;//Actualitzar capacitat de la columna
}

void Tauler::treure_carta(int col)
{
    //Pre:col>=0 col<NC, columna no buida; Post: treu la carta del cim de la columna
    assert(col >= 0 and col < NC and !a_t[col].empty());//Assegurar que l'index es vàlid i que la columna no es buida

    a_t[col].pop_back();//Treure carta del final de la columna
    caps_col[col]--;
}

void Tauler::mou_cartes_tauler(int f,int c)
{
    //Pre:tauler omplert, 0<=f,c, c<NC; Post:Mou les cartes dins del tauler
    if (f >= 0 and (c >= 0 and c < NC) and a_t[c][f].es_visible())
    {

        int col_f;
        cout << "ENTRA LA COLUMNA DESTI:" << endl;
        cin >> col_f;
        col_f--; //Ajustar per facilitar indexacio a la taula
        Carta c_moure = a_t[c][f];

        if ((col_f >= 0 and col_f < NC) and ((!a_t[col_f].empty() and c_moure.casen(a_t[col_f].back())) or (a_t[col_f].empty() and c_moure.valor() == 13)))
        {

            vector<Carta> v_aux; //Vector auxiliar per copiar-hi les cartes a moure
            int n_aux = caps_col[c] - f; //Nombre de cartes a moure

            for (int i = 0; i < n_aux; i++)
            {
                v_aux.push_back(a_t[c][f + i]); //Omplir vector auxiliar amb les cartes que cal moure
            }

            for (int i = 0; i < n_aux; i++)
            {
                treure_carta(c);//Treure les cartes de la posicio inicial
                posar_carta(col_f, v_aux[i]);//Posar-les a la columna final
            }

            if (!cim_col(c).es_visible() and !a_t[c].empty())
            {
                a_t[c].back().fes_visible();//Si el cim de la col inicial ha quedat no visible fer-lo visible
            }
        }
        else
        {
            cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col_f + 1 << endl;
        }
    }
    else
    {
        cout << "LA CARTA NO ES POT MOURE" << endl;
    }
}

void Tauler::fes_darrera_visible(int col)
{
//Pre:columna no buida, 0<=col<NC; Post:fa l'ultima carta de la columna visible
    assert(!a_t[col].empty());
    a_t[col].back().fes_visible();
}

//CONSULTORS
void Tauler::mostra() const
{
    //Pre:cert; Post: mostra el tauler
    //Determina l'altura maxima:
    int altura_max = 0;
    for (int i = 0; i < NC; ++i)
    {
        if (caps_col[i] > altura_max)
        {
            altura_max = caps_col[i];
        }
    }

    //Mostra tauler fins a l'altura màxima:
    for (int i = 0; i < altura_max; ++i)
    {
        for (int j = 0; j < NC; ++j)
        {
            if (caps_col[j] > i)
            {
                a_t[j][i].mostra();
            }
            else
            {
                cout << "   ";
            }
        }
        cout << "f" << i + 1 << endl;
    }
}

Carta Tauler::cim_col(int col) const
{
    //Pre:col>=0, col<NC, columna no buida; Post: retorna la carta al cim de la columna
    return a_t[col].back();
}

bool Tauler::col_buida(int col) const
{
//Pre:--; Post:cert si la columna es buida
    return a_t[col].empty();
}

void Tauler::espia() const
{
//Pre:--; Post: mostra totes les cartes del tauler com a visibles
    vector<vector<Carta> > tauler_aux; //vector de vectors auxiliar, per no modificar el tauler
    Carta copia;
    for(int i = 0; i< NC; i++)
    {
        tauler_aux.push_back(vector <Carta> (caps_col[i]));//Quan hagi copiat una columna afegeix-la al vector de vectors
        for(int j=0; j<caps_col[i]; j++)
        {
            copia = a_t[i][j]; //copia és una copia de la carta del tauler
            copia.fes_visible();
            tauler_aux[i][j] = copia;//insereix la carta feta visible al tauler auxiliar
        }
    }
//Per mostrar la copia modificada:
//Buscar la capacitat maxima
    int altura_max = 0;
    for (int i = 0; i < NC; ++i)
    {
        if (caps_col[i] > altura_max)
        {
            altura_max = caps_col[i];
        }
    }

//Mostra la copia fins a l'altura màxima:
    for (int i = 0; i < altura_max; ++i)
    {
        for (int j = 0; j < NC; ++j)
        {
            if (caps_col[j] > i)
            {
                tauler_aux[j][i].mostra();
            }
            else
            {
                cout << "   ";
            }
        }
        cout << "f" << i + 1 << endl;
    }
}
