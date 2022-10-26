# include<iostream>
# include<cstdlib>

using namespace std;

int main(){

int opcion=0;
while(opcion!=5){
        system("cls");
cout<<"         ||MENU||          "<<endl;
cout<<""<<endl;
cout<<"->  1.   1 jugador         <-"<<endl;
cout<<"->  2.   2 jugadores       <-"<<endl;
cout<<"->  3.   Valor maximo      <-"<<endl;
cout<<"->  4.   Reglas            <-"<<endl;
cout<<"->  5.   Fin del programa  <-"<<endl;


cin>>opcion;

switch(opcion)
{
case 1:

break;

case 2:


break;

case 3:


break;

case 4:
    system("cls");
    cout<<"                   ||REGLAS DEL JUEGO||                    "<<endl;
    cout<<""<<endl;
cout<<"- El objetivo del juego es obtener 10000 puntos en la menor cantidad de rondas posibles. Una ronda puede estar compuesta por varios lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje."<<endl;
cout<<""<<endl;
cout<<"- El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la secci�n Combinaciones ganadoras."<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"- Si en un lanzamiento el jugador obtiene una combinaci�n ganadora entonces acumular� provisoriamente el puntaje correspondiente."<<endl;
cout<<""<<endl;
cout<<"- Luego de un lanzamiento ganador, el jugador debe elegir si desea volver a lanzar los dados o asegurarse el puntaje acumulado hasta el momento. Si en un lanzamiento el jugador no obtiene una combinaci�n ganadora perder� todo el puntaje acumulado de esa ronda y ser� el turno del otro jugador."<<endl;
cout<<""<<endl;
cout<<"- Esta es la razón por la que seguir lanzando es riesgoso. La posibilidad de hacer m�s puntos debe ser considerada con el riesgo de perder todo lo que se gan� durante un turno."<<endl;
cout<<""<<endl;
cout<<"- Una vez que un jugador decide finalizar el turno, todo el puntaje acumulado en el turno se acumular� al puntaje total del jugador."<<endl;
cout<<""<<endl;
cout<<"- Cuando un jugador obtiene exactamente 10000 puntos, el juego termina. Si un jugador se excede de los 10000 puntos volver� al puntaje que ten�a previamente al comenzar la ronda."<<endl;
cout<<""<<endl;
cout<<"         ||EJEMPLO||          "<<endl;
cout<<""<<endl;

cout<<"--  Si en el inicio de una ronda el jugador tiene 9000 puntos y en transcurso de la ronda termina obteniendo 1500 puntos, entonces, como el puntaje acumulado total superar�a los diez mil, la cantidad de puntos no variar�, conservando los 9000 puntos que ten�a al inicio.  --"<<endl;
system("pause");
break;

case 5:
system("cls");
cout<<" ----------------"<<endl;
cout<<"|Fin del programa|"<<endl;
cout<<" ----------------";
break;
default:
    cout<<"la opcion elegida no es valida";

}
}

cout<<endl;
system("pause");
return 0;
}
