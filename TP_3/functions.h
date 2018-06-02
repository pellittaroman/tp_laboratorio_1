#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[150];
    int puntaje;
    char linkImagen[250];
}EMovie;


/** \brief muestra las peliculas
 *
 * \param  EMovie*
 *
 */
void mostrarPelicula(EMovie *moviesList);


/** \brief valida que no sea demasiado largo el string
 *
 * \param  cadena de string, y la cantidad de caracteres.
 *
 */
void validarString(char valido[], int);


/** \brief valida el maximo de caracteres
 *
 * \param recibe el numero,el max y el minimo
 * \return 1 true, 0  false
 */
int validoMinMax(int ,int ,int );


/** \brief genera espacio en memoria dinamica.
 *
 * \param moviesList y cantidad
 * \return int 1 si consigue espacio.
 *
 */
int buscarLugar(EMovie *moviesList,int);


/** \brief Load from the binary file of the movies in dynamic memory
 *
 * \param moviesList EMovie*
 * \return int Returns 1 if the file could not be read or created | 0 if possible.
 *
 */
int subirPelicula(EMovie *moviesList,int*);


/** \brief agrega pelicula a memoria.
 *
 * \param puntero con la lista de peliculas, tamaño del array y tamaño
 * \return void
 *
 */
void agregarPelicula(EMovie *moviesList,int,int*);


/** \brief da un menu para modificar pelicula
 *
 * \param moviesList  y tamaño
 * \return void
 *
 */
 void modificaMovie(EMovie *moviesList,int);


/** \brief borrar pelicula
 *
 * \param moviesList, tam y lugar
 * \return 1 si se borro || 0 si no se pudo
 *
 */
int borrarPelicula(EMovie *moviesList,int,int*);


/** \brief genera pagina web.
 *
 * \param moviesList y tamaño
 * \return void
 *
 */
void generarPagina(EMovie* moviesList, int);


/** \brief guarda en un archivo dat
 *
 * \param moviesList
 * \return void
 *
 */
int guardar(EMovie* moviesList,int,int*);

#endif // FUNCIONES_H_INCLUDED
