#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{  /* CrearRegistroCelda();*/
    Imagen fondo("fondo2.png");



    Nivel nivel1;
    Nivel::traerNivel(nivel1,5,5,"Nivel1.dat");
    sf::RenderWindow Ventana(sf::VideoMode(800, 600), "SFML window");
    Ventana.setFramerateLimit(60);

    // Load a sprite to display
    sf::Texture texture;
   /* if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;*/
    sf::Sprite sprite(texture);

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
        Ventana.draw(sprite);
        Ventana.draw(fondo);
        Ventana.draw(sprite);

        // Update the window
        Ventana.display();
    }

    return EXIT_SUCCESS;
}
