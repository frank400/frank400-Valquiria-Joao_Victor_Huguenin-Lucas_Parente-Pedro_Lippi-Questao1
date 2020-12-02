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

    srand((unsigned) time(0));
    if (opcao == 1) {
        fill_quadro_random(quadro);
    } else {
        inicializacao_celula_viva(quadro);
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
