#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "baralho.h"

int cmp(const void* x, const void* y){
    Carta** xa = (Carta**) x;
    Carta** ya = (Carta**) y;

    if((**xa).valor > (**ya).valor){
        return 1;
    }

    if ((**xa).valor < (**ya).valor){
        return -1;
    }

    else{
        return 0;
    }

}
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

//Remove uma carta do topo do Baralho e decrementa topo
Carta* removeCarta(Baralho *b){
    free(b->c[b->topo]);
    b->topo-=1;
}

//Embaralha. Faz uma permutação aleatória no Baralho
void embaralha(Baralho* b){
     //A ser implementada
     srand((unsigned)time (NULL));
     for(int i = 0; i < b->topo; i++){
        int carta = rand() % b->topo;
        Carta* aux = b->c[i];
        b->c[i] = b->c[carta];
        b->c[carta] = aux;
     }


}

//Ordena o Baralho da menor carta para a maior.
void ordena(Baralho* b){
    qsort(b->c, b->topo, sizeof(Carta*), cmp);
}

//Imprime uma carta
void imprimeCarta(Carta* c){
    printf("(%d, %d)", c->valor, c->naipe);
}

void imprimeBaralho(Baralho* b){
    for (int i = 0; i < b->topo ; i++){
        printf("(%d, %d)", b->c[i]->valor, b->c[i]->naipe);
        if (i == b->topo-1)
            printf("\n");
    }
}
