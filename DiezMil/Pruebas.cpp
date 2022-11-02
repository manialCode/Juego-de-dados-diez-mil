#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(int argc, const char **argv)
{

    int dado[6], i , puntaje = 0;
    int repeticionDeDado[6], comparePoints[8] = {0, 0, 0, 0, 0, 0, 0, 1};
    int numeroRepetido;

    while (puntaje != 10000)
    {
        std::cout << "Tu puntaje: "<< puntaje << std::endl;

        cargarVector(dado, 6);
        mostrarVector(dado, 6);

        for (i = 1; i <= 6; i++){
            repeticionDeDado[i] = contarNumerosRepetidos(dado, i, 6);
        }

        std::cout << "6 repetido" << repeticionDeDado[6] << std::endl;
        
        if (juegoDeUno(repeticionDeDado))
        {
            if(repeticionDeDado[1] == 1 && (puntaje + 100) <= 10000) puntaje += 100;
            if( repeticionDeDado[2] == 2 && (puntaje + 200) <= 10000) puntaje += 200;
            comparePoints[0] = puntaje;
        }
        
        if(juegoDeCinco(repeticionDeDado)){
            if(repeticionDeDado[5] == 1 && (puntaje + 50) <= 10000) 
                comparePoints[1] = puntaje + 50;
            if( repeticionDeDado[5] == 2 && (puntaje + 100) <= 10000)
                comparePoints[1] = puntaje + 100;
             
        }

        if(trioDeUno(repeticionDeDado)){
            if ((puntaje + 1000) <= 10000)
                comparePoints[2] = puntaje + 1000;
        }

        numeroRepetido = trioDeX(repeticionDeDado);
        if(numeroRepetido > 1){
            if ((puntaje + (numeroRepetido * 100)) <= 10000)
                comparePoints[3] = puntaje + (numeroRepetido * 100);
        }

        if(trioUnoAmpliado(repeticionDeDado)){
            if ((puntaje + 2000) <= 10000) 
                comparePoints[4] = puntaje + 2000;
        }

        if (escaleraLarga(repeticionDeDado))
        {
            if ((puntaje + 1500) <= 10000) 
                comparePoints[5] = puntaje + 1500;
        }

        if (sexteto(repeticionDeDado))
        {
            comparePoints[6] = 10000;
        }

        if(comparePoints[maximoVector(comparePoints, 8)] != 7)
            puntaje = comparePoints[maximoVector(comparePoints, 7)];
        else puntaje = 0;

        mostrar(maximoVector(comparePoints, 8));

        std::cout << std::endl;
    }
            std::cout << "Fin de partida" << std::endl;

    return 0;
}