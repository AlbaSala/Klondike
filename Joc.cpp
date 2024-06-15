//IMPLEMENTACIO de la classe JOC

#include "Joc.h"
#include <iostream>
#include "Baralla.h"
#include "Tauler.h"
#include "PilaCarta.h"
#include <cassert>
using namespace std;

//CONSTRUCTORS

Joc::Joc(Baralla& baralla)
{
//Pre:baralla no esta barrejada; Post:el joc està preparat per iniciar la partida
    int l;
    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> l;
    unsigned llavor = abs(l);
    baralla.barreja(llavor);
    a_tauler.omple(baralla);//omple amb la baralla barrejada
    a_ma.recicla(baralla);//guardar les cartes restants a la mà
}

//CONSULTORS

void Joc::mostra(bool guanyat) const
{
//Pre:--; Post:mostra l'estat actual del joc
    cout << "ESTAT DEL JOC" << endl;
    for(int i = 0; i<N_PALS; i++) a_pals[i].mostra();
    cout << "   ";
    a_ma.mostra();
    a_descartades.mostra();
    cout << endl << "c1 c2 c3 c4 c5 c6 c7 " << endl;
    a_tauler.mostra();
    if(!guanyat)
    {
        cout << "JOC EN CURS" << endl;
    }
    else
    {
        cout << "JOC ACABAT" << endl;
    }
}

void Joc::espia_tauler(bool guanyat) const
{
//Pre:--; Post: mostra el tauler amb totes les cartes visibles
    cout << "ESTAT DEL JOC" << endl;
    for(int i = 0; i<N_PALS; i++) a_pals[i].mostra();
    cout << "   ";
    a_ma.mostra();
    a_descartades.mostra();
    cout << endl << "c1 c2 c3 c4 c5 c6 c7 " << endl;
    a_tauler.espia();
    if(!guanyat)
    {
        cout << "JOC EN CURS" << endl;
    }
    else
    {
        cout << "JOC ACABAT" << endl;
    }
}

bool Joc::joc_guanyat() const
{
//Pre:--; Post:retorna cert si totes les piles de pals estan plenes
    Carta cim_pila;
    bool pals_plens = true;
    int i = 0;
    while(i < N_PALS and pals_plens)
    {
        if(a_pals[i].buida() or (!a_pals[i].buida() and (a_pals[i].cim()).valor() != 13)) pals_plens = false;
        i++;
    }
    return pals_plens;
}

//MODIFICADORS
void Joc::obrir_carta()
{
//Pre:--; Post: obre carta
    if(!a_ma.buida())
    {
        Carta c = a_ma.cim();
        a_ma.desempila();
        c.fes_visible();
        a_descartades.empila(c);
    }
    else
    {
        //si la ma està buida recicla descartades
        a_ma.recicla_pila(a_descartades);
    }
}

void Joc::posar_carta_tauler()
{
//Posa l'ultima carta oberta al tauler
    if(not a_descartades.buida())
    {
        //si la pila no esta buida
        int col;
        cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
        cin >> col;
        Carta aux = a_descartades.cim();
        if(0 < col and col <= Tauler::NC)
        {
            if(!a_tauler.col_buida(col-1) and aux.casen(a_tauler.cim_col(col-1)))
            {
                a_descartades.desempila();
                a_tauler.posar_carta(col-1,aux);
            }
            else if(a_tauler.col_buida(col-1) and aux.valor() == 13)
            {
                a_descartades.desempila();
                a_tauler.posar_carta(col-1,aux);
            }
            else
            {
                //si no es pot posar perque no casen
                cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
            }
        }
        else
        {
            cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
        }
    }
    else
    {
        //si la pila esta buida
        cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    }
}

