#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{  /* CrearRegistroCelda();*/



Nivel nivel1;
nivel1.setMatriz();
  sf::RenderWindow Ventana(sf::VideoMode(800, 600), "SFML window");
    sf::RenderStates states;
    Ventana.setFramerateLimit(60);
    Imagen fondo("r(2).jpg");












   /* if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;*/


	// Start the game loop
    while (Ventana.isOpen())
    {
        // Process events
        sf::Event event;
        while (Ventana.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                Ventana.close();
        }

        // Clear screen
        Ventana.clear();

        // Draw the sprite
      ///nivel1.drawNivel(nivel1,Ventana,states,5,5);
Ventana.draw(fondo);


       nivel1.drawNivel(Ventana,states);

       /// Ventana.draw(fondo);

      // nivel1.drawNivel( Ventana,states,5,5);
        // Update the window
        Ventana.display();
    }

    return EXIT_SUCCESS;
}
