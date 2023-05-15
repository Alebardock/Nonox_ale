#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{
Nivel nivel1;


nivel1.traerNivel("Nivel1.dat");

///nivel1.setMatriz();
  sf::RenderWindow Ventana(sf::VideoMode(800, 600), "SFML window");
    sf::RenderStates states;
   sf::Mouse Raton;
    Ventana.setFramerateLimit(90);
    Imagen fondo1("Fon2.jpg");
    Imagen fondo2("Fon3.jpg");
    fondo2._sprite.setPosition(185,35);
    /*while(true){

        std::cout<<Raton.getPosition().x<<" ";
        std::cout<<Raton.getPosition().y;
    }
*/
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

Ventana.draw(fondo1);
Ventana.draw(fondo2);
       nivel1.CambiarEstado();
       nivel1.drawNivel(Ventana,states);

      /// SiSePrecionaLaCelda(Raton,nivel1.fila);



        // Update the window
        Ventana.display();
    }
    return EXIT_SUCCESS;
}
