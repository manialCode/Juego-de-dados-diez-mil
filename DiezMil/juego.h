#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

bool juegoDeUno(int combinacion[]);
bool juegoDeCinco(int combinacion[]);
bool trioDeUno(int combinacion[]);
int trioDeX(int combinacion[]);
bool trioUnoAmpliado(int combinacion[]);
bool escaleraLarga(int combinacion[]);
bool sexteto(int combinacion[]);
void mostrar(int combinacionGanadora);
void onePlayer(char name[]);
void reglas();

void reglas(){
    std::cout << "                   ||REGLAS DEL JUEGO||                    " << endl;
            std::cout << "" << endl;
            std::cout << "- El objetivo del juego es obtener 10000 puntos en la menor cantidad de rondas posibles. Una ronda puede estar compuesta por varios lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje." << endl;
            std::cout << "" << endl;
            std::cout << "- El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la sección Combinaciones ganadoras." << endl;
            std::cout << "" << endl;
            std::cout << "" << endl;
            std::cout << "- Si en un lanzamiento el jugador obtiene una combinación ganadora entonces acumulará provisoriamente el puntaje correspondiente." << endl;
            std::cout << "" << endl;
            std::cout << "- Luego de un lanzamiento ganador, el jugador debe elegir si desea volver a lanzar los dados o asegurarse el puntaje acumulado hasta el momento. Si en un lanzamiento el jugador no obtiene una combinación ganadora perderá todo el puntaje acumulado de esa ronda y será el turno del otro jugador." << endl;
            std::cout << "" << endl;
            std::cout << "- Esta es la razón por la que seguir lanzando es riesgoso. La posibilidad de hacer más puntos debe ser considerada con el riesgo de perder todo lo que se ganá durante un turno." << endl;
            std::cout << "" << endl;
            std::cout << "- Una vez que un jugador decide finalizar el turno, todo el puntaje acumulado en el turno se acumulará al puntaje total del jugador." << endl;
            std::cout << "" << endl;
            std::cout << "- Cuando un jugador obtiene exactamente 10000 puntos, el juego termina. Si un jugador se excede de los 10000 puntos volverá al puntaje que tenía previamente al comenzar la ronda." << endl;
            std::cout << "" << endl;
            std::cout << "         ||EJEMPLO||          " << endl;
            std::cout << "" << endl;

            cout << "--  Si en el inicio de una ronda el jugador tiene 9000 puntos y en transcurso de la ronda termina obteniendo 1500 puntos, entonces, como el puntaje acumulado total superaráa los diez mil, la cantidad de puntos no variará, conservando los 9000 puntos que tenía al inicio.  --" << endl;
            system("pause");

}

