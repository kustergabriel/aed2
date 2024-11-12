#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* arv_cria();
Arv* arv_insere(Arv* a, int v);
Arv* arv_libera(Arv* a);
void arv_imprime(Arv* a);
Arv* arv_busca_iterativa(Arv* a, int v);
Arv* arv_busca_recursiva(Arv* a, int v);

#endif