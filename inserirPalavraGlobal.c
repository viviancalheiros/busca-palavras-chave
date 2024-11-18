#include "estrutura.h"

// recebe o inicio da lista
Palavra *procurarPalavra(Palavra *atual, char palav[20])
{
    if (atual == NULL)
    {
        return NULL;
    }

    if (strcmp(atual->titulo, palav) == 0)
    {
        return atual;
    }

    return procurarPalavra(atual->prox, palav);
}

void inserirNaLetra(ListaPalavras *lista, char palav[20], Artigo *end_art)
{
    Palavra *existe = procurarPalavra(lista->inicio, palav);
    if (existe == NULL)
    {
        existe = incluirPalavra(lista, palav);
    }
    incluirArtigoTem(existe->listaTem, end_art);

    return;
}

void inserirListaGlobal (ListaPalavras lista[26], char palav[20], Artigo *end_art)
{
    int i = palav[0] - 97;

    inserirNaLetra(&lista[i], palav, end_art);

    return;
}