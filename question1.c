#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

struct Celula {
    bool is_alive;
};
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}

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
    printf("Digite sua opção de inicialização do quadro:\n1-Inicialização Randômica\n2-Define celulas vivas\n");
    int opcao;
    scanf("%d",&opcao);
    if (opcao == 1)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                quadro[i][j].is_alive=false;
            }
            
        }
        
        int number_of_cells= rand()%900;
        for (int i = 0; i < number_of_cells; i++)
        {
            int x = rand()%30;
            int y = rand()%30;
            quadro[x][y].is_alive=true;
        }
        
    }
    else
    {   
        int x[30],y[30];
        for (int i = 0; i < 30; i++)
        {
            x[i]=0;
            y[i]=0;
        }
        
        int count = 0;
        while (true )
        {
          scanf("%d %d",&x[count],&y[count]);
          if(x[count] == -1 && y[count] == -1){
              break;
          }
          count++;  
        }
        
        for(int i = 0; i<30 ; i++){
            for(int j = 0; j<30; j++){
                for(int cont = 0; cont<30; cont++){
                    if(x[cont] == i && y[cont] == j){
                        quadro[i][j].is_alive = true;
                    }else{
                        quadro[i][j].is_alive = false;
                    }
                }
               
            }
        }
        
    }
    while (true)
    {
        for (int i = 0; i < 30; i++){
            for (int j = 0; j < 30; j++)
            {
                if (quadro[i][j].is_alive==true)
                {
                    printf("O");
                }
                else
                {
                    printf(" ");
                }            
            }
            printf("\n");
            
        }
        delay(1);
        clear();
    }
    
    
    
    
    return 0;
}
