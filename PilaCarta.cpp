//IMPLEMENTACIO de la classe PILACARTA

#include "PilaCarta.h"
#include "Carta.h"
#include <iostream>
#include <cassert>
using namespace std;

//CONSTRUCTORS I DESTRUCTOR

PilaCartes::PilaCartes()
{
    //Pre:--; Post:pila de cartes buida
    a_cim= NULL;
}

PilaCartes::PilaCartes(const PilaCartes& o)
{
    //Pre:--;Post: aquesta pila és una copia de o
    a_cim= NULL;
    copia(o);
}

PilaCartes::~PilaCartes()
{
    // Pre: --; Post: memoria alliberada (inclosa la dinamica)
    allibera();
}

//CONSULTORS

bool PilaCartes::buida() const
{
    // Pre: -- ; Post: retorna cert si la pila es buida; fals altrament
    return a_cim==NULL;
}

Carta PilaCartes::cim() const
{
    // Pre: pila no buida; Post: retorna el valor del cim de la pila
    assert(!buida() && "Atencio: pila buida"); // Terminació del programa si es vol retornar el cim d'una pila buida
    return a_cim->valor;
}

void PilaCartes::mostra() const
{
//Pre:--; Post: mostra el cim de la pila
    if(not buida())
    {
        Carta c = cim();
        c.mostra();
    }
    else cout << "   ";
}

//MODIFICADORS

void PilaCartes::empila(const Carta& c)
{
    // Pre: --; Post: ha afegit c a dalt de la pila
    Node* nou= new Node;
    nou->valor= c;
    nou->seg= a_cim;
    a_cim= nou;
}

void PilaCartes::desempila()
{
    // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
    assert(!buida());
    Node* aux= a_cim;
    a_cim= a_cim->seg;
    delete aux;
}

void PilaCartes::recicla(Baralla& c)
{
//Pre:c no buida;Post: la pila actual es resultat de capgirar la baralla
    while (!c.buida())
    {
        empila(c.last());
        c.elimina_last();
    }
}

void PilaCartes::recicla_pila(PilaCartes& b)
{
//la pila actual és resultat de reciclar b
    while (!b.buida())
    {
        Carta aux = b.cim();
        aux.fes_no_visible();
        b.desempila();
        empila(aux);
    }
}

//OPERADORS

PilaCartes& PilaCartes::operator=(const PilaCartes& o)
{
    //Pre:--;Post: pila actual es copia de la pila o i la seva mem˜ria dinamica ha estat previament alliberada
    if (this != &o)
    {
        allibera();
        copia(o);
    }
    return *this;
}

// METODES PRIVATS

void PilaCartes::copia(const PilaCartes& o)
{
    // Pre: pila buida; Post: pila actual es copia de la pila o
    if(!o.buida())
    {
        Node *p, *q, *aux;
        p = new Node;
        a_cim = p;
        aux = o.a_cim;
        p->valor = aux->valor;
        p->seg = NULL;
        q = p;
        while (aux->seg!=NULL)
        {
            aux = aux->seg;
            p = new Node;
            q->seg = p;
            p->valor = aux->valor;
            p->seg = NULL;
            q = p;
        }
    }
}

void PilaCartes::allibera()
{
    // Pre: --; Post: memoria dinamica alliberada
    while (!buida())
    {
        Node* aux= a_cim;
        a_cim= a_cim->seg;
        delete aux;
    }
}
