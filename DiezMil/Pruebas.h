#ifndef PRUEBAS_H_INCLUDED
#define PRUEBAS_H_INCLUDED

bool juegoDeUno(int combinacion[]);
bool juegoDeCinco(int combinacion[]);
bool trioDeUno(int combinacion[]);
int trioDeX(int combinacion[]);
bool trioUnoAmpliado(int combinacion[]);
bool escaleraLarga(int combinacion[]);
bool sexteto(int combinacion[]);
void mostrar(int combinacionGanadora);


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