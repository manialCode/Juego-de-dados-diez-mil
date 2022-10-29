#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

void onePlayer(char name[]);

void onePlayer(char name[])
{
    int arr[6], i = 1, onePlayerPoints = 0;
    int roundPoint = 0, rondaN = 0, numberOfRelease = 0;
    char vv;
    bool v = true;

    while (v)
    {
        system("cls");

        rondaN++;
        numberOfRelease++;

        std::cout << "TURNO DE " << name << " | "
                  << "RONDA N°" << rondaN << " | "
                  << "PUNTAJE TOTAL: " << onePlayerPoints << " PUNTOS" << std::endl;
        std::cout << "------------------------------------------------------------------ " << std::endl;
        std::cout << "PUNTAJE DE LA RONDA: " << roundPoint << std::endl;
        std::cout << "LANZAMIENTO N°" << numberOfRelease << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;

        cargarAleatorio(arr, 6, 6);
        mostrarVector(arr, 6);

        std::cout << std::endl;
        std::cout << std::endl
        
        ///start editing from from here
        
        std::cout << std::endl;
        std::cout << std::endl
        std::cout << "¿CONTINUAR LANZANDO (S/N)?: ";
        std::cin >> vv;

        if (vv == 'S' || vv == 's')
            v = true;
        if (vv == 'N' || vv == 'n')
            v = false;

        system("cls");
    }

}

#endif