#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"


int obtenerEspacioLibre(ePersona vec[],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1)
        {
            indice=i;
        }
    }
    return indice;
}
void inicializarPersona(ePersona vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
    vec[i].ocupado=1;
    }
}
void mostrarPersona(ePersona vec[],int indice)
{

    printf("%8s     %2d      %d\n\n",vec[indice].nombre,vec[indice].edad,vec[indice].dni);
}
int buscarPorDni(ePersona vec[], int tam,int dni)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( vec[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void altas(ePersona vec[], int tam)
{
    ePersona nuevaPersona;
    int indice;
    int esta;
    int dni;
    system("cls");


    indice=obtenerEspacioLibre(vec,tam);

    if(indice ==-1)
    {
        printf("No hay lugar para dar altas\n\n");

    }
    else
    {
        printf("Ingrese D.N.I: ");
        scanf("%d", &dni);
        esta= buscarPorDni(vec,tam,dni);
        if(esta==-1)
        {

            nuevaPersona.dni=dni;
            nuevaPersona.ocupado=0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("Ingrese edad: ");
            scanf("%d",&nuevaPersona.edad);
            vec[indice]=nuevaPersona;
            printf("Se realizo la alta!\n\n");
        }
        else
        {

            mostrarPersona(vec,esta);
        }
    }

}
void lista(ePersona vec[],int tam)
{
    system("cls");
    ordenarPersona(vec,tam);

    printf("      ---Lista de Empleados---\n\n");
    printf("   Nombre   edad     D.N.I\n   ------   ----     -----\n\n");

    for(int i=0; i< tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            mostrarPersona(vec,i);
        }
    }
}
void baja(ePersona vec[],int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");


    printf("Ingrese dni: ");
    scanf("%d", &dni);

    esta = buscarPorDni(vec, tam, dni);

    if(esta == -1)
    {
        printf("\nEl D.N.I %d no se encuentra en el sistema\n\n", dni);

    }
    else
    {

        mostrarPersona(vec,esta);

        printf("\nConfirma baja:s/n? ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].ocupado = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}
void ordenarPersona(ePersona vec[],int tam)
{
    int i;
    int j;
    ePersona aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp (vec[i].nombre, vec[j].nombre)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;

            }
        }

    }
}
void grafico(ePersona vec[],int tam)
{
    system("cls");
   int i;
   int j;
   int acumulador=0;
   int acumulador1=0;
   int acumulador2=0;

    for(i=0;i<tam;i++)
   {
       if(vec[i].ocupado==0)
       {
           if (vec[i].edad>35)
            {
                acumulador2++;
            }
            else
            {
                if(vec[i].edad<18)
                {
                    acumulador++;
                }
                else
                {
                    acumulador1++;
                }

            }

       }


   }
    int valor[]={acumulador,acumulador1,acumulador2};
    int max=0;
    for (i = 0; i < 3; i++)
      {
        if (valor[i] > max)
         {
             max = valor[i];
         }
      }

    for (i = max; i > 0; i--)
    {
      for (j = 0; j < 3; j++)
      {
          if (valor[j] >= i)
            {
                printf("   *");
            }
         else
            {
                printf("    ");
            }
      }
      printf("\n\n");

   }
        printf("<18  18-35  35>\n");
}
int menu()
{
    int opcion;

        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Elija opcion: ");
        scanf("%d",&opcion);
        return opcion;
}

