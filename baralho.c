#include <stdio.h>
#include <stdlib.h>
#include "baralho.h"

//Cria uma carta
Carta* newCarta(int valor, int naipe){
    Carta* Aux = (Carta*) malloc (sizeof(Carta));
    Aux->valor = valor;
    Aux->naipe = naipe;
    return Aux;
}

//Cria um novo Baralho com 0 cartas
Baralho* newBaralho(){
    Baralho* aux = (Baralho*) malloc (sizeof(Baralho));
    aux->topo = 0;
    return aux;
}

//Adiciona uma carta existente dentro de um baralho
void addCarta(Baralho *b, Carta *c) {
    b->c[b->topo] = c;
    b->topo += 1;
}

//Remove uma carta do topo do Baralho
Carta* removeCarta(Baralho *b){
    free(b->c[b->topo]);
    b->topo-=1;
}
