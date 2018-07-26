#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
int main()
{
    ArrayList* deposito1=al_newArrayList();
    ArrayList* deposito2=al_newArrayList();
    char path[30],path1[30];
    strcpy(path,"dep0.csv");
    strcpy(path1,"dep1.csv");
    int salir=0;

    while(salir==0)
    {
       switch(menu())
    {
        case 1:
            cargar(deposito1,deposito2,path,path1);
            system("pause");
            break;
        case 2:
            Listar(deposito1,deposito2);
            break;
        case 3:
            mover(deposito1,deposito2,path,path1);
            break;
        case 4:
            descontar(deposito1,deposito2,path,path1);
            break;
        case 5:
            agregar (deposito1,deposito2,path,path1);
        case 6:
            salir=1;
            break;
        default:
            printf("ERROR");
            break;
    }
    }




    return 0;
}
