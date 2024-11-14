#include "trie.h"

/* cria um novo nó */
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
