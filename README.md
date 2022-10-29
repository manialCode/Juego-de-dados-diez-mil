# Juego-de-dados-diez-mil
Diez mil  Se deberá realizar una variante al juego de dados denominado Diez mil, que es un juego que puede desarrollarse para un jugador o dos jugadores.
El programa debe contar con un menú principal que permita iniciar un juego nuevo para un jugador, un juego nuevo para dos jugadores o guardar la puntuación más alta.

Juego nuevo para un jugador
Esta opción permite a un solo jugador realizar una partida completa de Diez mil. Antes de comenzar a jugar deberá solicitar el nombre del jugador.
Una vez finalizada la partida, deberá mostrar el nombre del jugador y la cantidad de turnos o rondas que necesito para obtener el puntaje requerido.

Juego nuevo para dos jugadores
Esta opción permite a dos jugadores realizar una partida completa de Diez mil. Antes de comenzar a jugar deberá solicitar el nombre de los jugadores. Una vez finalizada la partida, deberá mostrar el nombre del jugador que haya ganado y la cantidad de turnos o rondas que necesito para obtener el puntaje requerido.

Mostrar puntuación más alta
Esta opción debe mostrar el nombre del jugador que haya finalizado el juego con la menor cantidad de rondas para obtener el puntaje requerido. Debe mostrar también la cantidad de rondas del juego ganador.

NOTA: Cabe aclarar que el sistema no tendrá la capacidad de guardar la puntuación en un archivo. Por lo que al salir del juego, se borrarán todos los datos de puntuación.

Reglamento del juego
El objetivo del juego es obtener 10000 puntos en la menor cantidad de rondas posibles. Una ronda puede estar compuesta por varios lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje.
El puntaje de un lanzamiento está determinado por una serie de reglas que figuran en la sección Combinaciones ganadoras.

Si en un lanzamiento el jugador obtiene una combinación ganadora entonces acumulará provisoriamente el puntaje correspondiente.
Luego de un lanzamiento ganador, el jugador debe elegir si desea volver a lanzar los dados o asegurarse el puntaje acumulado hasta el momento. Si en un lanzamiento el jugador no obtiene una combinación ganadora perderá todo el puntaje acumulado de esa ronda y será el turno del otro jugador.
Esta es la razón por la que seguir lanzando es riesgoso. La posibilidad de hacer más puntos debe ser considerada con el riesgo de perder todo lo que se ganó durante un turno.
Una vez que un jugador decide finalizar el turno, todo el puntaje acumulado en el turno se acumulará al puntaje total del jugador.
Cuando un jugador obtiene exactamente 10000 puntos, el juego termina. Si un jugador se excede de los 10000 puntos volverá al puntaje que tenía previamente al comenzar la ronda.

Ejemplo:
Si en el inicio de una ronda el jugador tiene 9000 puntos y en transcurso de la ronda termina obteniendo 1500 puntos, entonces, como el puntaje acumulado total superaría los diez mil, la cantidad de puntos no variará, conservando los 9000 puntos que tenía al inicio.

Interfaz
Durante el turno de un jugador
Se deberá mostrar el nombre del jugador, el número de ronda, el puntaje total que lleva acumulado. Luego se deberá mostrar dentro de la ronda el puntaje provisorio que lleva acumulado y la cantidad de lanzamientos.
Más abajo, se deberán listar los dados que conforman el lanzamiento y de obtener una combinación ganadora, el nombre de la combinación y el puntaje otorgado.

TURNO DE ANGEL |  RONDA N° 3  | PUNTAJE TOTAL: 6500 PUNTOS
------------------------------------------------------------------
PUNTAJE DE LA RONDA: 500 PUNTOS
LANZAMIENTO N° 2
------------------------------------------------------------------
⚀⚁⚂⚃⚄⚅
 ¡ OBTUVISTE UNA ESCALERA LARGA ! +1500 PUNTOS

 ¿CONTINUAR LANZANDO (S/N)?

NO ES OBLIGATORIO QUE SE MUESTREN LOS DADOS POR PANTALLA. ES SUFICIENTE QUE SE MUESTREN LOS NÚMEROS DE LOS DADOS.

Entre turnos
Cuando finaliza un turno y comienza el otro, deberá mostrar una pantalla que indique a quién le corresponde el próximo turno, el número de ronda y los puntajes de ambos jugadores. En el caso de que sea un juego para un jugador, debe indicar el número de ronda, el nombre del jugador y el puntaje.




RONDA N° 3
PRÓXIMO TURNO: DANIEL

PUNTAJE ANGEL : 6500 PUNTOS
PUNTAJE DANIEL: 4500 PUNTOS






PRESIONAR UNA TECLA PARA CONTINUAR...


Ganador
Cuando un jugador gana la partida, se deberá mostrar una pantalla que indique el nombre y apellido del ganador y la cantidad de rondas que llevó ganar la partida.
El ganador de la partida es aquel jugador que haya obtenido los 10000 puntos primero.

Características opcionales
1 - Existe la posibilidad de empate. Esto ocurre cuando ambos jugadores logran los diez mil puntos en la misma ronda. 

2 - Si luego de diez rondas no hubo ningún jugador que haya obtenido los 10000 puntos. El ganador de la partida será aquel que haya obtenido el puntaje más alto.

Nivel obligatorio para aprobar: Modo 1 jugador

Para acceder a la puntuación máxima:
Modo de dos jugadores
Solicitar los nombres de los jugadores
