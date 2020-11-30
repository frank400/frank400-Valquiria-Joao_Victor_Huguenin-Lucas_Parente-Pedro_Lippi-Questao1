#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "operacoes_matrix.h"
#include "system_operations.h"

int main() {
    struct Celula quadro[size_quadro][size_quadro];
    printf("Digite sua opção de inicialização do quadro:\n1-Inicialização Randômica\n2-Define celulas vivas\n");
    int opcao;
    scanf("%d", &opcao);
    printf("Digite quantas gerações quer ver:\n");
    int geracoes;
    scanf("%d", &geracoes);
    if (opcao == 1) {
        fill_morto(size_quadro, size_quadro, *quadro);

        int number_of_cells = rand() % (size_quadro * size_quadro);
        for (int i = 0; i < number_of_cells; i++) {
            int x = rand() % size_quadro;
            int y = rand() % size_quadro;
            quadro[x][y].is_alive = true;
        }
    } else {
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

        fill_morto(size_quadro, size_quadro, *quadro);

        for (int i = 0; i < size_quadro; i++) {
            for (int j = 0; j < size_quadro; j++) {
                for (int cont = 0; cont < size_quadro; cont++) {
                    if (x[cont] == i && y[cont] == j) {
                        quadro[j][i].is_alive = true;
                    }
                }
            }
        }
    }
    int count_geracoes = 0;
    while (count_geracoes < geracoes) {

        print_matrix(size_quadro, size_quadro, *quadro);
        still_alive(size_quadro, size_quadro, quadro);
        update_cells(size_quadro, size_quadro, *quadro);
        count_geracoes++;
        delay(1);
        clear();
    }


    return 0;
}
