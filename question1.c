#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> 
#define size_quadro 30

struct Celula {
    bool is_alive;
    bool is_going_to_die;
    bool is_going_to_be_alive;
};
void fill_morto(int colunas,int linhas, struct Celula* quadro){
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            quadro[i*colunas +j].is_alive=false;
            quadro[i*colunas +j].is_going_to_die=false;
            quadro[i*colunas +j].is_going_to_be_alive=false;
        }
    }
    
}
void print_matrix(int colunas,int linhas, struct Celula* quadro){
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            if(quadro[i*colunas +j].is_alive==true) printf("O");
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
}
void delay(int number_of_seconds) 
{ 
    sleep(number_of_seconds);
}
void update_cells(int linhas,int colunas, struct Celula* quadro){
    for (int i = 0; i < size_quadro; i++)
    {
        for (int j = 0; j < size_quadro; j++)
        {
            if (quadro[i*size_quadro+j].is_going_to_die)
            {
                quadro[i*size_quadro+j].is_alive=false;
            }else if (quadro[i*size_quadro+j].is_going_to_be_alive)
            {
                quadro[i*size_quadro+j].is_alive=true;
            }
            quadro[i*colunas +j].is_going_to_die=false;
            quadro[i*colunas +j].is_going_to_be_alive=false;           
            
        }
        
    }
    
}
void aplica_regras(int i,int j, struct Celula* quadro, int* vizinhos){

    if (*vizinhos<2 || *vizinhos > 3)
    {
        quadro[i*size_quadro+j].is_going_to_die=true;
    }
    else if(quadro[i*size_quadro+j].is_alive==false && *vizinhos==3)
    {
        quadro[i*size_quadro+j].is_going_to_be_alive=true;
    }
    *vizinhos=0;
}
void still_alive(int linhas,int colunas, struct Celula quadro[][colunas]){
    for (int i = 0; i < size_quadro; i++)
    {
        for (int j = 0; j < size_quadro; j++)
        {   
            int vizinhos=0;
            if (j+1<size_quadro && i+1<size_quadro && j-1>=0 && i-1>=0)
            {
                //celula acima
                if (quadro[i][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal superior direita
                if (quadro[i+1][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal inferior esquerda
                if (quadro[i-1][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i+1][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i-1][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                // celula abaixo
                if (quadro[i][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i+1][j].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i-1][j].is_alive==true)
                {
                    vizinhos++;
                }

                aplica_regras(i,j,*quadro,&vizinhos);         
                
            }
            if (i==0 && j ==0)
            {
                // celula abaixo
                if (quadro[i][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i+1][j].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal inferior direita
                if (quadro[i+1][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                

                aplica_regras(i,j,*quadro,&vizinhos);
            }else if (i == 0 && i!= size_quadro-1)
            {
                // celula abaixo
                if (quadro[i][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i+1][j].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i-1][j].is_alive==true)
                {
                    vizinhos++;
                }
                aplica_regras(i,j,*quadro,&vizinhos);

            }else if (j==0 && j != size_quadro-1)
            {
                //celula acima
                if (quadro[i][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                // celula abaixo
                if (quadro[i][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i+1][j].is_alive==true)
                {
                    vizinhos++;
                }
                aplica_regras(i,j,*quadro,&vizinhos);
            }
            
            
            if (i == size_quadro-1 && j ==size_quadro-1)
            {
                //celula acima
                if (quadro[i][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula na diagonal superior esquerda
                if (quadro[i-1][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i-1][j].is_alive==true)
                {
                    vizinhos++;
                }

                aplica_regras(i,j,*quadro,&vizinhos);
            }else if (i == size_quadro-1)
            {
                //celula acima
                if (quadro[i][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a direita
                if (quadro[i+1][j].is_alive==true)
                {
                    vizinhos++;
                }
                //celula a esquerda
                if (quadro[i-1][j].is_alive==true)
                {
                    vizinhos++;
                }
                aplica_regras(i,j,*quadro,&vizinhos);
            }else if (j== size_quadro-1)
            {
                //celula a esquerda
                if (quadro[i-1][j].is_alive==true)
                {
                    vizinhos++;
                }
                //celula acima
                if (quadro[i][j+1].is_alive==true)
                {
                    vizinhos++;
                }
                //celula abaixo
                if (quadro[i][j-1].is_alive==true)
                {
                    vizinhos++;
                }
                aplica_regras(i,j,*quadro,&vizinhos);
            }
        }
        
    }
    
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
    struct Celula quadro[size_quadro][size_quadro];
    printf("Digite sua opção de inicialização do quadro:\n1-Inicialização Randômica\n2-Define celulas vivas\n");
    int opcao;
    scanf("%d",&opcao);
    printf("Digite quantas gerações quer ver:\n");
    int geracoes;
    scanf("%d",&geracoes);
    if (opcao == 1)
    {
        fill_morto(size_quadro,size_quadro,*quadro);

        int number_of_cells= rand()%(size_quadro*size_quadro);
        for (int i = 0; i < number_of_cells; i++)
        {
            int x = rand()%size_quadro;
            int y = rand()%size_quadro;
            quadro[x][y].is_alive=true;
        }
        
    }
    else
    {   
        int x[size_quadro],y[size_quadro];
        for (int i = 0; i < size_quadro; i++)
        {
            x[i]=-4;
            y[i]=-4;
        }
        
        int count = 0;

        while (true)
        {
          scanf("%d %d",&x[count],&y[count]);
          if(x[count] == -1 && y[count] == -1){
              break;
          }
          count++;  
        }

        fill_morto(size_quadro,size_quadro,*quadro);

        for(int i = 0; i<size_quadro ; i++){
            for(int j = 0; j<size_quadro; j++){
                for(int cont = 0; cont<size_quadro; cont++){
                    if(x[cont] == i && y[cont] == j){
                        quadro[j][i].is_alive = true;
                    }
                }
               
            }
        }
        
    }
    int count_geracoes=0;
    while (count_geracoes<geracoes)
    {
        print_matrix(size_quadro,size_quadro,*quadro);
        still_alive(size_quadro,size_quadro,quadro);
        update_cells(size_quadro,size_quadro,*quadro);
        count_geracoes++;

        //delay(1);
        //clear();
    } 
    
    
    
    return 0;
}
