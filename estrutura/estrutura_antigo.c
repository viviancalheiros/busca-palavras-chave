#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Implemente um sistema de busca de documentos na internet. No caso, você deve considerar a palavra chave e as palavras que 
compõem o nome do documento. No caso você receberá vários artigos, seu endereço, nome e palavra chaves, e deve responder a uma 
pergunta do usuário sobre um determinando assunto listando todos documentos que atendem ao mesmo, os documentos de seu trabalho 
devem ser os artigos da https://sol.sbc.org.br/index.php/bracis, https://sol.sbc.org.br/index.php/bsb, https://sol.sbc.org.br/index.php/cbie 
e https://sol.sbc.org.br/index.php/cbsoft*/

typedef struct Artigo
{
    char titulo[200];
    char link[300];
    int relevancia;
    struct Artigo *prox;
} Artigo;

typedef struct Palavra
{
    char titulo[20];
    ArtigoTem *listaTem;
    struct Palavra *prox;
} Palavra;

typedef struct ArtigoTem
{
    Artigo *endArtigo;
    struct ArtigoTem *prox;;
} ArtigoTem;

typedef struct ListaArtigos
{
    Artigo *inicio;
    Artigo *final;
} ListaArtigos;

typedef struct ListaPalavras
{
    Palavra *inicio;
    Palavra *final;
} ListaPalavras;

typedef struct ListaArtigoTem
{
    ArtigoTem *inicio;
    ArtigoTem *final;
} ListaArtigoTem;

void iniciaArtigo(Artigo *a)
{
    a->relevancia = 0;
    a->prox = NULL;
}

void iniArtigoTem(ArtigoTem * a)
{
    a->endArtigo = NULL;
    a->prox = NULL;
}

void iniciaPalavra(Palavra *p)
{
    ListaArtigoTem *novo = mallocc(sizeof(ArtigoTem));
    iniArtigoTem(novo);
    p->listaTem = novo;
    p->prox = NULL;
}

void iniListaArtigo(ListaArtigos *l)
{
    l->inicio = NULL;
    l->final = NULL;
}

void iniListaPalavra(ListaPalavras *l)
{
    l->inicio = NULL;
    l->final = NULL;
}

void iniListaArtigoTem (ListaPalavras *l)
{
    l->inicio = NULL;
    l->final = NULL;
}

void resetaRelevancia(Artigo *a)
{
    a->relevancia = 0;
}

void incluiArtigo(ListaArtigos *lista, char titulo[200], char link[300] )
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

void imprimir(Artigo **lista) {
    Artigo *aux = malloc(sizeof(Artigo));
    for(aux = *lista; aux != NULL; aux = aux->prox){
        printf("%s", aux->titulo);
        printf("%s", aux->link);
    }
}

int main(){
    Artigo *lista = malloc(sizeof(Artigo));
    iniciaLista(lista);
    lerArtigos(lista);
    imprimir(&lista);
    char palavras[300];
    fgets(palavras, 300, stdin);

    return 0;
} 