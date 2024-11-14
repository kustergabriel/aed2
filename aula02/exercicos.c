#include <stdio.h>


#define TAM_ALFABETO 26

typedef struct trie_nodo {
    struct trie_nodo *chave[TAM_ALFABETO];
    int eh_final_palavra;
} trie_nodo_t;

trie_nodo_t *trie_cria_nodo(void); // cria um novo nó
void trie_insere(trie_nodo_t *raiz, char *chave); // insere uma palavra na trie
int trie_busca(trie_nodo_t *raiz, char *chave); // busca uma palavra na trie
void trie_destroi(trie_nodo_t *raiz); // destroi a trie
int buscar_palavra (trie_nodo_t *raiz,char *chave);

int main  () {

    trie_nodo_t* a = trie_cria_nodo();
    trie_insere (a, "macaco");
    if (buscar_palavra(a, "macaco")) {
        printf("A palavra 'macaco' foi encontrada.\n");
    } else {
        printf("A palavra 'macaco' não foi encontrada.\n");
    }

    trie_destroi(a);

    return 0;
}

// minha busca na trie
int buscar_palavra (trie_nodo_t *raiz,char *chave) {
    trie_nodo_t *atual = raiz;
    for (int i = 0; chave[i] != '\0'; i++) {
        int indice = chave [i] - 'a'; // NAO ENTENDI ESSA PARTE DE JEITO MANEIRA
        if (atual->chave[indice] == NULL) {
            return 0;
        }
        atual = atual->chave[indice];
    }
    return atual->eh_final_palavra;
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
