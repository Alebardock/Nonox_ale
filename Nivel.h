#pragma once
#include "Celda.h"
class Nivel {
    private:
        short int F;
        short int C;
        char* _nombre;

    public:
         Celda fila[5][5];
         int  traerNivel(const char* nombre );
         void setNombre( char *n){
         strcpy(_nombre, n);
         }
         Nivel();
         void setMatriz();
         void drawNivel(sf::RenderTarget& Ventana,sf::RenderStates states);
         void CargarNivel(int F,int C,const char* nombre);
         void CambiarEstado();

};

void SiSePrecionaLaCelda(sf::Mouse Raton,Celda Matrz[5][5]);
int grabarEnDisco();
int leerDeDisco();
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
