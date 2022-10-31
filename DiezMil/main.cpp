#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <locale.h>
#include <conio.h>

#include <string.h>

using namespace std;
#include "funciones.h"
#include "juego.h"

int main()
{
    setlocale(LC_ALL, "spanish");

    char playerOne[30];
    int opcion = 0;
    while (opcion != 5)
    {
        system("cls");
        cout << "         ||MENU||          " << endl;
        cout << "" << endl;
        cout << "->  1.   1 jugador         <-" << endl;
        cout << "->  2.   2 jugadores       <-" << endl;
        cout << "->  3.   Mejor Jugador      <-" << endl;
        cout << "->  4.   Reglas            <-" << endl;
        cout << "->  5.   Fin del programa  <-" << endl;

        std::cout << std::endl;
        std::cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:

            printf("Por favor, ingrese el nombre del jugador uno: ");
            cargarCadena(playerOne, 30);

            onePlayer(playerOne);

            break;

        case 2:

            break;

        case 3:
            ///Mejor Jugador
            break;

        case 4:
            system("cls");
            reglas();
             break;

        case 5:
            system("cls");
            cout << " ----------------" << endl;
            cout << "|Fin del programa|" << endl;
            cout << " ----------------";
            break;
        default:
            cout << "la opcion elegida no es valida";
            system("pause");
            break;
        }
    }

    cout << endl;
    system("pause");
    return 0;

    return 0;
}
