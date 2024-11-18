#include "estrutura.h"

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

void iniListaArtigoTem (ListaArtigoTem *l)
{
    l->inicio = NULL;
    l->final = NULL;
}

void iniciaPalavra(Palavra *p)
{
    ListaArtigoTem *novo = malloc(sizeof(ListaArtigoTem));
    iniListaArtigoTem(novo);
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

void resetaRelevancia(Artigo *a)
{
    a->relevancia = 0;
}

void incluiArtigo(ListaArtigos *lista, char titulo[200])
{
    Artigo *novo =  malloc(sizeof(Artigo));
    iniciaArtigo(novo);

    strcpy(novo->titulo, titulo);

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

Palavra *incluirPalavra (ListaPalavras *lista, char palavra[20])
{
    Palavra *novo = malloc(sizeof(Palavra));
    iniciaPalavra(novo);

    strcpy(novo->titulo, palavra);

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->final = novo;
        return novo;
    }

    lista->final->prox = novo;
    lista->final = novo;
    return novo;
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

void imprimirArtigo(Artigo *a)
{
    printf("Titulo: %s\n", a->titulo);
    return;
}

// é passado como paremetro dessa funcao o inicio da lista
void imprimirListaArtigos(Artigo *atual)
{
    if (atual == NULL)
    {
        return;
    }

    imprimirArtigo(atual);

    imprimirListaArtigos(atual->prox);

    return;
}

void iniPalavraGlobal(ListaPalavras lista[26])
{
    int i = 0;

    while (i < 26)
    {
        iniListaPalavra(&lista[i]);
        i++;
    }
    
    return;
}