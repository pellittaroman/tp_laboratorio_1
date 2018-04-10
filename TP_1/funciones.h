#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float suma(float,float);
/** \brief toma dos numeros float y los suma;
 *
 * \param operando numero 1;
 * \param operando numero 2;
 * \return resultado de la suma;
 *
 */

float resta(float,float);
/** \brief toma dos numeros y los restas;
 *
 * \param operando numero 1;
 * \param operando numero 2;
 * \return resultado de la resta;
 *
 */

float multiplica(float,float);
/** \brief toma dos numeros y los multiplica;
 *
 * \param operando numero 1;
 * \param operando numero 2;
 * \return producto;
 *
 */

float dividir(float,float);
/** \brief toma dos numeros y los divide;
 *
 * \param operando numero 1;
 * \param operando numero 2;
 * \return resultado;
 *
 */
float pedirNum();
/** \brief pide un numero por printf y lo asigna a una variable;
 * \param toma un numero flotante;
 * \return devuelve un float en una variable;
 *
 */

long int fact(float A);
/** \brief toma un numero lo factorea;
 *
 * \param el caso de ingresar 'x' factorea el primer operando;
 * \param el caso de ingresar 'y' factorea el segundo operando;
 * \return devuelve un factorial o error si el numero es demasiado grande;
 *
 */




#endif // FUNCIONES_H_INCLUDED
