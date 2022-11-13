#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>
#include <cstring>
#include "juego.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");

    int minRound = 0, maxScore = 0, bestRound[2], option = 0;
    char playerOne[30], playerTwo[30], bestPlayerName[30];
    int scoreMatch[3] = {0, 0, 0};

    while (option != 5)
    {
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
        system("cls");

        switch (option)
        {

        case 1:
            printf("Por favor, ingrese el nombre del jugador uno: ");
            cargarCadena(playerOne, 30);

            onePlayer(playerOne, scoreMatch);

            break;

        case 2:
            printf("Por favor, ingrese el nombre del jugador uno: ");
            cargarCadena(playerOne, 30);

            printf("Por favor, ingrese el nombre del jugador dos: ");
            cargarCadena(playerTwo, 30);

            twoPlayer(playerOne, playerTwo, scoreMatch);

            break;

        case 3:
            if (scoreMatch[0] != 0)
            {
                if (minRound == 0 || scoreMatch[1] < minRound)
                {
                    minRound = scoreMatch[1];

                    if (maxScore == 0 || scoreMatch[0] >= maxScore)
                        maxScore = scoreMatch[0];

                    if (scoreMatch[2] == 0)
                        memcpy(bestPlayerName, playerOne, 30);
                    else
                        memcpy(bestPlayerName, playerTwo, 30);
                }

                std::cout << "Nombre: " << bestPlayerName << std::endl;
                std::cout << std::endl;
                std::cout << "Puntaje: " << maxScore << std::endl;
                std::cout << std::endl;
                std::cout << "Rondas Jugadas: " << minRound << std::endl;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "No hubo partidas registradas" << std::endl;
                std::cout << std::endl;
            }
            system("pause");
            break;

        case 4:
            reglas();
            break;

        case 5:

            cout << " ----------------" << endl;
            cout << "|Fin del programa|" << endl;
            cout << " ----------------";
            break;

        default:
            std::cout << std::endl;
            cout << "la opción elegida no es valida";
            std::cout << std::endl;
            system("pause");
            break;
        }
    }

    cout << endl;
    system("pause");
    return 0;

    return 0;
}
