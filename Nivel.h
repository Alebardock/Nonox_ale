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
/*
bool SiSePrecionaLaCelda(sf::Mouse & Raton,Celda Matrz[5][5]);
int grabarEnDisco();
int leerDeDisco();*/
///NIVELES--------------------------        ---------------
/*class Nivel1 :public Nivel{


    private:

    std::array<std::array<Celda, 5>,5> nonox1;

};
class Nivel2 :public Nivel{
    private:

	std::array<std::array<Celda, 6>,6> nonox1;

};
class Nivel3 :public Nivel{
    private:

	std::array<std::array<Celda, 7>,7> nonox1;
};
class Nivel4 :public Nivel{
    private:

	std::array<std::array<Celda, 8>,8> nonox1;

};
class Nivel5 :public Nivel{
    private:

	std::array<std::array<Celda, 9>,9> nonox1;

};


*/
