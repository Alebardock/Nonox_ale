#pragma once

#include "Nonograma.h"
using namespace sf;
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


class Celda: public sf::Drawable
{
private:
    float _x;
    float  _y;
    ///(Ocupado por "X"/0 || Ocupado Pixel  =true1)
    bool _pixel;
    bool _visible;


public:
    sf::RectangleShape rectCelda;
    ///(No _Visible=false/0 || _Visible =true/1) si esta oculto o no se presiono
    bool _Activo;
    Celda();
    void setX( float x);
    void setY( float y);
    void setVisible(bool visible);
    void setActivo(bool Activo);
    void setPixel(bool pixel);

    void setCelda(float x, float y,bool Activo,bool pixel,bool visible);
    void SetColorCelda();

    float getX();
    float getY();
    void setVisible();
    bool getVisible();
    bool getActivo();
    bool getPixel();
    sf::Vector2< int>getArea();
    void CambiarEstado();
    short int estadoActual();

    void CargarCelda();
    void MostrarCelda();
    ///lee los booleanos que devuelve como resultado -1, 0 o 1
    void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
};
int CrearRegistroCelda();

