#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

int main()
{
    char guarda, seguir='s';
    int tam=0, opcion, i;
    int* tamP=&tam;

    EMovie* moviesList;

    moviesList=(EMovie*)malloc(sizeof(EMovie)*50);
        if(moviesList==NULL)
        {
            printf("\nNo hay espacio en memoria.\n");
            exit(1);
        }


    for(i=0; i<tam; i++)
    {
        moviesList->duracion=0;
        moviesList->puntaje=0;
    }


    if(subirPelicula(moviesList,tamP))
    {
        printf("No se pudo abrir la base de datos.");
        exit(1);
    }

    while(seguir=='s')
    {
        printf("Peliculas cargadas en la base de datos: %d\n",tam);
        printf("1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3. Modificar pelicula\n");
        printf("4. Generar pagina\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(tam%100==0)
            {
                tam++;
                EMovie* auxMovies;
                auxMovies=(EMovie*)realloc(moviesList,100*sizeof(EMovie));
                if(auxMovies!=NULL)
                {
                    moviesList=auxMovies;
                    agregarPelicula(moviesList,tam,tamP);
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                tam++;
                agregarPelicula(moviesList,tam,tamP);
            }
            break;
        case 2:
            if(borrarPelicula(moviesList,tam,tamP))
            {
                tam--;
            }
            break;
        case 3:
            modificaMovie(moviesList,tam);
            break;
        case 4:
            generarPagina(moviesList,tam);
            if(guardar(moviesList,tam,tamP))
            {
                printf("\nEl archivo no pudo ser abierto. Error.\n");
            }
            else
            {
                printf("\nSe guardo la informacion con exito.\n");
            }
            break;
        case 5:
            printf("Guardar cambios (S/n): ");
            fflush(stdin);
            scanf("%c", &guarda);
            if(guarda == 's')
            {
                if(guardar(moviesList,tam,tamP))
                {
                    printf("\nEl archivo no pudo ser abierto. Error.\n");
                }
                else
                {
                    printf("\nSe guardo la informacion con exito. Ya puede salir.\n");
                }
            }
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
