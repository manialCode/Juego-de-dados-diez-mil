#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <locale.h>
#include <conio.h>
#include "funciones.h"
#include "juego.h"
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");

    int minRound = 0, maxScore = 0;
    char playerOne[30], playerTwo[30];
    int option = 0, *scoreMatch = 0;
    while (option != 5)
    {
        option = 0;
        system("cls");
        cout << "         ||MENU||          " << endl;
        cout << "" << endl;
        cout << "->  1.   1 jugador         <-" << endl;
        cout << "->  2.   2 jugadores       <-" << endl;
        cout << "->  3.   Valor máximo      <-" << endl;
        cout << "->  4.   Reglas            <-" << endl;
        cout << "->  5.   Fin del programa  <-" << endl;

        std::cout << std::endl;
        std::cout << "Ingrese la opción: ";
        cin >> option;

        switch (option)
        {

        case 1:

            printf("Por favor, ingrese el nombre del jugador uno: ");
            cargarCadena(playerOne, 30);

            scoreMatch = onePlayer(playerOne);

            break;

        case 2:
            printf("Por favor, ingrese el nombre del jugador uno: ");
            cargarCadena(playerOne, 30);
            
            printf("Por favor, ingrese el nombre del jugador dos: ");
            cargarCadena(playerTwo, 30);

            break;

        case 3:
            if (scoreMatch != 0)
            {
                if (*(scoreMatch + 2) == 1)
                    std::cout << "Nombre: " << playerOne << std::endl;

                if (*(scoreMatch + 2) == 2)
                    std::cout << "Nombre: " << playerTwo << std::endl;

                if (maxScore == 0 || *scoreMatch > maxScore || *scoreMatch == 10000)
                    maxScore = *scoreMatch;
                std::cout << "Puntaje: " << maxScore << std::endl;

                if (minRound == 0 || (*(scoreMatch + 1)) < minRound)
                    minRound = *(scoreMatch + 1);
                std::cout << "Rondas Jugadas: " << minRound << std::endl;
            }
            else
                std::cout << "No hubo partidas registradas" << std::endl;
            system("pause");
            break;

        case 4:
            system("cls");
            reglas();
            system("pause");
            break;

        case 5:
            system("cls");
            cout << " ----------------" << endl;
            cout << "|Fin del programa|" << endl;
            cout << " ----------------";
            break;
        default:
            cout << "la opción elegida no es valida";
            option = 0;
            system("pause");
            break;
        }
    }

    cout << endl;
    system("pause");
    return 0;

    return 0;
}
