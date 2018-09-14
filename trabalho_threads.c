#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linhas 16
#define colunas 62

/* palavras:
    threads
    arquivos
    sinais
    pipe
    processos
    mutex */

// matriz para armazenar o diagrama
char diagrama[linhas][colunas];

/* ---------------- BUSCA HORIZONTAL --------------- */
void busca_horizontal(char *palavra, int tamanho_palavra) {
    // percorre a matriz do diagrama
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // confere as letras da linha com a primeira letra da palavra
            if (tolower(diagrama[i][j]) == palavra[0]) {
                // se achou a primeira letra, confere o restante
                int posicao_palavra = 0;
                int posicao_linha = j;

                while (posicao_palavra < tamanho_palavra && posicao_linha < colunas) {
                    if (tolower(diagrama[i][posicao_linha]) == palavra[posicao_palavra]) {
                        posicao_palavra++;
                        posicao_linha++;
                    }
                    else {
                        posicao_palavra = 0;
                        posicao_linha++;
                    }
                }
                // se chegou até o fim da palavra é porque achou
                // então dá uppercase
                if (posicao_palavra == tamanho_palavra) {
                    for (int k = j; k < j + tamanho_palavra; k++) {
                        diagrama[i][k] = toupper(diagrama[i][k]);
                    }
                }
            }
        }
    }
}

/* ---------------- BUSCA VERTICAL --------------- */
void busca_vertical(char *palavra, int tamanho_palavra) {
    // percorre a matriz do diagrama
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // confere as letras da linha com a primeira letra da palavra
            if (tolower(diagrama[i][j]) == palavra[0]) {
                // se achou a primeira letra, confere o restante
                int posicao_palavra = 0;
                int posicao_coluna = i;

                while (posicao_palavra < tamanho_palavra && posicao_coluna < linhas) {
                    if (tolower(diagrama[posicao_coluna][j]) == palavra[posicao_palavra]) {
                        printf("d[%d][%d]: %c == %c\n", posicao_coluna, j, diagrama[posicao_coluna][j], palavra[posicao_palavra]);
                        posicao_palavra++;
                        posicao_coluna++;
                    }
                    else {
                        posicao_palavra = 0;
                        posicao_coluna++;
                    }
                }
                // se chegou até o fim da palavra é porque achou
                // então dá uppercase
                if (posicao_palavra == tamanho_palavra) {
                    for (int k = i; k < i + tamanho_palavra; k++) {
                        diagrama[k][j] = toupper(diagrama[k][j]);
                        printf("diagrama: [%d][%d]: %c\n", k, j, diagrama[k][j]);
                    }
                }
            }
        }
    }
}

/* --------- BUSCA VERTICAL INVERTIDA   --------------- */
void busca_vertical_invertida(char *palavra, int tamanho_palavra) {
    // percorre a matriz do diagrama
    for (int i = linhas - 1; i >= 0; i--) {
        for (int j = colunas - 1; j >= 0; j--) {
            // confere as letras da linha com a primeira letra da palavra
            if (tolower(diagrama[i][j]) == palavra[0]) {
                // se achou a primeira letra, confere o restante
                int posicao_palavra = 0;
                int posicao_coluna = i;

                while (posicao_palavra < tamanho_palavra && posicao_coluna >= 0) {
                    if (tolower(diagrama[posicao_coluna][j]) == palavra[posicao_palavra]) {
                        posicao_palavra++;
                        posicao_coluna--;
                    }
                    else {
                        posicao_palavra = 0;
                        posicao_coluna--;
                    }
                }
                // se chegou até o fim da palavra é porque achou
                // então dá uppercase
                if (posicao_palavra == tamanho_palavra) {
                    for (int k = i; k > i - tamanho_palavra; k--) {
                        diagrama[k][j] = toupper(diagrama[k][j]);
                    }
                }
            }
        }
    }
}

int main() {

    /* --------------- LEITURA DO DIAGRAMA --------------- */
    // ponteiro para o arquivo de entrada
    FILE *entrada;

    // verifica se funcionou a abertura do arquivo
    // entrada = fopen("entrada.txt", "r");
    entrada = fopen("entrada_modificada.txt", "r");
    if (entrada == NULL) {
        printf("Erro na abertura do arquivo!");
    }

    // leitura do arquivo para popular a matriz
    for (int i = 0; i < linhas; i++) {
        fgets(diagrama[i], colunas, entrada);
    }

    // fecha o arquivo
    fclose(entrada);

    /* ----------------- IMPRESSÃO DO DIAGRAMA ----------- */
    printf("Diagrama antes:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c", diagrama[i][j]);
        }
    }
    printf("\n");

    // busca horizontal
    char palavra[] = "processos";
    int tamanho_palavra = 9;
    busca_horizontal(palavra, tamanho_palavra);

    strcpy(palavra, "sinais");
    tamanho_palavra = 6;
    busca_horizontal(palavra, tamanho_palavra);

    // busca vertical
    strcpy(palavra, "pipe");
    tamanho_palavra = 4;
    busca_vertical(palavra, tamanho_palavra);

    strcpy(palavra, "threads");
    tamanho_palavra = 7;
    busca_vertical(palavra, tamanho_palavra);

    // busca vertical invertida
    strcpy(palavra, "mutex");
    tamanho_palavra = 5;
    busca_vertical_invertida(palavra, tamanho_palavra);

    // busca diagonal invertida (?)

    /* ----------------- IMPRESSÃO DO DIAGRAMA ----------- */
    printf("\nDiagrama depois:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c", diagrama[i][j]);
        }
    }

}