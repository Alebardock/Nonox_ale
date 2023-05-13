#pragma once

#include "Nonograma.h"

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




int CrearRegistroCelda();
