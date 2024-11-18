#include "estrutura.h"
#include "leitura.h"
#include "inserirPalavraGlobal.h"

void insereFim(Artigo **a, char nome[200]) {
    Artigo *aux, *novo = malloc(sizeof(Artigo));
    if(novo) {
        strcpy(novo->titulo, nome);
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

int ehPalavraChave(char palavra[20], char insignificantes[COL][LIN]) {
    for(int i = 0; i < COL; i++) {
        if(strcmp(palavra, insignificantes[i]) == 0){
            return 0;
        }
    }
    return 1;
}

void palavrasDoTitulo(char palavras[300], char insignificantes[COL][LIN], ListaPalavras alfabeto[26], Artigo *a) {
    //separa as palavras do titulo
    int indice = 0;
    char aux[20];
    for(int i = 0; palavras[i] != '\0'; i++) {
        if(palavras[i] != ' ') {
            aux[indice] = palavras[i];
            indice++;
            if(palavras[i+1] == '\0') {
                aux[indice] = '\0';
                if(ehPalavraChave(aux, insignificantes) == 1) {
                    //coloca aux em palavras
                }
            }
        } else {
            aux[indice] = '\0';
            if(ehPalavraChave(aux, insignificantes) == 1) {

            }
            indice = 0;
            aux[indice] = '\0';
        }
    }
}

void lerArtigos(Artigo *a, char insignificantes[COL][LIN], ListaPalavras alfabeto[26]) {
    FILE *arq;
    arq = fopen("semlink.txt", "r");
    char nome[200];
    char url[300];
    for(int i = 0; i < 20; i++) {
        fgets(nome, 200, arq);
        nome[strcspn(nome, "\n")] = '\0';
        palavrasDoTitulo(strlwr(nome), insignificantes, alfabeto, a);
        insereFim(&a, nome);
    }
    fclose(arq);
}

void separaEntrada(char palavras[300], char insignificantes[COL][LIN]) {
    //apenas p/usuario
    int indice = 0;
    char aux[20];
    for(int i = 0; palavras[i] != '\0'; i++) {
        if(palavras[i] != ' ') {
            aux[indice] = palavras[i];
            indice++;
            if(palavras[i+1] == '\0') {
                aux[indice] = '\0';
                if(ehPalavraChave(aux, insignificantes) == 1) {
                    
                }
            }
        } else {
            aux[indice] = '\0';
            if(ehPalavraChave(aux, insignificantes) == 1) {
                
            }
            indice = 0;
            aux[indice] = '\0';
        }
    }
}