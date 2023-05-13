#pragma once
#include <SFML/Graphics.hpp>
# include<cstdlib>
# include<cstring>
#include <iostream>
#include<array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Imagen:public sf::Drawable
{


public:
    sf::Sprite _sprite;
    sf::Texture _texture;
    Imagen();
    Imagen( const std::string &imagen);
    void cargarImagen( const std::string &imagen);
    void draw(sf::RenderTarget& target,sf::RenderStates states)const override;

};



class Celda
{

    private:

    float _ancho=50;
    float _alto=50;
    short int _x;
    short int  _y;

    ///(Ocupado por "X"/0 || Ocupado Pixel  =true/1)
    bool _pixel;
    ///los posibles 3 archivos para los sprites de estado de celda

    public:
    Imagen cuadrito;
    ///(No _Visible=false/0 || _Visible =true/1) si esta oculto o no se presiono
    bool _visible;
    Celda();
    void setX(const short int x);
    void setY(const short int y);
    void setVisible(bool visible);
    void setPixel(bool pixel);

    ///los posibles 3 archivos para los sprites de estado de celda


    short int getX();
    short int getY();
    bool getVisible();
    bool getPixel();




     void CambiarEstado();
    void setCelda(short int x,short int y,bool visible,bool pixel);
   void SetTexture();
    void CargarCelda();
    void MostrarCelda();
    ///lee los booleanos que devuelve como resultado -1, 0 o 1
    short int estadoActual();
    void drawCelda(sf::RenderTarget& target,sf::RenderStates states);
};



class Nivel {
    private:

        short int F;
        short int C;
        char* _nombre;

       /// std::vector<std::vector <Celda>>AyudaHor;
       /// std::vector<std::vector <Celda>>AyudaVer;



    public:
         Celda fila[5][5];
         void traerNivel(short int F,const char* nombre);
         void setNombre( char *n){
         strcpy(_nombre, n);
         }
         Nivel();
         void setMatriz();
         void drawNivel(sf::RenderTarget& Ventana,sf::RenderStates states);
         void CargarNivel(int F,int C,const char* nombre);
};


///NIVELES-----------------------------------------
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
int CrearRegistroCelda();
/*
///CLASE ARCHIVO DE CLIENTES: PARA MANEJAR EL ARCHIVO DE CLIENTES
class ArchivoCliente{

    const char *getNombre(){ return nombre;}
    void setNombre(const char *n){strcpy(nombre,n);}

    int agregarRegistro();///ALTA

    int sobreEscribirRegistro(Cliente reg, int pos);

    int bajaLogica();///BAJA: LOGICA Y FISICA.
    ///int modificarRegistro();///MODIFICACION: CAMBIAR EL VALOR DE UNO O VARIOS CAMPOS
    int modificarEmail();
    bool listarArchivo();///LISTADO
    int buscarDNI(int d);
    Cliente leerRegistro(int pos);
    void mostrarPorFecha(Fecha aux);
    bool VaciarArchivo();
};
*/
///-------------------------------------------------------------









/*
class Ventana:public {
private:
 sf::RenderWindow _Ventana;
 Fondo _Fondo;
 Fondo _Titulo;


public:
Ventana(){(sf::VideoMode(800, 600), "SFML window");}

void setFramerateLimit(60);*/






