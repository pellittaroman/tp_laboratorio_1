#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
    int ocupado;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * param lista: el array se pasa como parametro.
 */
int obtenerEspacioLibre(ePersona [],int);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista: el array se pasa como parametro. dni: el dni a ser buscado en el array.
 */
int buscarPorDni(ePersona [], int,int);
/**
 *
 * Inicia todos los elementos del array en 1 para saber que estan disponibles.
 * param: el array y su tamaño.
 */
void inicializarPersona(ePersona [],int );
/**
 *
 * muestra los datos de la persona en el indice indicado.
 * param:el array y el indice a mostrar.
 *
 *
 */
void mostrarPersona(ePersona [],int );
/**
 *  Permite dar el alta a nueva persona si es que hay lugar en el array.
 * \param un array de tipo de la estructura.
 * \param int con el tamaño del array.
 *
 */
void altas(ePersona[], int);
/**
 *  Permite dar el baja a la persona si es que se encuentra en el array.
 * \param un array de tipo de la estructura.
 * \param int con el tamaño del array.
 *
 */
void baja(ePersona [],int);
/**
 *  Ordena de menor a mayor los nombre de las personas que encuentran en el array.
 * \param un array de tipo de la estructura.
 * \param int con el tamaño del array.
 *
 */
void ordenarPersona(ePersona [],int );
/**
 *  imprime en pantalla un grafico de barras.
 * \param un array de tipo de la estructura.
 * \param int con el tamaño del array.
 *
 */
void grafico(ePersona [],int);
/**
 *  muestra una lista con todas las personas dadas de altas dentro del array.
 * \param un array de tipo de la estructura.
 * \param int con el tamaño del array.
 *
 */
void lista(ePersona[],int);
/**
 *
 * muestra el menu para que el usuario elija una opcion.
 * return el numero de opcion seleccionado.
 *
 */
int menu();



#endif // LIBRERIA_H_INCLUDED
