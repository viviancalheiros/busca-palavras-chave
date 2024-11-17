#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Artigo
{
    char titulo[200];
    char link[300];
    int relevancia;
    struct Artigo *prox;
} Artigo;

typedef struct ArtigoTem
{
    Artigo *endArtigo;
    struct ArtigoTem *prox;;
} ArtigoTem;

typedef struct Palavra
{
    char titulo[20];
    ArtigoTem *listaTem;
    struct Palavra *prox;
} Palavra;

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

void iniciaArtigo(Artigo *a);
void iniArtigoTem(ArtigoTem *a);
void iniciaPalavra(Palavra *p);
void iniListaArtigo(ListaArtigos *l);
void iniListaPalavra(ListaPalavras *l);
void iniListaArtigoTem (ListaPalavras *l);
void resetaRelevancia(Artigo *a);
void imprimir(Artigo **lista);

#endif