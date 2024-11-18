#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Artigo
{
    char titulo[200];
    int relevancia;
    struct Artigo *prox;
} Artigo;

typedef struct ArtigoTem
{
    Artigo *endArtigo;
    struct ArtigoTem *prox;
} ArtigoTem;

typedef struct ListaArtigoTem
{
    ArtigoTem *inicio;
    ArtigoTem *final;
} ListaArtigoTem;

typedef struct Palavra
{
    char titulo[20];
    ListaArtigoTem *listaTem;
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

void iniciaArtigo(Artigo *a);
void iniArtigoTem(ArtigoTem *a);
void iniListaArtigoTem (ListaArtigoTem *l);
void iniciaPalavra(Palavra *p);
void iniListaArtigo(ListaArtigos *l);
void iniListaPalavra(ListaPalavras *l);
void resetaRelevancia(Artigo *a);
void incluiArtigo(ListaArtigos *lista, char titulo[200]);
Palavra *incluirPalavra (ListaPalavras *lista, char palavra[20]);
void incluirArtigoTem (ListaArtigoTem *lista, Artigo *end_artigo);
void imprimirArtigo(Artigo *a);
void imprimirListaArtigos(Artigo *atual);
void iniPalavraGlobal(ListaPalavras lista[26]);

#endif