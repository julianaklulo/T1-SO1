#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    // flag para marcar se achou ou não a palavra
    int achou = 0;

    // índice atual da palavra
    int posicao_palavra = 0;

    // índices para salvar onde a palavra achada começa
    int linha_palavra = -1;
    int coluna_palavra = -1;

    // flag para saber se já pode parar os loops
    int terminou = 0;

    // percorre a matriz do diagrama
    for (int i = 0; i < linhas && !terminou; i++) {
        for (int j = 0; j < colunas && !terminou; j++) {
            // confere as letras da linha com as letras da palavra
            if (tolower(diagrama[i][j]) == palavra[posicao_palavra]) {
                // se for a primeira letra da palavra, salva a posição do começo dela
                if (posicao_palavra == 0) {
                    linha_palavra = i;
                    coluna_palavra = j;
                }
                // ativa a flag para indicar que achou
                achou = 1;
                // avança a posição da palavra
                posicao_palavra++;
            }
            // caso a letra da linha não faça parte da palavra, reseta os índices e flags
            else {
                achou = 0;
                posicao_palavra = 0;
                linha_palavra = -1;
                coluna_palavra = -1;
            }
            // se já chegou no fim da palavra, ativa a flag para parar os loops
            if (posicao_palavra == tamanho_palavra) {
                terminou = 1;
            }
        }
    }
    // se achou a palavra, dá uppercase
    if (achou) {
        for (int k = coluna_palavra; k < coluna_palavra + tamanho_palavra; k++) {
            diagrama[linha_palavra][k] = toupper(diagrama[linha_palavra][k]);
        }
    }
}

/* -------- BUSCA HORIZONTAL INVERTIDA ----------------- */
void busca_horizontal_invertida(char *palavra, int tamanho_palavra) {
    // flag para marcar se achou ou não a palavra
    int achou = 0;

    // índice atual da palavra
    int posicao_palavra = 0;

    // índices para salvar onde a palavra achada começa
    int linha_palavra = -1;
    int coluna_palavra = -1;

    // flag para saber se já pode parar os loops
    int terminou = 0;

    // percorre a matriz do diagrama
    for (int i = 0; i < linhas && !terminou; i++) {
        for (int j = colunas - 1; j > 0 && !terminou; j--) {
            // confere as letras da linha com as letras da palavra
            if (tolower(diagrama[i][j]) == palavra[posicao_palavra]) {
                // se for a primeira letra da palavra, salva a posição do começo dela
                if (posicao_palavra == 0) {
                    linha_palavra = i;
                    coluna_palavra = j;
                }
                // ativa a flag para indicar que achou
                achou = 1;
                // avança a posição da palavra
                posicao_palavra++;
            }
            // caso a letra da linha não faça parte da palavra, reseta os índices e flags
            else {
                achou = 0;
                posicao_palavra = 0;
                linha_palavra = -1;
                coluna_palavra = -1;
            }
            // se já chegou no fim da palavra, ativa a flag para parar os loops
            if (posicao_palavra == tamanho_palavra) {
                terminou = 1;
            }
        }
    }
    // se achou a palavra, dá uppercase
    if (achou) {
        for (int k = coluna_palavra; k > coluna_palavra - tamanho_palavra; k--) {
            diagrama[linha_palavra][k] = toupper(diagrama[linha_palavra][k]);
        }
    }
}


/* ---------------- BUSCA VERTICAL --------------- */
void busca_vertical(char *palavra, int tamanho_palavra) {
    // flag para marcar se achou ou não a palavra
    int achou = 0;

    // índice atual da palavra
    int posicao_palavra = 0;

    // índices para salvar onde a palavra achada começa
    int linha_palavra = -1;
    int coluna_palavra = -1;

    // flag para saber se já pode parar os loops
    int terminou = 0;

    // percorre a matriz do diagrama
    for (int j = 0; j < colunas && !terminou; j++) {
        for (int i = 0; i < linhas && !terminou; i++) {
            // confere as letras da linha com as letras da palavra
            if (tolower(diagrama[i][j]) == palavra[posicao_palavra]) {
                // se for a primeira letra da palavra, salva a posição do começo dela
                if (posicao_palavra == 0) {
                    linha_palavra = i;
                    coluna_palavra = j;
                }
                // ativa a flag para indicar que achou
                achou = 1;
                // avança a posição da palavra
                posicao_palavra++;
            }
            // caso a letra da linha não faça parte da palavra, reseta os índices e flags
            else {
                achou = 0;
                posicao_palavra = 0;
                linha_palavra = -1;
                coluna_palavra = -1;
            }
            // se já chegou no fim da palavra, ativa a flag para parar os loops
            if (posicao_palavra == tamanho_palavra) {
                terminou = 1;
            }
        }
    }
    // se achou a palavra, dá uppercase
    if (achou) {
        for (int k = linha_palavra; k < linha_palavra + tamanho_palavra; k++) {
            diagrama[k][coluna_palavra] = toupper(diagrama[k][coluna_palavra]);
        }
    }
}

/* --------- BUSCA VERTICAL INVERTIDA   ---------------
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
} */

/* -------- BUSCA VERTICAL INVERTIDA ----------------- */
void busca_vertical_invertida(char *palavra, int tamanho_palavra) {
    // flag para marcar se achou ou não a palavra
    int achou = 0;

    // índice atual da palavra
    int posicao_palavra = 0;

    // índices para salvar onde a palavra achada começa
    int linha_palavra = -1;
    int coluna_palavra = -1;

    // flag para saber se já pode parar os loops
    int terminou = 0;

    // percorre a matriz do diagrama
    for (int j = colunas - 1; j > 0 && !terminou; j--) {
        for (int i = linhas - 1; i > 0 && !terminou; i--) {
            // confere as letras da linha com as letras da palavra
            if (tolower(diagrama[i][j]) == palavra[posicao_palavra]) {
                // se for a primeira letra da palavra, salva a posição do começo dela
                if (posicao_palavra == 0) {
                    linha_palavra = i;
                    coluna_palavra = j;
                }
                // ativa a flag para indicar que achou
                achou = 1;
                // avança a posição da palavra
                posicao_palavra++;
            }
            // caso a letra da linha não faça parte da palavra, reseta os índices e flags
            else {
                achou = 0;
                posicao_palavra = 0;
                linha_palavra = -1;
                coluna_palavra = -1;
            }
            // se já chegou no fim da palavra, ativa a flag para parar os loops
            if (posicao_palavra == tamanho_palavra) {
                terminou = 1;
            }
        }
    }
    // se achou a palavra, dá uppercase
    if (achou) {
        for (int k = linha_palavra; k > linha_palavra - tamanho_palavra; k--) {
            diagrama[k][coluna_palavra] = toupper(diagrama[k][coluna_palavra]);
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

    // busca horizontal invertida
    strcpy(palavra, "batata");
    tamanho_palavra = 6;
    busca_horizontal_invertida(palavra, tamanho_palavra);

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