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
