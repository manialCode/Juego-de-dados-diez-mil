#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

void unJugador(char nombre[]);

void unJugador(char nombre[])
{
    int arr[6], i = 1, puntosJugador1 = 0;
    int puntajeRonda = 0, rondaN = 0, lanzamientoN = 0;
    char vv;
    bool v = true;

    while (v)
    {
        system("cls");

        rondaN++;
        lanzamientoN++;

        std::cout << "TURNO DE " << nombre << " | "
                  << "RONDA N°" << rondaN << " | "
                  << "PUNTAJE TOTAL: " << puntosJugador1 << " PUNTOS" << std::endl;
        std::cout << "------------------------------------------------------------------ " << std::endl;
        std::cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << std::endl;
        std::cout << "LANZAMIENTO N°" << lanzamientoN << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;

        cargarAleatorio(arr, 6, 6);
        mostrarVector(arr, 6);

        std::cout << std::endl;
        std::cout << std::endl
                  << "¿CONTINUAR LANZANDO (S/N)?: ";
        std::cin >> vv;

        if (vv == 'S' || vv == 's')
            v = true;
        if (vv == 'N' || vv == 'n')
            v = false;

        system("cls");
    }

}

#endif