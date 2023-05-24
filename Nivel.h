#pragma once
#include "Celda.h"
#include "Matrix.h"
#include <array>
class Nivel :public Matrix{
    private:

    public:
         int Vidas=3;
        std::array<Matrix,3>Niveles;
         Nivel();
         void setNivelesManual();
         void drawNivel(sf::RenderTarget& Ventana,sf::RenderStates states);
         int CargarNiveles(const char* nombre);

         void CambiarEstado();

};
void CreaeNiveles(const char* nombre);

