#include "estrutura.h"
#include "leitura.h"

/*Implemente um sistema de busca de documentos na internet. No caso, você deve considerar a palavra chave e as palavras que 
compõem o nome do documento. No caso você receberá vários artigos, seu endereço, nome e palavra chaves, e deve responder a uma 
pergunta do usuário sobre um determinando assunto listando todos documentos que atendem ao mesmo, os documentos de seu trabalho 
devem ser os artigos da https://sol.sbc.org.br/index.php/bracis, https://sol.sbc.org.br/index.php/bsb, https://sol.sbc.org.br/index.php/cbie 
e https://sol.sbc.org.br/index.php/cbsoft*/

int main(){
    Artigo *lista = malloc(sizeof(Artigo));
    ListaPalavras palavrasGlobal[26];
    char insignificantes[COL][LIN] = {"de", "da", "do", "para", "em", "com", "mas", "mais", "um", "uma", 
    "sobre", "que", "como", "no", "na", "nas", "nos", "por", "até", "sob", 
    "entre", "e", "através", "durante", "desde", "baseada", "baseado", "baseadas", "baseados", "às",
    "o", "a", "os", "as", "uns", "umas", "dos", "das", "acerca", "numa",
    "nuns", "num", "numas", "in", "with", "and", "of", "an", "the", "are", 
    "on", "for", "to", "from", "does", "through", "about", "how"};
    iniciaArtigo(lista);
    lerArtigos(lista, insignificantes);
    //imprimir(&lista);

    char palavras[300];
    scanf("%[^\n]", palavras);
    separaEntrada(strlwr(palavras), insignificantes, 'u');

    return 0;
} 