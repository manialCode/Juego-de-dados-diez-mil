#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/* Usar en el main para que funcionen.
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
*/

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void cargarVector(int v[], int tam); /// asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam); /// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam); /// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[], int tam, int numero); /// devuelve la posicion que ocupa un numero que se //envía como parámetro. Devuelve la primera posicion que encuentra el numero. Si no lo encuentra devuelve -1
int contarNumerosRepetidos(int v[], int tam, int numero); /// cuenta la cantidad de veces que se repite un //n�mero en el vector

int maximoVector(int v[], int tam); /// devuelve  la posicion (primera) que ocupa el maximo en el vector

int minimoVector(int v[], int tam); /// devuelve  la posicion (primera) que ocupa el minimo en el vector

void cargarAleatorio(int v[], int tam, int limite); /// asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam); /// ordena de menor a mayor un vector

int sumarVector(int v[], int tam); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[], int tam); /// copia el vector v en v2

bool compararVectores(int v[], int v2[], int tam); // compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

void cargarCadena(char *palabra, int tamano);


int juegoDeUno(int combination[]);
int juegoDeCinco(int combination[]);
int trioDeUno(int combination[]);
int trioDeX(int combination[]);
int trioUnoAmpliado(int combination[]);
int escaleraLarga(int combination[]);
int sexteto(int combination[]);

/// Desarrollo de funciones / Definiciones
int posicionNumeroEnVector(int v[], int tam, int numero)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (v[i] == numero)
            return i;
    }
    return -1;
}
int minimoVector(int v[], int tam)
{
    int i, posMin = 0;
    for (i = 1; i < tam; i++)
    {
        if (v[i] < v[posMin])
        {
            posMin = i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam)
{
    int i, j, posmin, aux;
    for (i = 0; i < tam - 1; i++)
    {
        posmin = i;
        for (j = i + 1; j < tam; j++)
        {
            if (v[j] < v[posmin])
                posmin = j;
        }
        aux = v[i];
        v[i] = v[posmin];
        v[posmin] = aux;
    }
}

int maximoVector(int v[], int tam)
{
    int i, posMax = 0;
    for (i = 1; i < tam; i++)
    {
        if (v[i] > v[posMax])
        {
            posMax = i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {
        v[i] = (rand() % limite) + 1;
    }
}

void mostrarVector(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        std::cout << v[i] << "\t";
    }
}

int contarNumerosRepetidos(int v[], int numero, int tam)
{
    int i, cant = 0;
    for (i = 0; i < tam; i++)
    {
        if (v[i] == numero)
            cant++;
    }
    return cant;
}

void ponerCero(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = 0;
    }
}

int sumarVector(int v[], int tam)
{
    int i, suma = 0;
    for (i = 0; i < tam; i++)
    {
        suma += v[i];
    }
    return suma;
}

void copiarVector(int v[], int v2[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v2[i] = v[i];
    }
}

bool compararVectores(int v[], int v2[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (v2[i] != v[i])
            return false;
    }
    return true;
}

void cargarVector(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        std::cout << "INGRESE NUMERO: ";
        std::cin >> v[i];
    }
}

    void cargarCadena(char *palabra, int tamano)
    {
    int i = 0;
    fflush(stdin);

    for (i = 0; i < tamano; i++)
    {
        palabra[i] = std::cin.get();
        if (palabra[i] == '\n') break;
    }

    palabra[i] = '\0';

    fflush(stdin);
    }

int juegoDeUno(int combination[])
{
    if (combination[0] == 1)
        return 100;
    else if (combination[0] == 2)
        return 200;
    else
        return 0;
}

int juegoDeCinco(int combination[])
{
    if (combination[4] == 1)
        return 50;
    else if(combination[4] == 2)
        return 100;
    else return 0;
}

int trioDeUno(int combination[])
{
    if (combination[0] == 3)
        return 1000;
    else
        return 0;
}

int trioDeX(int combination[])
{
    int posLast = 0;
    for (int i = 1; i < 6; i++)
        if (combination[i] >= 3) posLast = i ;

    if(combination[posLast] >= 3)
        return (posLast + 1) * 100;
    else return 0;
}

int trioUnoAmpliado(int combination[])
{
    if (combination[0] == 4 || combination[0] == 5)
        return 2000;
    else
        return 0;
}

int escaleraLarga(int combination[])
{
    int i, c = 0;

    for (i = 0; i < 7; i++)
        if (combination[i] == 1)
            c++;

    if (c == 6)
        return 1500;
    else
        return 0;
}

int sexteto(int combination[])
{
    if (combination[0] == 6)
        return 10000;
    else
        return 0;
}


#endif // FUNCIONES_H_INCLUDED
