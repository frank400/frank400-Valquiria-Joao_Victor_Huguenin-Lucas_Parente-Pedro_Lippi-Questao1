#include "system_operations.h"

void delay(int number_of_seconds) {
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
    Sleep(number_of_seconds*1000000);
#else

#include <unistd.h>

    usleep(1000000 * number_of_seconds);
#endif
}

void clear() {
    // funcao para limpar a tela para ambos sistemas operacionais.
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}


