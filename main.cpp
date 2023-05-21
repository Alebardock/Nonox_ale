#include <SFML/Graphics.hpp>
#include "Nonograma.h"

int main()
{
Celda Mate;
Mate.CargarCelda();


system("pause");
///nivel1.traerNivel("Nivel1.dat");

///nivel1.setMatriz();
sf::RectangleShape cuadrito(sf::Vector2f(25,25));
cuadrito.setPosition(50,50);


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
Ventana.draw(fondo2);/*
for (int x=0;x<12;x++){
    for (int y=0;y<12;y++){
        if (Mate._Matriz[x][y].getActivo()){
              Ventana.draw(Mate._Matriz[x][y]);
}
    }
    }*/
        // Update the window
        Ventana.display();
    }
    return EXIT_SUCCESS;
}
