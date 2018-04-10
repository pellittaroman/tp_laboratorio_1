float suma(float,float);
float resta(float,float);
float multiplica(float,float);
float dividir(float,float);
long int fact(float A);
float pedirNum();

float suma(float A,float B)
{
    float resultado;
    resultado=A+B;

    return resultado;
}
float resta(float A,float B)
{
    float resultado;
    resultado=A-B;

    return resultado;
}
float multiplica(float A, float B)
{
    float resultado;
    resultado=A*B;

    return resultado;
}
float dividir(float A, float B)
{
    float divi;
    float resultado;
    if(B==0)
    {
        resultado=printf("Operacion no valida\n\n");
        return resultado;
    }
    else
    {
        divi=(float)A/B;
        resultado=printf("La division da: %.3f\n\n",divi);
        return resultado;
    }
    }

long int fact(float A)
{

    int resultado;
    float b;
    int fact=1;
    if(A>12.0)
    {
        resultado=-1;
    }
    else if (A<1)
    {
        resultado=-2;
    }
    else
    {
       for (b = A; b > 1; b--)
        {
        fact = fact * b;
        }
    resultado=fact;
    }
    return resultado;
}
float pedirNum()
{
    float retorno;
    printf("Ingrese Numero: ");
    scanf("%f",&retorno);


    return retorno;

}