void onePlayer(char name[])
{
    int dado[6], i = 1, j, puntaje = 0, roundPoints = 0;
    int roundPoint = 0, numberOfRelease = 0, comparePoints[8];
    char vv;
    bool v = true;
    int repeticionDeDado[6];
    int numeroRepetido;

        for(j = 1; j <= 10; j++){
        if(puntaje == 10000)j = 10;
        roundPoint = 0;

        while(v){

        system("cls");
        int comparePoints[8] = {0, 0, 0, 0, 0, 0, 0, 1};
        numberOfRelease++;

        std::cout << "TURNO DE " << name << " | "
                  << "RONDA N°" << j << " | "
                  << "PUNTAJE TOTAL: " << puntaje << " PUNTOS" << std::endl;
        std::cout << "------------------------------------------------------------------ " << std::endl;
        std::cout << "PUNTAJE DE LA RONDA: " << puntaje << std::endl;
        std::cout << "LANZAMIENTO N°" << numberOfRelease << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;

        cargarAleatorio(dado, 6, 6);
        mostrarVector(dado, 6);

        std::cout << std::endl;
        std::cout << std::endl;

        ///start editing from from here
         for (i = 1; i <= 6; i++){
            repeticionDeDado[i] = contarNumerosRepetidos(dado, i, 6);
        }

        if (juegoDeUno(repeticionDeDado))
        {
            if(repeticionDeDado[1] == 1 && (puntaje + 100) <= 10000) comparePoints[0] = 100;
            if( repeticionDeDado[2] == 2 && (puntaje + 200) <= 10000) comparePoints[0] = 200;
        }

        if(juegoDeCinco(repeticionDeDado)){
            if(repeticionDeDado[5] == 1 && (puntaje + 50) <= 10000)
                comparePoints[1] = 50;
            if( repeticionDeDado[5] == 2 && (puntaje + 100) <= 10000)
                comparePoints[1] = 100;

        }

        if(trioDeUno(repeticionDeDado)){
            if ((puntaje + 1000) <= 10000)
                comparePoints[2] = 1000;
        }

        numeroRepetido = trioDeX(repeticionDeDado);
        if(numeroRepetido > 1){
            if ((puntaje + (numeroRepetido * 100)) <= 10000)
                comparePoints[3] = (numeroRepetido * 100);
        }

        if(trioUnoAmpliado(repeticionDeDado)){
            if ((puntaje + 2000) <= 10000)
                comparePoints[4] = puntaje + 2000;
        }

        if (escaleraLarga(repeticionDeDado))
        {
            if ((puntaje + 1500) <= 10000)
                comparePoints[5] = 1500;
        }

        if (sexteto(repeticionDeDado))
        {
            comparePoints[6] = 10000;
        }


        if(maximoVector(comparePoints, 8) == 7){
            j++;
            roundPoint = 0;
        }

        mostrar(maximoVector(comparePoints, 8));
        roundPoint +=comparePoints[maximoVector(comparePoints, 7)];
        std::cout << roundPoint << std::endl;

        if(maximoVector(comparePoints, 8) == 7)v = false;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "¿CONTINUAR LANZANDO (S/N)?: ";
        std::cin >> vv;

        if (vv == 'S' || vv == 's'){
            v = true;

        }
        if (vv == 'N' || vv == 'n'){
            v = false;
             if(roundPoint + puntaje <= 10000)
            puntaje += roundPoint;
        }

        system("cls");
    }

    if(j < 10)v = true;

    }


}

bool juegoDeUno(int combinacion[]){
    if(combinacion[1] == 1 || combinacion[1] == 2) return true;
    else return false;
}

bool juegoDeCinco(int combinacion[]){
    if(combinacion[5] == 1 || combinacion[5] == 2) return true;
    else return false;
}

bool trioDeUno(int combinacion[]){
    if(combinacion[1] == 3)return true;
    else return false;
}

int trioDeX(int combinacion[]){
    int i, posLast;
    for(i = 2; i <= 6; i++)
        if (combinacion[i] >= 3)posLast = i;

    return posLast;
}

bool trioUnoAmpliado(int combinacion[]){
    if(combinacion[1] == 4 || combinacion[1] == 5) return true;
    else return false;
}

bool escaleraLarga(int combinacion[]){
    int i, c = 0;

    for (i = 1; i <= 6; i++)
        if(combinacion[i] == 1)c++;

        if(c == 6) return true;
        else return false;
}


bool sexteto(int conbinacion[]){
    if(conbinacion[1] == 6) return true;
    else return false;
}


void mostrar( int combinacionGanadora){
    switch (combinacionGanadora)
    {
    case 0:
        std::cout << "Juego de Uno" << std::endl;
        break;
    case 1:
        std::cout << "Juego de Cinco" << std::endl;
        break;
    case 2:
        std::cout << "Trio de 1" << std::endl;
        break;
    case 3:
        std::cout << "Trio de x++" << std::endl;
        break;

    case 4:
        std::cout << "Trio ampliado" << std::endl;
        break;
    case 5:
        std::cout << "Escalera Larga" << std::endl;
        break;
    case 6:
        std::cout << "SEXTETO" << std::endl;
        break;

    default:
        std::cout << "No hay combinacion ganadora" << std::endl;
        break;
    }
}


#endif
