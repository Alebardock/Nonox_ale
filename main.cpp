#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{  /* CrearRegistroCelda();*/
    Imagen fondo("fondo2.png");


 Nivel nivel1;
    nivel1.traerNivel(5,5,"Nivel1.dat");

for (int x = 0;x<5;x++){
    for (int y = 0;y<5;y++){

    nivel1._Level[x][y].Celda::MostrarCelda();
}

}

    sf::RenderWindow Ventana(sf::VideoMode(800, 600), "SFML window");
    sf::RenderStates states;
    Ventana.setFramerateLimit(60);



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

      // nivel1.drawNivel( Ventana,states,5,5);
        // Update the window
        Ventana.display();
    }

    return EXIT_SUCCESS;
}
