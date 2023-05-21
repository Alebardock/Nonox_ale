#pragma once
#include "Nonograma.h"
#include "Celda.h"
#include <array>
class Matrix{

private:


public:
    Celda _Matriz[12][12];
Matrix();
void CargarMatrix();
void MostrarMatrix();
void setMatrix( Matrix auxi);
void siCliquea(sf::Mouse Raton, sf::RenderWindow Ventana);
};