void Joc::posar_carta_ma_pila()
{
//Posa l'ultima carta oberta a la pila
    if(not a_descartades.buida())
    {
        Carta carta_ma = a_descartades.cim();
        Carta carta_pal;
        if(carta_ma.pal() == 'P')
        {
            //PIQUES
            if(not a_pals[0].buida())
            {
                carta_pal = a_pals[0].cim();
                if(carta_ma.valor() == carta_pal.valor()+1)
                {
                    a_pals[0].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
            else
            {
                if(carta_ma.valor()==1)
                {
                    a_pals[0].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
        }
        else if(carta_ma.pal() == 'c')
        {
            //CORS
            if(not a_pals[1].buida())
            {
                carta_pal = a_pals[1].cim();
                if(carta_ma.valor() == carta_pal.valor()+1)
                {
                    a_pals[1].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
            else
            {
                if(carta_ma.valor()==1)
                {
                    a_pals[1].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
        }
        else if(carta_ma.pal() == 'd')
        {
            //DIAMANTS
            if(not a_pals[2].buida())
            {
                carta_pal = a_pals[2].cim();
                if(carta_ma.valor() == carta_pal.valor()+1)
                {
                    a_pals[2].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
            else
            {
                if(carta_ma.valor()==1)
                {
                    a_pals[2].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
        }
        else   //pal == 'T'
        {
            //TREVOLS
            if(not a_pals[3].buida())
            {
                carta_pal = a_pals[3].cim();
                if(carta_ma.valor() == carta_pal.valor()+1)
                {
                    a_pals[3].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
            else
            {
                if(carta_ma.valor()==1)
                {
                    a_pals[3].empila(carta_ma);
                    a_descartades.desempila();
                }
                else cout << "LA CARTA NO ES POT APILAR" << endl;
            }
        }
    }
    else
    {
        cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    }
}

void Joc::mou_tauler_tauler()
{
//Pre:--; Post: Mou carta Tauler -> Tauler
    int fil_origen, col_origen;
    cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:" << endl;
    cin >> col_origen >> fil_origen;
    if (col_origen > 0 and col_origen <= Tauler::NC and fil_origen > 0)
    {
        a_tauler.mou_cartes_tauler(fil_origen - 1, col_origen - 1);
    }
    else
    {
        cout << "LA CARTA NO ES POT MOURE" << endl;
    }
}

void Joc::mou_tauler_pila()
{
//Pre:--; Post: Mou carta tauler -> pila
    int col_origen;
    cout << "ENTRA LA COLUMNA ORIGEN:" << endl;
    cin >> col_origen;
    col_origen--; //Per adaptar incici a 0
    if(0 <= col_origen && col_origen < Tauler::NC)
    {
        if(not a_tauler.col_buida(col_origen))
        {
            Carta carta_tauler = a_tauler.cim_col(col_origen);
            Carta carta_pal;
            if(carta_tauler.pal() == 'P')
            {
                //PIQUES
                if(not a_pals[0].buida())
                {
                    carta_pal = a_pals[0].cim();
                    if(carta_tauler.valor() == carta_pal.valor()+1)
                    {
                        a_pals[0].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
                else if(a_pals[0].buida())
                {
                    if(carta_tauler.valor()==1)
                    {
                        a_pals[0].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
            }
            else if(carta_tauler.pal() == 'c')
            {
                //CORS
                if(not a_pals[1].buida())
                {
                    carta_pal = a_pals[1].cim();
                    if(carta_tauler.valor() == carta_pal.valor()+1)
                    {
                        a_pals[1].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
                else if(a_pals[1].buida())
                {
                    if(carta_tauler.valor()==1)
                    {
                        a_pals[1].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
            }
            else if(carta_tauler.pal() == 'd')
            {
                //DIAMANTS
                if(not a_pals[2].buida())
                {
                    carta_pal = a_pals[2].cim();
                    if(carta_tauler.valor() == carta_pal.valor()+1)
                    {
                        a_pals[2].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
                else if(a_pals[2].buida())
                {
                    if(carta_tauler.valor()==1)
                    {
                        a_pals[2].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
            }
            else   //pal == 'T'
            {
                //TREVOLS
                if(not a_pals[3].buida())
                {
                    carta_pal = a_pals[3].cim();
                    if(carta_tauler.valor() == carta_pal.valor()+1)
                    {
                        a_pals[3].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
                else if(a_pals[3].buida())
                {
                    if(carta_tauler.valor()==1)
                    {
                        a_pals[3].empila(carta_tauler);
                        a_tauler.treure_carta(col_origen);
                        if (!a_tauler.cim_col(col_origen).es_visible() && !a_tauler.col_buida(col_origen))
                        {
                            a_tauler.fes_darrera_visible(col_origen);
                        }
                    }
                    else cout << "LA CARTA NO ES POT APILAR" << endl;
                }
            }
        }
        else
        {
            cout << "NO HI HA CAP CARTA PER EMPILAR" << endl;
        }
    }
    else
    {
        cout << "COLUMNA NO VALIDA" << endl;
    }
}

void Joc::recupera_carta()
{
//recupera la carta d'una pila i la torna al joc
    int pila_origen;
    cout << "ENTRA LA PILA:" << endl; //1: piques, 2: cors, 3: diamants i 4: trèvols
    cin >> pila_origen;
    pila_origen--; //Ajustar a inici 0
    if(0 <= pila_origen && pila_origen < N_PALS && !a_pals[pila_origen].buida())
    {
        int col_desti;
        cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
        cin >> col_desti;
        col_desti--; //Ajustar a inici 0
        Carta carta_pila = a_pals[pila_origen].cim();
        Carta carta_tauler = a_tauler.cim_col(col_desti);
        if((!a_tauler.col_buida(col_desti) and carta_pila.casen(carta_tauler)) or (a_tauler.col_buida(col_desti) and carta_pila.valor()== 13))
        {
            a_pals[pila_origen].desempila();
            a_tauler.posar_carta(col_desti,carta_pila);
        }
        else
        {
            cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col_desti+1 << endl;
        }
    }
    else
    {
        cout << "A LA PILA NO HI HA CAP CARTA PER RECUPERAR" << endl;
    }
}
