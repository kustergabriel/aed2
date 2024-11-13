#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;


Arv* arv_cria();
Arv* arv_insere(Arv* a, int v);
void arv_libera(Arv* a);
void arv_imprime(Arv* a);
Arv* arv_busca_iterativa(Arv* a, int v);
Arv* arv_busca_recursiva(Arv* a, int v);
Arv* menor_valor(Arv* a);
int maiores_que_x(Arv* a, int x);
int maior_valor(Arv* a);
int verifica_abb(Arv* a);

int main () {

    Arv* a = arv_cria();
    a = arv_insere(a,8);
    a = arv_insere(a,2);
    a = arv_insere(a,3);

    //menor_valor(a); // ex01
    //printf ("\n");
    //maiores_que_x(a, 5); // ex02
    //printf ("\n");
    //maior_valor (a); // ex04
    //printf ("\n");
    verifica_abb(a);

    return 0;
}

Arv* menor_valor(Arv* a) { //ex01
    if (a == NULL) {
        printf ("Arvore nula!\n");
        return NULL;
    }
        if (a -> esq != NULL) {
            a = menor_valor(a-> esq); 
        }
            else {
            printf ("%d", a->info);
            }
}

int maiores_que_x(Arv* a, int x) { //ex02
    int valores = 0;

    if (a == NULL) {
        printf ("Arvore esta vazia!\n");
        return 0;
    }
    
    if (a -> info > x) {
      return 1;  
    } 
    valores = valores + maiores_que_x(a->esq,x);
    valores = valores + maiores_que_x(a->dir,x);
    return valores;
}

int maior_valor(Arv* a) { //ex04
    if (a == NULL) {
        return 0;
    }
        if (a->dir != NULL) {
            a = maior_valor (a->dir);
        }
        else {
            printf ("%d", a->info);
        }
}

int verifica_abb(Arv* a) { //ex05
    

}





Arv* arv_insere(Arv* a, int v) {
    if (a == NULL) {
        a = (Arv*) malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    } else if (v < a->info) {
        a->esq = arv_insere(a->esq, v);
    } else {
        a->dir = arv_insere(a->dir, v);
    }
    return a;
}

//libera a arvore binaria de busca
void arv_libera(Arv* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}

Arv* arv_busca_recursiva(Arv* r, int v) {
    if (r == NULL) {
        return NULL;
    } else if (r->info > v) {
        return arv_busca_recursiva(r->esq, v);
    } else if (r->info < v) {
        return arv_busca_recursiva(r->dir, v);
    } else {
        return r;
    }
}

Arv* arv_busca_iterativa(Arv* r, int v) {
    while (r != NULL) {
        if (r->info > v) {
            r = r->esq;
        } else if (r->info < v) {
            r = r->dir;
        } else {
            return r;
        }
    }
    return NULL;
}

Arv* arv_cria() {
    return NULL;
}