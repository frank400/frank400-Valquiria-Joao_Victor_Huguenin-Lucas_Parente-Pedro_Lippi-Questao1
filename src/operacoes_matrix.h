#ifndef QUESTION1_OPERACOES_MATRIX_H
#define QUESTION1_OPERACOES_MATRIX_H

#define size_quadro 30

struct Celula{
    bool is_alive;
    bool is_going_to_die;
    bool is_going_to_be_alive;
};

void fill_morto(int colunas, int linhas, struct Celula *quadro);
void print_matrix(int colunas, int linhas, struct Celula *quadro);
void update_cells(int linhas, int colunas, struct Celula *quadro);
void aplica_regras(int i, int j, struct Celula *quadro, int *vizinhos);
void still_alive(int linhas, int colunas, struct Celula quadro[][colunas]);

#endif //QUESTION1_OPERACOES_MATRIX_H
