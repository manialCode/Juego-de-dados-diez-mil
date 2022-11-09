#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

void show(int winningCombination);
void onePlayer(char name[]);
void twoPlayer(char nameOne[], char nameTwo[]);
void reglas();

void reglas()
{
    std::cout << "                   ||REGLAS DEL JUEGO||                    " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- El objetivo del juego es obtener 10000 puntos en la menor cantidad de rondas posibles. Una ronda puede estar compuesta por varios lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la sección Combinaciones ganadoras." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- Si en un lanzamiento el jugador obtiene una combinación ganadora entonces acumulará provisoriamente el puntaje correspondiente." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- Luego de un lanzamiento ganador, el jugador debe elegir si desea volver a lanzar los dados o asegurarse el puntaje acumulado hasta el momento. Si en un lanzamiento el jugador no obtiene una combinación ganadora perderá todo el puntaje acumulado de esa ronda y será el turno del otro jugador." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- Esta es la razón por la que seguir lanzando es riesgoso. La posibilidad de hacer más puntos debe ser considerada con el riesgo de perder todo lo que se gana durante un turno." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- Una vez que un jugador decide finalizar el turno, todo el puntaje acumulado en el turno se acumulará al puntaje total del jugador." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "- Cuando un jugador obtiene exactamente 10000 puntos, el juego termina. Si un jugador se excede de los 10000 puntos volverá al puntaje que tenía previamente al comenzar la ronda." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "         ||EJEMPLO||          " << std::endl;
    std::cout << "" << std::endl;

    std::cout << "--  Si en el inicio de una ronda el jugador tiene 9000 puntos y en transcurso de la ronda termina obteniendo 1500 puntos, entonces, como el puntaje acumulado total superará los diez mil, la cantidad de puntos no variará, conservando los 9000 puntos que tenía al inicio.  --" << std::endl;
    system("pause");
}

void onePlayer(char name[], int onePlayerMatch[])
{
    int dado[6], i = 1, j, score = 0, winnerRound;
    int roundPoint = 0, numberOfRelease = 0, comparePoints[8];
    bool v = true;
    for (j = 1; j <= 10; j++)
    {
        system("cls");

        roundPoint = 0;
        char vv;
        numberOfRelease = 0;

        while (v)
        {
            int diceRepetition[7] = {0, 0, 0, 0, 0, 0, 0};
            int comparePoints[8] = {0, 0, 0, 0, 0, 0, 0, 1};
            numberOfRelease++;

            // cargarAleatorio(dado, 6, 6);
            cargarVector(dado, 6);

            /// start editing from from here
            for (i = 1; i <= 6; i++)
                diceRepetition[i] = contarNumerosRepetidos(dado, i, 7);

            comparePoints[0] = juegoDeUno(diceRepetition);
            comparePoints[1] = juegoDeCinco(diceRepetition);
            comparePoints[2] = trioDeUno(diceRepetition);
            comparePoints[3] = trioDeX(diceRepetition);
            comparePoints[4] = trioUnoAmpliado(diceRepetition);
            comparePoints[5] = escaleraLarga(diceRepetition);
            comparePoints[6] = sexteto(diceRepetition);

            int bestCombination = comparePoints[maximoVector(comparePoints, 7)];
            int highestCombination = maximoVector(comparePoints, 8);

            roundPoint += bestCombination;
            
            std::cout << "TURNO DE " << name << " | "
                      << "RONDA N°" << j << " | "
                      << "PUNTAJE TOTAL: " << score << " PUNTOS" << std::endl;
            std::cout << "------------------------------------------------------------------ " << std::endl;
            std::cout << "PUNTAJE DE LA RONDA: " << roundPoint << std::endl;
            std::cout << "LANZAMIENTO N°" << numberOfRelease << std::endl;
            std::cout << "------------------------------------------------------------------" << std::endl;

            mostrarVector(dado, 6);

            std::cout << std::endl;
            std::cout << std::endl;

            if (highestCombination < 7)
            {
                std::cout << "Obtuviste ";
                show(highestCombination);
                if (highestCombination == 6)
                {
                    std::cout << " Has ganado la partida " << std::endl;
                    score = 0;
                    roundPoint = 10000;
                }
                else std::cout << " + " << bestCombination << " puntos!" << std::endl;
            }
            else
            {
                show(highestCombination);
                roundPoint = 0;
            }

            if (roundPoint != 10000 && roundPoint + bestCombination > 10000)
            {
                system("cls");
                std::cout << "Fin de ronda, por exceder el máximo puntaje acumulable" << std::endl;
                roundPoint = 0;
                system("pause");
                system("cls");
                break;
            }

            std::cout << std::endl;
            std::cout << std::endl;

            vv = 'n';
            if (highestCombination != 7 && roundPoint < 10000)
            {
                std::cout << "¿CONTINUAR LANZANDO (S/N)?: ";
                std::cin >> vv;
            }

            if (vv == 'S' || vv == 's')
                v = true;

            if (vv == 'N' || vv == 'n')
            {
                if (roundPoint + score <= 10000) score += roundPoint;
                v = false;
                system("pause");
            }

            if (score == 10000)
            {
                winnerRound = j;
                v = false;
                j = 11;
            }
            system("cls");
        }
        if (j <= 10)
            v = true;
    }

    onePlayerMatch[0] = score;
    onePlayerMatch[1] = winnerRound;
    onePlayerMatch[2] = 0;
}

