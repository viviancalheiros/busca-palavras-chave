#include "estrutura.h"
#include "leitura.h"

void incluiArtigo(ListaArtigos *lista, char titulo[200], char link[300])
{
    Artigo *novo =  malloc(sizeof(Artigo));
    iniciaArtigo(novo);

    strcpy(novo->titulo, titulo);
    strcpy(novo->link, link);

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->final = novo;
        return;
    }

    lista->final->prox = novo;
    lista->final = novo;
    return;
}

void incluirPalavra (ListaPalavras *lista, char palavra[20])
{
    Palavra *novo = malloc(sizeof(Palavra));
    iniciaPalavra(novo);

    strcpy(novo->titulo, palavra);

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->final = novo;
        return;
    }

    lista->final->prox = novo;
    lista->final = novo;
    return;
}

void incluirArtigoTem (ListaArtigoTem *lista, Artigo *end_artigo)
{
    ArtigoTem *novo = malloc(sizeof(ArtigoTem));
    iniArtigoTem(novo);

    novo->endArtigo = end_artigo;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->final = novo;
        return;
    }

    lista->final->prox = novo;
    lista->final = novo;
    return;
}

void insereFim(Artigo **a, char nome[200], char url[300]) {
    Artigo *aux, *novo = malloc(sizeof(Artigo));
    if(novo) {
        strcpy(novo->titulo, nome);
        strcpy(novo->link, url);
        novo->prox = NULL;
        if(*a == NULL) {
            *a = novo;
        } else {
            aux = *a;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } else {
        printf("erro ao alocar memoria!\n");
        return;
    }
}

void lerArtigos(Artigo *lista) {
    FILE *arq;
    arq = fopen("artigos.txt", "r");
    char nome[200];
    char url[300];
    for(int i = 0; i < 20; i++) {
        fgets(nome, 200, arq);
        fgets(url, 300, arq);
        insereFim(&lista, nome, url);
    }
    fclose(arq);
}

int ehPalavraChave(char palavra[20], char insignificantes[COL][LIN]) {
    for(int i = 0; i < COL; i++) {
        if(strcmp(palavra, insignificantes[i]) == 0){
            return 0;
        }
    }
    return 1;
}

void separaEntrada(char palavras[300], char insignificantes[COL][LIN]) {
    int indice = 0;
    char aux[20];
    for(int i = 0; palavras[i] != '\0'; i++) {
        if(palavras[i] != ' ') {
            aux[indice] = palavras[i];
            indice++;
            if(palavras[i+1] == '\0') {
                aux[indice] = '\0';
                if(ehPalavraChave(aux, insignificantes) == 1) {
                    printf("%s\n", aux);
                    
                }
            }
        } else {
            aux[indice] = '\0';
            if(ehPalavraChave(aux, insignificantes) == 1) {
                printf("%s\n", aux);
                
            }
            indice = 0;
            aux[indice] = '\0';
        }
    }
}