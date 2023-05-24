#pragma once
#include <SFML/Graphics.hpp>

/*

El constructor Timer recibe los minutos y segundos iniciales del temporizador y los inicializa.
El método update actualiza el tiempo restante cada vez que se llama. Utiliza la clase sf::Clock de SFML para obtener el tiempo transcurrido desde la última actualización y lo resta del tiempo total.
El método draw dibuja el temporizador en una ventana de SFML.
El método isTimeUp verifica si el tiempo ha llegado a cero.
El método getElapsedSeconds devuelve la cantidad de segundos transcurridos desde el inicio del temporizador.
El método addTime permite agregar tiempo adicional al temporizador.
El método reset reinicia el temporizador al tiempo inicial.
Recuerda adaptar este código a tu proyecto y asegurarte de tener la fuente de texto (font.ttf) en la ubicación correcta. También puedes ajustar el diseño y la apariencia del temporizador según tus necesidades.


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
