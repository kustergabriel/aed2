#include <stdio.h>
#include <stdlib.h>


#define TAM_ALFABETO 26

typedef struct trie_nodo {
    struct trie_nodo *chave[TAM_ALFABETO];
    int eh_final_palavra;
} trie_nodo_t;

trie_nodo_t *trie_cria_nodo(void); // cria um novo nó
void trie_insere(trie_nodo_t *raiz, char *chave); // insere uma palavra na trie
int trie_busca(trie_nodo_t *raiz, char *chave); // busca uma palavra na trie
void trie_destroi(trie_nodo_t *raiz); // destroi a trie
int conta_nodos(trie_nodo_t *raiz);
void imprime_todas_chaves(trie_nodo_t *raiz, char *palavra, int nivel);

int main  () {
    char sdhuf[100];
    trie_nodo_t* a = trie_cria_nodo();
    trie_insere (a, "macaco");
    trie_insere (a, "cagao");

   int contador = conta_nodos(a);

    imprime_todas_chaves(a, sdhuf, 0);

    trie_destroi(a);

    return 0;
}

void imprime_todas_chaves(trie_nodo_t *raiz, char *palavra, int nivel) {
    trie_nodo_t *atual = raiz;
    if (raiz == NULL) {
        return;
    }
    if (atual->eh_final_palavra) {
        palavra[nivel] = '\0';
        printf ("%s\n", palavra);   
        }
    for (int i = 0; i < TAM_ALFABETO; i++) {
        if (raiz->chave[i] != NULL) {
            palavra[nivel] = i + 'a';
            imprime_todas_chaves(atual->chave[i], palavra, nivel+1);
        }
    }
}

int conta_nodos(trie_nodo_t *raiz) {
    int contador = 0;
    if (raiz == NULL) {
        printf ("vaziaaa"); 
    trie_nodo_t *atual = raiz;

    for (int i = 0; i <= TAM_ALFABETO; i++) {
        if (atual->chave[i] != NULL) {
            contador += conta_nodos(atual->chave[i]);
        }
    }
    }
    return 1 + contador;
}

trie_nodo_t *trie_cria_nodo(void){
    trie_nodo_t *novo_no = (trie_nodo_t *)malloc(sizeof(trie_nodo_t));
    if(novo_no == NULL){
        fprintf(stderr, "Erro ao alocar memória para um novo nó\n");
        exit(1);
    }
    novo_no->eh_final_palavra = 0;
    for(int i = 0; i < TAM_ALFABETO; i++){
        novo_no->chave[i] = NULL;
    }
    return novo_no;
}

/* insere uma palavra na trie*/
void trie_insere(trie_nodo_t *raiz, char *chave){
    trie_nodo_t *atual = raiz;
    for(int i = 0; chave[i] != '\0'; i++){
        int idx = chave[i] - 'a';
        if(atual->chave[idx] == NULL){
            atual->chave[idx] = trie_cria_nodo();
        }
        atual = atual->chave[idx];
    }
    atual->eh_final_palavra = 1;
} 

/* busca uma palavra na trie */
int trie_busca(trie_nodo_t *raiz, char *chave){
    trie_nodo_t *atual = raiz;
    for(int i = 0; chave[i] != '\0'; i++){
        int idx = chave[i] - 'a'; // calcula o indice da letra
        if(atual->chave[idx] == NULL){
            return 0;
        }
        atual = atual->chave[idx];
    }
    return atual->eh_final_palavra;
}

/* destroi a trie */
void trie_destroi(trie_nodo_t *raiz){
    for(int i = 0; i < TAM_ALFABETO; i++){
        if(raiz->chave[i] != NULL){ // se o nó atual não for nulo
            trie_destroi(raiz->chave[i]);
        }
    }
    free(raiz);
}
