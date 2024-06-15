////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                 **  PRACTICA FINAL MTP2  **                                        //
//----------------------------------------------------------------------------------------------------//
//  Autora: Alba Sala Solé  || Universitat de Girona || GEB || Darrera modificació: 02/06/2024 14:50  //
//----------------------------------------------------------------------------------------------------//
//                                       JOC DEL SOLITARI                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////////

//Lliberies
#include <iostream>
#include "Joc.h"

using namespace std;

void menu()
{
    //Pre:--; Post: mostra el menu d'opcions
    cout << "MENU" << endl << "1: OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl << "2: POSAR UNA CARTA (MA->TAULER)" << endl;
    cout << "3: POSAR UNA CARTA (MA->PILA)" << endl << "4: MOURE UNA CARTA (TAULER->TAULER)" << endl << "5: MOURE UNA CARTA (TAULER->PILA)" << endl;
    cout << "6: RECUPERAR UNA CARTA (PILA->TAULER)" << endl << "E: ESPIAR EL TAULER" << endl << "M: MOSTRAR EL MENU" << endl;
    cout << "A: ABANDONAR LA PARTIDA" << endl;
}

char llegeix_opcio()
{
    //Pre:--; Post: retorna l'opció
    char op;
    cout << "OPCIO:" << endl;
    cin >> op;
    return op;
}

void obre_carta(Joc & j, bool guanyat) //OPCIO 1
{
//Pre:--;
//Post: agafa la carta del cim de la mà i la posa a sobre de la pila de descartades.
//Si la mà no té cartes, en seleccionar aquesta opció es reciclen totes les de la pila
    j.obrir_carta();
    j.mostra(guanyat);
}

void posa_carta_tauler(Joc& j, bool guanyat) //OPCIO 2
{
//Pre:pila de descartades no buida
//Post:agafa la darrera carta oberta de la mà i la posa al tauler
    j.posar_carta_tauler();
    j.mostra(guanyat);
}

void posa_carta_pila(Joc& j, bool& guanyat) //OPCIO 3
{
//Pre:--;
//Post:agafa la darrera carta oberta de la mà i la posa a la pila
    j.posar_carta_ma_pila();
    guanyat = j.joc_guanyat();
    j.mostra(guanyat);
}

void moure_tauler_tauler(Joc& j, bool guanyat) //OPCIO 4
{
//Pre:--;
//Post:agafa la darrera carta oberta de la mà i la posa a la pila
    j.mou_tauler_tauler();
    j.mostra(guanyat);
}

void moure_tauler_pila(Joc& j, bool& guanyat)  //OPCIO 5
{
//Pre:--;
//Post:agafa la darrera carta oberta d’una columna i es posa a la pila corresponent de les piles dels pals
    j.mou_tauler_pila();
    guanyat = j.joc_guanyat();
    j.mostra(guanyat);
}

void recuperar_carta(Joc& j, bool guanyat)  //OPCIO 6
{
//Pre:--;
//Post:agafa la carta d'una de les piles i la torna al joc
    j.recupera_carta();
    j.mostra(guanyat);
}

void espiar(const Joc& j, bool guanyat)
{
//Pre:--;
//Post: mostra el tauler amb totes les cartes visibles
    j.espia_tauler(guanyat);
}

int main()
{
    //Inicialitzar la baralla, omplir-la i repartir-la
    Baralla baralla;
    baralla.omple();
    Joc j(baralla);
    bool guanyat = false;
    j.mostra(guanyat);
    //Mostra menu
    menu();
    char opcio = llegeix_opcio();
    //Començar el joc
    while(opcio!='A' and !guanyat)
    {
        if(opcio == '1')
        {
            //OBRIR UNA CARTA (O TORNAR A COMENCAR)
            obre_carta(j,guanyat);
        }
        else if(opcio == '2')
        {
            //POSAR UNA CARTA (MA->TAULER)
            posa_carta_tauler(j,guanyat);
        }
        else if(opcio == '3')
        {
            //POSAR UNA CARTA (MA->PILA)
            posa_carta_pila(j,guanyat);
        }
        else if(opcio == '4')
        {
            //MOURE UNA CARTA (TAULER->TAULER)
            moure_tauler_tauler(j,guanyat);
        }
        else if(opcio == '5')
        {
            //MOURE UNA CARTA (TAULER->PILA)
            moure_tauler_pila(j,guanyat);
        }
        else if(opcio == '6')
        {
            //RECUPERAR UNA CARTA (PILA->TAULER)
            recuperar_carta(j,guanyat);
        }
        else if(opcio == 'E')
        {
            espiar(j,guanyat);
        }
        else if(opcio == 'M')
        {
            menu();
        }
        else
        {
            cout << "OPCIO NO DEFINIDA a" << endl;
            menu();
            j.mostra(guanyat);
        }
        if (not guanyat) opcio = llegeix_opcio();
    }
    if(opcio == 'A') cout << "HAS ABANDONAT LA PARTIDA!" << endl;
    if(guanyat) cout << "HAS GUANYAT LA PARTIDA!" << endl;
    return 0;
}
