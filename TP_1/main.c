#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    float x;
    float y;
    float resultado;
    char fac;
    int flagx=0;
    int flagy=0;



    while(seguir=='s')
    {
        if (flagx==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");

        }
        else
        {
             printf("1- Ingresar 1er operando (A=%.3f)\n",x);
        }
        if (flagy==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");

        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.3f)\n",y);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)o(B!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        printf("\n\n");



        switch(opcion)
        {
            case 1:
                x =pedirNum();
                flagx=1;
                printf("\n\n");
                break;
            case 2:
                y =pedirNum();
                flagy=1;
                printf("\n\n");
                break;
            case 3:
                resultado=suma(x,y);
                printf("La suma da: %.3f\n\n",resultado);
                break;
            case 4:
                resultado=resta(x,y);
                printf("La resta da: %.3f\n\n",resultado);
                break;
            case 5:
                dividir(x,y);
                break;
            case 6:
                resultado=multiplica(x,y);
                printf("La multiplicacion da: %.3f\n\n",resultado);
                break;
            case 7:
                printf("Seleccion operando a factorear: 'A' o 'B': ");
                scanf(" %c",&fac);
                switch(fac)
                {   case 'A':
                    fact(x);
                    if(fact(x)==-1)
                    {
                        printf("No se puede mostrar resultado\n");
                    }
                    else if(fact(x)==-2)
                    {
                        printf("operacion no valida!");
                    }
                    else
                    {
                        printf("El factorial de %.0f es: %li\n",x,fact(x));
                    }
                    printf("\n\n");
                    break;
                    case 'B':
                    fact(y);
                    if(fact(y)==-1)
                    {
                        printf("No se puede mostrar resultado\n");
                    }
                    else if(fact(y)==-2)
                    {
                        printf("operacion no valida");
                    }
                    else
                    {
                        printf("El factorial de %.0f es: %li\n",y,fact(y));
                    }
                    printf("\n\n");
                    break;
                    default:
                    printf("ERROR\n");
                    printf("Seleccion operando a factorear: 'A' o 'B'\n");
                    scanf(" %c",&fac);
                }
                break;
            case 8:

                printf("La suma da: %.2f\n\n",suma(x,y));
                printf("La resta da: %.2f\n\n",resta(x,y));
                dividir(x,y);
                printf("La multiplicacion da: %.3f\n\n",multiplica(x,y));
                fact(x);
                    if(fact(x)==-1)
                    {
                        printf("No se puede mostrar resultado\n\n");
                    }
                    else if(fact(x)==-2)
                    {
                        printf("operacion no valida");
                    }
                    else
                    {
                        printf("El factorial de %.0f es: %li\n\n",x,fact(x));
                    }
                fact(y);
                    if(fact(y)==-1)
                    {
                        printf("No se puede mostrar resultado\n");
                    }
                    else if(fact(y)==-2)
                    {
                        printf("operacion no valida");
                    }
                    else
                    {
                        printf("El factorial de %.0f es: %li\n",y,fact(y));
                    }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
