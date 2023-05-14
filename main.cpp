#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{
Nivel nivel1;
nivel1.setMatriz();
  sf::RenderWindow Ventana(sf::VideoMode(800, 600), "SFML window");
    sf::RenderStates states;
    Ventana.setFramerateLimit(60);
    Imagen fondo1("Fon2.jpg");
    Imagen fondo2("Fon3.jpg");
    fondo2._sprite.setPosition(185,35);

   /* if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;*/

	// Start the game loop
    while (Ventana.isOpen())
    {
        // Process events
        sf::Event event;
        while (Ventana.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Ventana.close();
        }

        // Clear screen
        Ventana.clear();

        // Draw the sprite
      ///nivel1.drawNivel(nivel1,Ventana,states,5,5);
Ventana.draw(fondo1);
Ventana.draw(fondo2);

       nivel1.drawNivel(Ventana,states);

nivel1.CambiarEstado();
        // Update the window
        Ventana.display();
    }
    return EXIT_SUCCESS;
}
