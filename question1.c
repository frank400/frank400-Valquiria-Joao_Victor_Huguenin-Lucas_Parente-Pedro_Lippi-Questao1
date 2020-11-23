#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

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
    
    return 0;
}
