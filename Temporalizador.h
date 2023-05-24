#pragma once
#include <SFML/Graphics.hpp>

/*

El constructor Timer recibe los minutos y segundos iniciales del temporizador y los inicializa.
El m�todo update actualiza el tiempo restante cada vez que se llama. Utiliza la clase sf::Clock de SFML para obtener el tiempo transcurrido desde la �ltima actualizaci�n y lo resta del tiempo total.
El m�todo draw dibuja el temporizador en una ventana de SFML.
El m�todo isTimeUp verifica si el tiempo ha llegado a cero.
El m�todo getElapsedSeconds devuelve la cantidad de segundos transcurridos desde el inicio del temporizador.
El m�todo addTime permite agregar tiempo adicional al temporizador.
El m�todo reset reinicia el temporizador al tiempo inicial.
Recuerda adaptar este c�digo a tu proyecto y asegurarte de tener la fuente de texto (font.ttf) en la ubicaci�n correcta. Tambi�n puedes ajustar el dise�o y la apariencia del temporizador seg�n tus necesidades.


*/

class Temporalizador{

private:

    bool _estaCorriendo;
    int  _tiempoTotal;
    int  _tiempoRestante;
    sf::Clock clock;
    sf::Font  font;
    sf::Text  text;


public:

    Temporalizador(int minutos, int segundos);

    void actualizar();
    void actualizarTiempo();
    void dibujar(sf::RenderWindow& window);
    bool tiempoTerminado();
    int  tiempoTranscurrido();
    int  segundosTranscurridos();
    void agregarTiempo(int minutos, int segundos);
    void tiempoTotal(int minutos, int segundos);
    void parar();
    void reiniciar();

    void setTiempoTotal();
    void setTiempoRestante(int segundos);


    int  getTiempoRestante();
    int  getTiempoTotal();





};
