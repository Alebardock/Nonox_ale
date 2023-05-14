#include "Nonograma.h"
using namespace std;
///Celda-----------------------------
Celda::Celda(){

    _x=0;
    _y=0;
    _visible=false;
     _pixel=false;
 SetTexture();
  cuadrito._sprite.setPosition(getY(),getX());
}

void Celda::CargarCelda(){
short    int x;
 short  int y;
   bool visible;
   bool pixel;
   cout<<"ingrese X"<<endl;
   cin>>x;
   this->_x=x;
   cout<<"ingrese Y"<<endl;
   cin>>y;
   this->_y=y;
   cout<<"ingrese visibilidad (0-1)"<<endl;
   cin>>visible;
   this->_visible=visible;
   cout<<"ingrese si es pixel (0-1)"<<endl;
   cin>>pixel;
   this->_pixel=pixel;

 SetTexture();
 cuadrito._sprite.setPosition(getY(),getX());
}
void Celda::MostrarCelda(){

   cout<<"prop X"<<endl;
   cout<<_x<<endl;
   cout<<"prop Y"<<endl;
   cout<<_y<<endl;
   cout<<"prop visibilidad (0-1)"<<endl;
   cout<<_visible<<endl;
   cout<<"prop si es pixel (0-1)"<<endl;
   cout<<_pixel<<endl;
}
void Celda::setCelda(short int x,short int y,bool visible,bool pixel){
    this->_x=x;
    this->_y=y;
    this->_visible=visible;
    this-> _pixel=pixel;

    SetTexture();
    cuadrito._sprite.setPosition(getY(),getX());

}


short int Celda::estadoActual(){
    return (((-1 + 2 *(int)_pixel)) * ((int)_visible));
}

void Celda::setX(const short  int x)
{_x=x;}

void Celda::setY(const short int y)
{_y=y;}

void Celda::setVisible(bool visible)
{this->_visible=visible;}

void Celda::setPixel(bool pixel)
{_pixel=pixel;}

short int Celda::getX()
{return _x;}

short int Celda::getY()
{return _y;}

bool Celda::getVisible()
{return _visible;}

bool Celda::getPixel()
{return _pixel;}

 void Celda::CambiarEstado()
 {

   if (_visible){
    setVisible(false);
   }
   if  (!_visible){
   setVisible(true);
   }

 }

void Celda::SetTexture(){
 short int estadoActual1=estadoActual();
 if (estadoActual1==-1){
        cuadrito._texture.loadFromFile("icono1.png");
    }
    else if (estadoActual1==0){

cuadrito._texture.loadFromFile("icono2.png");
    }
    else {

   cuadrito._texture.loadFromFile("icono3.png");
    }
cuadrito._sprite.setTexture(cuadrito._texture);



}


void  Celda::drawCelda(sf::RenderTarget& target,sf::RenderStates states)
{


    target.draw(cuadrito._sprite,states);
}
 Imagen::Imagen( const std::string &imagen){
 _texture.loadFromFile(imagen);
_sprite.setTexture(_texture);
 }


void Imagen::cargarImagen( const std::string &imagen){
 _texture.loadFromFile(imagen);
_sprite.setTexture(_texture);

 }
Imagen::Imagen( ){
 _texture.loadFromFile("icono1.png");
_sprite.setTexture(_texture);
 }

 void  Imagen::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
target.draw(_sprite,states);
}
