#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

#define TAM 20



int main()
{
    ePersona personas[20];
    inicializarPersona(personas,TAM);
    char seguir='s';
    while(seguir=='s')
    {
        switch(menu())
            {
                case 1:
                    altas(personas,TAM);
                    system("PAUSE");
                    break;
                case 2:
                    baja(personas,TAM);
                    system("PAUSE");
                    break;
                case 3:
                    lista(personas,TAM);
                    system("PAUSE");
                    break;
                case 4:
                    grafico(personas,TAM);
                    system("PAUSE");
                    break;
                case 5:
                    seguir = 'n';
                    break;
            }
    }
            return 0;
}
