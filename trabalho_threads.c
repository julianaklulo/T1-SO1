#include <stdio.h>
#include <stdlib.h>

#define linhas 16
#define colunas 62


int main() {
    /* palavras:
    threads
    arquivos
    sinais
    pipe
    processos
    mutex */

    FILE *entrada;

    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro na abertura do arquivo!");
    }

    char diagrama[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        fgets(diagrama[i], colunas, entrada);
        printf("%s", diagrama[i]);

    }

    fclose(entrada);
}
