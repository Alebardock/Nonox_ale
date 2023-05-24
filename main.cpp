#include <SFML/Graphics.hpp>
#include "Nonograma.h"
#include "Temporalizador.h"

int main()
{
     Matrix nivelPrueba;
     nivelPrueba.CargarMatrix();
     nivelPrueba.MostrarMatrix();
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML window");

    sf::RenderStates states;
    sf::Mouse Raton;




    ventana.setFramerateLimit(90);
    Imagen fondo1("Fon2.jpg");
    Imagen fondo2("Fon3.jpg");
    Temporalizador temporalizador(1, 30);
    fondo2._sprite.setPosition(185,35);



        bool nivelGanado = false;

    while (ventana.isOpen()) {

        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                nivelGanado = true;
            }
        }


     if (!nivelGanado) {
            temporalizador.actualizar(); // Actualizar el temporizador

            if (temporalizador.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se acabe el tiempo
                // por ejemplo, terminar el juego o reiniciar el nivel.
                temporalizador.reiniciar(); // Reiniciar el temporizador para la próxima partida
            }

            if (temporalizador.segundosTranscurridos() >= 60) {
                int minutos = temporalizador.segundosTranscurridos() / 60;
                int segundos = temporalizador.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se complete el nivel correctamente
                // y obtener el tiempo transcurrido para usarlo en el puntaje final.
                nivelGanado = true;
            }
        }

        // Clear screen
        ventana.clear();

     ventana.draw(fondo1);
     ventana.draw(fondo2);
     nivelPrueba.siCliquea(Raton,ventana);
     nivelPrueba.drawMatrix(ventana);




        temporalizador.dibujar(ventana); // Dibujar el temporizador en la ventana

        ventana.display();

        if (nivelGanado) {
            // El nivel se ha ganado antes de tiempo, detener el reloj y mostrar el tiempo restante
           temporalizador.parar(); // Detener el temporizador



            std::cout << "¡Nivel ganado antes de tiempo! Tiempo restante: " << (temporalizador.getTiempoRestante()/ 60)<< " minutos " << (temporalizador.getTiempoRestante()%60) << " segundos" << std::endl;

            // Aquí puedes realizar las acciones adicionales cuando se gana antes de tiempo
            // por ejemplo, otorgar puntos extra, mostrar una animación, etc.

            //sf::sleep(sf::seconds(1)); // Pausa de 1 segundo antes de continuar el bucle
        }
    }

    return 0;


}
