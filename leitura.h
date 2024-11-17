#ifndef LEITURA_H
#define LEITURA_H

#define COL 29
#define LIN 20

void incluiArtigo(ListaArtigos *lista, char titulo[200], char link[300]);
void incluirPalavra (ListaPalavras *lista, char palavra[20]);
void incluirArtigoTem (ListaArtigoTem *lista, Artigo *end_artigo);
void insereFim(Artigo **a, char nome[200], char url[300]);
void lerArtigos(Artigo *lista);
int ehPalavraChave(char palavra[20], char insignificantes[COL][LIN]);
void separaEntrada(char palavras[300], char insignificantes[COL][LIN]);

#endif 