#include "operacoes_matrix.h"

#define size_quadro 30


void fill_morto(int colunas, int linhas, struct Celula *quadro) {
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            quadro[i * colunas + j].is_alive = false;
            quadro[i * colunas + j].is_going_to_die = false;
            quadro[i * colunas + j].is_going_to_be_alive = false;
        }
    }
}

void print_matrix(int colunas, int linhas, struct Celula *quadro) {
    printf("X------------------------------X\n");
    for (int i = 0; i < colunas; i++) {
        printf("|");
        for (int j = 0; j < linhas; j++) {
            if (quadro[i * colunas + j].is_alive == true) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("X------------------------------X\n");
}

void update_cells(int linhas, int colunas, struct Celula *quadro) {
    for (int i = 0; i < size_quadro; i++) {
        for (int j = 0; j < size_quadro; j++) {
            if (quadro[i * size_quadro + j].is_going_to_die) {
                quadro[i * size_quadro + j].is_alive = false;
            } else if (quadro[i * size_quadro + j].is_going_to_be_alive) {
                quadro[i * size_quadro + j].is_alive = true;
            }
            quadro[i * colunas + j].is_going_to_die = false;
            quadro[i * colunas + j].is_going_to_be_alive = false;

        }

    }

}

void aplica_regras(int i, int j, struct Celula *quadro, int *vizinhos) {

    if (*vizinhos < 2 || *vizinhos > 3) {
        quadro[i * size_quadro + j].is_going_to_die = true;
    } else if (quadro[i * size_quadro + j].is_alive == false && *vizinhos == 3) {
        quadro[i * size_quadro + j].is_going_to_be_alive = true;
    }
    *vizinhos = 0;
}
void still_alive(int linhas, int colunas, struct Celula quadro[][colunas]) {
    for (int i = 0; i < size_quadro; i++) {
        for (int j = 0; j < size_quadro; j++) {
            int vizinhos = 0;

            //celulas do miolo da matrix
            if (j + 1 < size_quadro && i + 1 < size_quadro && j - 1 >= 0 && i - 1 >= 0) {
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior direita
                if (quadro[i - 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior esquerda
                if (quadro[i + 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i + 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i - 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }

                aplica_regras(i, j, *quadro, &vizinhos);
            }
            //celula na posição x=0 y =0
            if (i == 0 && j == 0) {
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i + 1][j + 1].is_alive == true) {
                    vizinhos++;
                }

                aplica_regras(i, j, *quadro, &vizinhos);
            }
                //celula na posição y=0, na linha superior da matrix
            else if (i == 0 && i != size_quadro - 1) {
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i + 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior esquerda
                if (quadro[i + 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                aplica_regras(i, j, *quadro, &vizinhos);

            }
                //Na linha mais a esquerda da matrix, x=0
            else if (j == 0 && j != size_quadro - 1) {
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i + 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior direita
                if (quadro[i - 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                aplica_regras(i, j, *quadro, &vizinhos);
            }


            // No extremo inferior direito da matrix
            if (i == size_quadro - 1 && j == size_quadro - 1) {
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i - 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }

                aplica_regras(i, j, *quadro, &vizinhos);
            } else if (i == size_quadro - 1 && j == 0) {
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior direita
                if (quadro[i - 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                aplica_regras(i, j, *quadro, &vizinhos);
            } else if (i == size_quadro - 1) {
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i][j + 1].is_alive == true) {
                    vizinhos++;
                }
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i - 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior direita
                if (quadro[i - 1][j + 1].is_alive == true) {
                    vizinhos++;
                }
                aplica_regras(i, j, *quadro, &vizinhos);
            } else if (j == size_quadro - 1 && i == 0) {
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior esquerda
                if (quadro[i + 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                aplica_regras(i, j, *quadro, &vizinhos);
            } else if (j == size_quadro - 1) {
                //celula acima
                if (quadro[i - 1][j].is_alive == true) {
                    vizinhos++;
                }
                // celula abaixo
                if (quadro[i + 1][j].is_alive == true) {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i - 1][j - 1].is_alive == true) {
                    vizinhos++;
                }
                //celula na diagonal inferior esquerda
                if (quadro[i + 1][j - 1].is_alive == true) {
                    vizinhos++;
                }

                aplica_regras(i, j, *quadro, &vizinhos);
            }
        }
    }
}


void fill_quadro_random(struct Celula quadro[size_quadro][size_quadro]){
	fill_morto(size_quadro, size_quadro, *quadro);

    int number_of_cells = rand() % (size_quadro * size_quadro);
    for (int i = 0; i < number_of_cells; i++) {
        int x = rand() % size_quadro;
        int y = rand() % size_quadro;
        quadro[x][y].is_alive = true;
    }
}

void inicializacao_celula_viva(struct Celula quadro[size_quadro][size_quadro]){
     int x[size_quadro], y[size_quadro];
        for (int i = 0; i < size_quadro; i++) {
            x[i] = -4;
            y[i] = -4;
        }
        
        int count = 0;

        while (true) {
            scanf("%d %d", &x[count], &y[count]);
            if (x[count] == -1 && y[count] == -1) {
                break;
            }
            count++;
        }
    
}
