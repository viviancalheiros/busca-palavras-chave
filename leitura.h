#ifndef LEITURA_H
#define LEITURA_H

#define COL 58
#define LIN 20

void insereFim(Artigo **a, char nome[200]);
int ehPalavraChave(char palavra[20], char insignificantes[COL][LIN]);
void palavrasDoTitulo(char palavras[300], char insignificantes[COL][LIN], ListaPalavras alfabeto[26], Artigo *a);
void lerArtigos(Artigo *a, char insignificantes[COL][LIN], ListaPalavras alfabeto[26]);
void separaEntrada(char palavras[300], char insignificantes[COL][LIN]);

#endif 