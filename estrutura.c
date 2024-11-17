#include "estrutura.h"

void iniciaArtigo(Artigo *a)
{
    a->relevancia = 0;
    a->prox = NULL;
}

void iniArtigoTem(ArtigoTem *a)
{
    a->endArtigo = NULL;
    a->prox = NULL;
}

void iniciaPalavra(Palavra *p)
{
    ArtigoTem *novo = (ArtigoTem*)malloc(sizeof(ArtigoTem));
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

void imprimir(Artigo **lista) {
    Artigo *aux = malloc(sizeof(Artigo));
    for(aux = *lista; aux != NULL; aux = aux->prox){
        printf("%s", aux->titulo);
        printf("%s", aux->link);
    }
}
