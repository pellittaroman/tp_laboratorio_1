#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"



int setId(eProducto* productos,int id)
{
    int retorno=-1;
    if(productos!=NULL&&id>0)
    {
        productos->id=id;
        retorno=0;
    }
    return retorno;

}
int get_id(eProducto* productos)
{
    int id=-1;
    if(productos!=NULL)
    {
       id=productos->id;
    }
    return id;
}
int setName(eProducto* producto, char descripcion[20] )
{
    int retorno=-1;

    if(producto!=NULL)
    {
        strcpy(producto->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}
char* getName(eProducto* producto)
{
    char* aux;
    aux=(char*)malloc(sizeof(char)*50);
    if(producto!=NULL)
    {
        strcpy(aux,producto->descripcion);
    }
    return aux;

}
int setCantidad(eProducto* productos,int cantidad)
{
    int retorno=-1;
    if(productos!=NULL)
    {
        productos->cantidad=cantidad;
        retorno=0;
    }
    return retorno;

}


int getCantidad(eProducto* productos)
{
    int cantidad=0;
    if(productos!=NULL)
    {
       cantidad=productos->cantidad;
    }
    return cantidad;
}
eProducto* newProducto()
{
    eProducto* aux;
    aux=(eProducto*)malloc(sizeof(eProducto));
    if(aux!=NULL)
    {
        aux->id=-1;
        strcpy(aux->descripcion,"");
        aux->cantidad=0;


    }
    else
    {
        printf("no se pudo crear por falta de memoria");

    }
    return aux;
}
int parserProductos(ArrayList* producto,char* path)
{
    char buffer [10],buffer1 [20],buffer2 [30];
    int cant,retorno=1;
    FILE* archivo;
    eProducto* aux;
    archivo=fopen(path,"r");
    if(archivo==NULL||producto==NULL)
    {
        printf("ERROR al leer archivo");
        exit(1);
    }
    else
    {
        while(!feof(archivo))
        {
            aux=newProducto();
            cant=fscanf(archivo,"%[^,],%[^,],%[^\n]",buffer,buffer1,buffer2);
            if(cant!=3)
            {
                if(feof(archivo))
                {
                    printf("se realizo lectura\n");
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Error de lectura de archivo");
                    retorno=1;
                    break;

                }
            }

            else
            {
                setId(aux,atoi(buffer));
                setName(aux,buffer1);
                setCantidad(aux,atoi(buffer2));
                retorno=0;
            }
            al_add(producto,aux);

        }
        fclose(archivo);
}
}

int guardarArchivo (ArrayList* producto, char* path)
{
    FILE* f;
    eProducto* aux;
    int retorno=-1;
    int i;
    int tam=producto->len(producto);


    if(producto!=NULL)
    {
        f= fopen(path,"w");
        if(f!=NULL)
        {
        for(i=0;i<tam;i++)
        {
                aux =producto->get(producto, i);
            //fprintf(f,"%d\t  %10s\t   %15s\t%d\t%d\n", get_id(aux),getName(aux),getAdress(aux),getHours(aux),getSalary(aux));
            //fprintf(f,"%d;  %10s;   %15s;%d;%d\n", get_id(aux),getName(aux),getAdress(aux),getHours(aux),getSalary(aux));
                fprintf(f,"%d;", get_id(aux));
                fprintf(f,"%s;", getName(aux));
                fprintf(f,"%d;", getCantidad(aux));



        }
        retorno=0;
        }
        fclose(f);
    }

    return retorno;
}

void printProducto(eProducto* producto)
{
    if(producto != NULL)
    {

        printf(" %2d      %25s        %6d\n", get_id(producto), getName(producto), getCantidad(producto));

    }
    else
    {
        printf("No se pudo leer el producto\n");
    }
}
void printProductosAll(ArrayList* producto)
{
    int i,tam=producto->len(producto);
    eProducto* aux;
    for(i=0;i<tam;i++)
    {
        aux=newProducto();
        aux=producto->get(producto,i);
        printProducto(aux);
    }
}
int menu()
{
    system("cls");
    int opcion;
    printf("1.Cargar deposito\n2.Listar deposito\n3.Mover Productos de deposito\n4.Descontar producto de deposito\n5.Agregar productos a deposito\n6.Salir\nElija opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
void cargar(ArrayList* deposito1,ArrayList* deposito2,char*path,char*path1)
{
     parserProductos(deposito1,path);
    parserProductos(deposito2,path1);
}
void Listar(ArrayList* deposito1,ArrayList* deposito2)
{
            system("cls");
            int opcion;
            printf("Elija deposito: ");
            scanf("%d",&opcion);
            if(opcion==1)
            {
                system("cls");
                printProductosAll(deposito1);
                system("pause");
            }
            else
            {
                if(opcion==2)
                {
                    system("cls");
                    printProductosAll(deposito2);
                    system("pause");
                }
                else
                {
                    printf("Error de opcion");
                    system("pause");

                }
            }
}
void mover (ArrayList* deposito1,ArrayList* deposito2,char*path,char*path1)
{
    FILE* dep1=fopen(path,"w");
    FILE* dep2=fopen(path1,"w");
    int opcion,i,index=-1,destino,id,tam=deposito1->len(deposito1),tam1=deposito2->len(deposito2);
    eProducto* aux=newProducto();
    if(dep1==NULL||dep2==NULL||deposito1==NULL||deposito2==NULL)
    {
        printf("Error de escritura");
    }
    else
    {
        printf("Ingrese deposito de origen: ");
        scanf("%d",&opcion);

        while(opcion!=1&&opcion!=2)
        {
            printf("Ingrese nuevamente deposito de origen: ");
            scanf("%d",&opcion);
        }
        printf("Ingrese deposito de destino: ");
        scanf("%d",&destino);
        while(destino!=1&&destino!=2||destino==opcion)
        {
            printf("Ingrese nuevamente deposito de destino: ");
            scanf("%d",&destino);
        }
        if(opcion==1)
        {
            printProductosAll(deposito1);
            printf("Ingrese codigo de producto: ");
            scanf("%d",&id);
            for(i=0;i<tam;i++)
            {
                aux=deposito1->get(deposito1,1);
                if(id==aux->id)
                {
                    index=i;
                }
            }
            if(index==-1)
            {
                printf("Error de codigo");
                exit(1);
            }
            aux=deposito1->pop(deposito1,index);
            if(aux==NULL)
            {
                printf("Error de producto");
            }
            else
            {
                deposito1->add(deposito2,aux);
                guardarArchivo(deposito1,dep1);
                guardarArchivo(deposito2,dep2);
            }

        }
        else
        {
            if(opcion==2)
            {
                  printProductosAll(deposito2);
            printf("Ingrese codigo de producto: ");
            scanf("%d",&id);
            for(i=0;i<tam1;i++)
            {
                aux=deposito1->get(deposito2,1);
                if(id==aux->id)
                {
                    index=i;
                }
            }
            if(index==-1)
            {
                printf("Error de codigo");
                exit(1);
            }
            aux=deposito1->pop(deposito2,index);
            if(aux==NULL)
            {
                printf("Error de producto");
            }
            else
            {
                deposito1->add(deposito1,aux);
                guardarArchivo(deposito1,dep1);
                guardarArchivo(deposito2,dep2);
            }
            }

        }

    }
        fclose(dep1);
        fclose(dep2);
}

void descontar(ArrayList* deposito1,ArrayList* deposito2,char*path,char*path1)
{
    FILE* dep1=fopen(path,"w");
    FILE* dep2=fopen(path1,"w");
    int opcion,i,index=-1,destino,id,tam=deposito1->len(deposito1),tam1=deposito2->len(deposito2);
    eProducto* aux=newProducto();
    if(dep1==NULL||dep2==NULL||deposito1==NULL||deposito2==NULL)
    {
        printf("Error de escritura");
    }
    else
    {
        printf("Ingrese id de producto ");
        scanf("%d",&id);
        for(i=0;i<tam;i++)
        {
            aux=deposito1->get(deposito1,i);
            if(id==aux->id)
            {
                index=0;
                break;
            }
        }
            if(index==-1)
            {
                index==-2;
                for(i=0;i<tam1;i++)
                {
                    aux=deposito1->get(deposito2,i);

                    if(id==aux->id)
                    {
                        index=0;
                        break;
                    }
                }
            }
            if(index==-2)
            {
                printf("no se encontro producto");
                exit(1);
                system("pause");
            }
            printf("Ingrese cantidad a descontar: ");
            scanf("%d",&opcion);
            while(opcion>aux->cantidad)
            {
                printf("Error la cantidad supera el stock");
                 printf("Ingrese cantidad a descontar: ");
                scanf("%d",&opcion);
            }
            if(aux!=NULL)
            {
                aux->cantidad=aux->cantidad-id;
                guardarArchivo(deposito1,dep1);
                guardarArchivo(deposito2,dep2);
            }


        }
fclose(dep1);
    fclose(dep2);
}


void agregar(ArrayList* deposito1,ArrayList* deposito2,char*path,char*path1)
{
    FILE* dep1=fopen(path,"w");
    FILE* dep2=fopen(path1,"w");
    int opcion,i,index=-1,destino,id,tam=deposito1->len(deposito1),tam1=deposito2->len(deposito2);
    eProducto* aux=newProducto();
    if(dep1==NULL||dep2==NULL||deposito1==NULL||deposito2==NULL)
    {
        printf("Error de escritura");
    }
    else
    {
        printf("Ingrese id de producto ");
        scanf("%d",&id);
        for(i=0;i<tam;i++)
        {
            aux=deposito1->get(deposito1,i);
            if(id==aux->id)
            {
                index=0;
                break;
            }
        }
            if(index==-1)
            {
                index==-2;
                for(i=0;i<tam1;i++)
                {
                    aux=deposito1->get(deposito2,i);

                    if(id==aux->id)
                    {
                        index=0;
                        break;
                    }
                }
            }
            if(index==-2)
            {
                printf("no se encontro producto");
                exit(1);
                system("pause");
            }
            printf("Ingrese cantidad a agregar: ");
            scanf("%d",&opcion);

            if(aux!=NULL)
            {
                aux->cantidad=aux->cantidad+opcion;
                guardarArchivo(deposito1,dep1);
                guardarArchivo(deposito2,dep2);
            }


        }
 fclose(dep1);
    fclose(dep2);
}


