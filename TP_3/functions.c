#ifndef FUNCTIONS_C_INCLUDED
#define FUNCTIONS_C_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "functions.h"


void mostrarPelicula(EMovie *moviesList)
{
    printf("Titulo: %s\nGenero: %s\nDuracion: %d mins\nDescripcion: %s\nPuntaje: %d\nEnlace de la imagen: %s\n", moviesList->titulo, moviesList->genero, moviesList->duracion, moviesList->descripcion, moviesList->puntaje, moviesList->linkImagen);
}
void mostrarPeliculas(EMovie *moviesList, int tam)
{
    int i;
    printf("Titulo\n");
    for(i=0;i<tam;i++)
    {
        if((moviesList+i)->duracion!=0)
        printf("%s\n", (moviesList+i)->titulo);

    }
}


void validarString(char valido[], int max)
{
    int largo=strlen(valido);

    while(max<largo)
    {
        printf("Se ha excedido el limite de caracteres.\nReingrese: ");
        gets(valido);
        largo=strlen(valido);
    }
}


int validoMinMax(int num,int min,int max)
{
    int Num=num;

    while(Num>max || Num<min)
    {
        printf("Entero no valido. Reingrese: ");
        scanf("%d", &Num);
    }
    return Num;
}


int buscarLugar(EMovie *moviesList,int tam)
{
    int index=-1, i;

    for(i=0; i<tam; i++)
        if((moviesList+i)->duracion==0)
        {
            index=i;
            break;
        }
    return index;
}


