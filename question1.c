#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

struct Celula {
    bool is_alive;
};

void clear(){
    // funcao para limpar a tela para ambos sistemas operacionais.
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
int main()
{    
    struct Celula quadro[30][30];
    
    return 0;
}