void twoPlayer(char nameOne[], char nameTwo[], int onePlayerMatch[])
{
    int p = 0, winnerRound;
    int dado[6], i, j, score[2] = {0, 0}, roundPoint[2];
    int numberOfRelease[2], comparePoints[8];
    bool v = true;
    for (j = 1; j <= 10; j++)
    {
        system("cls");

        char vv;
        ponerCero(numberOfRelease, 2);
        ponerCero(roundPoint, 2);

        while (v)
        {
            int diceRepetition[7] = {0, 0, 0, 0, 0, 0, 0};
            int comparePoints[8] = {0, 0, 0, 0, 0, 0, 0, 1};
            numberOfRelease[p]++;

            // cargarAleatorio(dado, 6, 6);
            cargarVector(dado, 6);

            /// start editing from from here
            for (i = 1; i <= 6; i++)
                diceRepetition[i] = contarNumerosRepetidos(dado, i, 7);

            comparePoints[0] = juegoDeUno(diceRepetition);
            comparePoints[1] = juegoDeCinco(diceRepetition);
            comparePoints[2] = trioDeUno(diceRepetition);
            comparePoints[3] = trioDeX(diceRepetition);
            comparePoints[4] = trioUnoAmpliado(diceRepetition);
            comparePoints[5] = escaleraLarga(diceRepetition);
            comparePoints[6] = sexteto(diceRepetition);

            int bestCombination = comparePoints[maximoVector(comparePoints, 7)];
            int highestCombination = maximoVector(comparePoints, 8);
            roundPoint[p] += bestCombination;

            if (p == 0)
                std::cout << "TURNO DE " << nameOne << " | ";
            else
                std::cout << "TURNO DE " << nameTwo << " | ";
            std::cout << "RONDA N°" << j << " | "
                      << "PUNTAJE TOTAL: " << score[p] << " PUNTOS" << std::endl;
            std::cout << "------------------------------------------------------------------ " << std::endl;
            std::cout << "PUNTAJE DE LA RONDA: " << roundPoint[p] << std::endl;
            std::cout << "LANZAMIENTO N°" << numberOfRelease[p] << std::endl;
            std::cout << "------------------------------------------------------------------" << std::endl;

            mostrarVector(dado, 6);

            std::cout << std::endl;
            std::cout << std::endl;

            if (highestCombination < 7)
            {
                std::cout << "Obtuviste ";
                show(highestCombination);
                if (highestCombination == 6)
                {
                    std::cout << " Has ganado la partida " << std::endl;
                    score[p] = 0;
                    roundPoint[p] = 10000;
                }
                else std::cout << " + " << bestCombination << " puntos!" << std::endl;
            }
            else
            {
                show(highestCombination);
                roundPoint[p] = 0;
            }

            if (roundPoint[p] != 10000 && roundPoint[p] > 10000)
            {
                system("cls");
                std::cout << "Fin de ronda, por exceder el máximo puntaje acumulable" << std::endl;
                system("pause");
            }

            std::cout << std::endl;
            std::cout << std::endl;

            vv = 'n';
            if (highestCombination != 7 && roundPoint[p] < 10000)
            {
                std::cout << "¿CONTINUAR LANZANDO (S/N)?: ";
                std::cin >> vv;
            }

            if (vv == 'S' || vv == 's')v = true;

            if (vv == 'N' || vv == 'n')
            {
                if (roundPoint[p] + score[p] <= 10000) score[p] += roundPoint[p];
                if(score[p] == 10000)p = 2;
                else p++;
                system("pause");
            }

            if (p >= 2)v = false;

            system("cls");
        }

        p = 0;
        if (j <= 10)
            v = true;

        if (score[0] == 10000 || score[1] == 10000)
        {
            winnerRound = j;
            j = 11;
            v = false;
        }
    }

    p = maximoVector(score, 2);
    
    std::cout << winnerRound << std::endl;
    system("pause");
      
      onePlayerMatch[0] = score[p];
      onePlayerMatch[1] = winnerRound;
      onePlayerMatch[2] = p;
}

void show(int winningCombination)
{
    switch (winningCombination)
    {
    case 0:
        std::cout << "un Juego de Uno";
        break;
    case 1:
        std::cout << "un Juego de Cinco";
        break;
    case 2:
        std::cout << "un Trio de 1";
        break;
    case 3:
        std::cout << "un Trio de x++";
        break;

    case 4:
        std::cout << "un Trio ampliado";
        break;
    case 5:
        std::cout << "una Escalera Larga";
        break;
    case 6:
        std::cout << "UN SEXTETO";
        break;

    default:
        std::cout << "No hay combinación ganadora";
        break;
    }
}

#endif