int subirPelicula(EMovie *moviesList, int* tam)
{
    int flag = 0;
    FILE *file;

    file=fopen("moviesData.dat", "rb");
    if(file==NULL)
    {
        file= fopen("moviesData.dat", "wb");
        if(file==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag==0)
    {
        fread(tam,sizeof(int),1,file);
        while(!feof(file))
        {
            fread(moviesList,sizeof(EMovie),*tam,file);
        }
    }
    fclose(file);
    return 0;
}


void agregarPelicula(EMovie *moviesList,int tam,int* tamP)
{
    int ubicacion, disponible=0, i, duracion, puntaje, largoTitulo;
    char auxTitulo[50], auxGenero[50], auxDescripcion[150], linkImagen[250];

    ubicacion=tam-1;
    printf("\nNUEVA PELICULA\nTitulo: ");
    fflush(stdin);
    gets(auxTitulo);
    validarString(auxTitulo,50);
    largoTitulo=strlen(auxTitulo);
    for(i=0; i<largoTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }

    for(i=0; i<tam; i++)
    {
        if(strcmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            disponible=1;
            break;
        }
    }

    if(!disponible)
    {
        strcpy((moviesList+ubicacion)->titulo,auxTitulo);
        printf("Genero: ");
        fflush(stdin);
        gets(auxGenero);
        validarString(auxGenero,50);
        strcpy((moviesList+ubicacion)->genero,auxGenero);
        printf("Descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);
        validarString(auxDescripcion,50);
        strcpy((moviesList+ubicacion)->descripcion,auxDescripcion);
        printf("Duracion (minutos): ");
        scanf("%d",&duracion);
        duracion=validoMinMax(duracion,0,400);
        (moviesList+ubicacion)->duracion=duracion;
        printf("Puntaje (1 a 10): ");
        scanf("%d",&puntaje);
        puntaje=validoMinMax(puntaje,1,10);
        (moviesList+ubicacion)->puntaje=puntaje;
        printf("Enlace de la imagen: ");
        fflush(stdin);
        gets(linkImagen);
        validarString(linkImagen,250);
        strcpy((moviesList+ubicacion)->linkImagen,linkImagen);
    }
    else
    {
        printf("ERROR: el titulo ingresado ya existe.\n");
        *tamP-=1;
    }
}


void modificaMovie(EMovie *moviesList,int tam)
{
    int flag=0, opcion, ubicacion, i, duracion, puntaje, largoTitulo, disponible=0;
    char auxTitulo[50], auxGenero[50], linkImagen[250], auxDescripcion[150];
    mostrarPeliculas(moviesList,tam);
    printf("\nMODIFICACION DE PELICULA\nTitulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    validarString(auxTitulo,50);
    largoTitulo=strlen(auxTitulo);
    for(i=0; i<largoTitulo; i++)
    {
        auxTitulo[i]=auxTitulo[i];
    }
    for(i=0; i<tam; i++)
    {
        if(stricmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            printf("\nModificando: %s\n", auxTitulo);

            mostrarPelicula((moviesList + i));
            ubicacion=i;
            printf("\nSe ha encontrado la pelicula. Indique que propiedad desea modificar.\n");
            printf("1. Titulo\n");
            printf("2. Genero\n");
            printf("3. Duracion\n");
            printf("4. Descripcion\n");
            printf("5. Puntaje\n");
            printf("6. Link a imagen\n");
            printf("7. Cancelar\n");
            printf("Opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("\nMODIFICACION\n");
                printf("Ingrese el titulo: ");
                fflush(stdin);
                gets(auxTitulo);
                validarString(auxTitulo,50);
                largoTitulo=strlen(auxTitulo);
                for(i=0; i<largoTitulo; i++)
                {
                    auxTitulo[i]=toupper(auxTitulo[i]);
                }

                for(i=0; i<tam; i++)
                {
                    if(strcmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
                    {
                        disponible=1;
                        break;
                    }
                }
                if(!disponible)//entra si disponible==0
                {
                    strcpy((moviesList+ubicacion)->titulo,auxTitulo);
                    printf("Titulo modificado.\n");
                }
                else
                {
                    printf("El titulo ingresado ya existe.\n");
                }
                break;
            case 2:
                printf("Nuevo genero: ");
                fflush(stdin);
                gets(auxGenero);
                validarString(auxGenero,50);
                strcpy((moviesList+ubicacion)->genero,auxGenero);
                printf("\nGenero modificado.\n");
                break;
            case 3:
                printf("Duracion (minutos): ");
                scanf("%d",&duracion);
                duracion=validoMinMax(duracion,0,400);
                (moviesList+ubicacion)->duracion=duracion;
                printf("\nDuracion modificada.\n");
                break;
            case 4:
                printf("Descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);
                validarString(auxDescripcion,250);
                strcpy((moviesList+ubicacion)->descripcion,auxDescripcion);
                printf("\nPDescripcion modificada.\n");
                break;
            case 5:
                printf("Puntaje: ");
                scanf("%d",&puntaje);
                puntaje=validoMinMax(puntaje,1,10);
                (moviesList+ubicacion)->puntaje=puntaje;
                printf("\nPuntaje modificado\n");
                break;
            case 6:
                printf("Enlace de la imagen: ");
                fflush(stdin);
                gets(linkImagen);
                validarString(linkImagen,250);
                strcpy((moviesList+ubicacion)->linkImagen,linkImagen);
                printf("\nEnlace de la imagen modificado.\n");
                break;
            case 7:
                break;
            default:
                printf("ERROR: Opcion invalida.\n");
                break;
            }

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se encontro la pelicula en la base de datos.\n");
    }
}


int borrarPelicula(EMovie *moviesList,int tam,int* tamP)
{
    int flag=0,i, largoTitulo;
    char opcion, titulo[50];
    mostrarPeliculas(moviesList,tam);
    printf("\nIngrese la pelicula a eliminar: ");
    fflush(stdin);
    gets(titulo);
    validarString(titulo,50);
    largoTitulo=strlen(titulo);
    for(i=0; i<largoTitulo; i++)
    {
        titulo[i]=toupper(titulo[i]);
    }
    for(i=0; i<tam; i++)
    {
        if(strcmp(titulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            printf("\nPelicula a eliminar:\n");

            mostrarPelicula((moviesList + i));

            printf("\nPelicula encontrada. Confirme la eliminacion (S/n): ");
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion=='s' || opcion=='S')
            {
                (moviesList+i)->duracion=0;
                printf("\n%s eliminada.\n", titulo);
                return 1;
            }
            else
            {
                printf("\n%s no ha sido eliminada.\n", titulo);
                return 0;
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("%s no esta registrada.\n", titulo);
        return 0;
    }
}


int guardar(EMovie* moviesList,int tam,int* tamP)
{

    FILE *file;
    file=fopen("moviesData.dat","wb");
    if(file == NULL)
    {
        return 1;
    }
    fwrite(tamP,sizeof(int),1,file);

    fwrite(moviesList,sizeof(EMovie),tamP,file);

    fclose(file);

    return 0;
}


void generarPagina(EMovie* moviesList, int tam)
{
    int i;
    FILE *file;
    file=fopen("index.html","w");
    if(file == NULL)
    {
        printf("El archivo no pudo ser creado.");
        exit(1);
    }
        fprintf(file,"<!DOCTYPE html>");
        fprintf(file,"<html lang='en'>");
        fprintf(file,"<head>");
            fprintf(file,"<title>Listado de peliculas</title>");
            fprintf(file,"<meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>");
            fprintf(file,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
            fprintf(file,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
            fprintf(file,"<link href='css/custom.css' rel='stylesheet'>");
        fprintf(file,"</head>");
        fprintf(file,"<body>");
            fprintf(file,"<div class='container'>");
            fprintf(file,"<div class='row'>");
            for(i=0; i<tam; i++)
            {
                if((moviesList+i)->duracion!=0)
                {
                    fprintf(file,"<article class='col-md-4 article-intro'>");
                    fprintf(file,"<a href='#'>");
                    fprintf(file,"<img class='img-responsive img-rounded' src='%s' alt='%s'></a>\n",(moviesList+i)->linkImagen,(moviesList+i)->titulo);
                    fprintf(file,"<h3 style='color:#2196f3'>%s</h3>\n",(moviesList+i)->titulo);
                    fprintf(file,"<ul><li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d mins</li></ul>\n",(moviesList+i)->genero,(moviesList+i)->puntaje,(moviesList+i)->duracion);
                    fprintf(file,"<p>%s</p></article>",(moviesList+i)->descripcion);
                }
            }
        fprintf(file,"</div></div>");
            fprintf(file,"<script src='js/jquery-1.11.3.min.js'></script>");
            fprintf(file,"<script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'>");
            fprintf(file,"</script><script src='js/holder.min.js'></script>");
        fprintf(file,"</body>");
        fprintf(file,"</html>");
    fclose(file);
}

#endif // FUNCTIONS_C_INCLUDED
