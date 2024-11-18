#ifndef INSERIRPALAVRAGLORAL_H
#define INSERIRPALAVRAGLORAL_H

#include "estrutura.h"

Palavra *procurarPalavra(Palavra *atual, char palav[20]);
void inserirNaLetra(ListaPalavras *lista, char palav[20], Artigo *end_art);
void inserirListaGlobal (ListaPalavras lista[26], char palav[20], Artigo *end_art);

#endif