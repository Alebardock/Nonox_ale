#include "Nonograma.h"
using namespace std;
///Celda-----------------------------
Celda::Celda(){

    _x=0;
    _y=0;
    _Activo=false;
    _pixel=false;
    _visible=false;
   SetColorCelda();
    rectCelda.setPosition(getY(),getX());
    rectCelda.setSize(sf::Vector2f (25,25));
}

void Celda::CargarCelda(){
   float  x;
   float y;
   bool Activo;
   bool pixel;
   bool visible;
  std::cout<<"ingrese X"<<endl;
   std:: cin>>x;
   _x=x;
   std:: cout<<"ingrese Y"<<endl;
    std::cin>>y;
   _y=y;
    std::cout<<"ingrese visibilidad (0-1)"<<endl;
     std::cin>>visible;
   _visible=visible;
    std::cout<<"ingrese si es pixel (0-1)"<<endl;
    std::cin>>pixel;
   _pixel=pixel;

   _Activo=true;

   SetColorCelda();
   rectCelda.setPosition(getY(),getX());
   rectCelda.setSize(sf::Vector2f (25,25));
}
void Celda::MostrarCelda(){

   cout<<"prop X"<<endl;
   cout<<_x<<endl;
   cout<<"prop Y"<<endl;
   cout<<_y<<endl;
   cout<<"prop si es Activa(0-1)"<<endl;
   cout<<_Activo<<endl;
   cout<<"prop si es pixel (0-1)"<<endl;
   cout<<_pixel<<endl;
   cout<<"prop visibilidad (0-1))"<<endl;
   cout<<_visible<<endl;
}
void Celda::setCelda(float x, float y,bool Activo,bool pixel,bool visible){
    _x=x;
    _y=y;
    _Activo=Activo;
    _pixel=pixel;
    _visible=visible;
    SetColorCelda();
    rectCelda.setPosition(getY(),getX());

}
 void  Celda::draw(sf::RenderTarget& target,sf::RenderStates states)const
{

target.draw(rectCelda,states);


}
short int Celda::estadoActual(){
    return (((-1 + 2 *(int)_pixel)) * ((int)_visible));
}
 void Celda::setVisible(bool visible){
 _visible=visible;
 }

void Celda::setX( float x)
{_x=x;}

void Celda::setY( float y)
{_y=y;}

void Celda::setActivo(bool Activo)
{_Activo=Activo;}

void Celda::setPixel(bool pixel)
{_pixel=pixel;}

 float Celda::getX()
{return _x;}

 float Celda::getY()
{return _y;}

bool Celda::getActivo()
{return _Activo;}

bool Celda::getPixel()
{return _pixel;}

 bool Celda::getVisible()
{return _visible;}

 void Celda::CambiarEstado()
 {
    if  (!_visible){
   setVisible(true);
   }

 }

void Celda::SetColorCelda(){
 short int estadoActual1=estadoActual();
 if (estadoActual1==-1){
    rectCelda.setFillColor( sf::Color::Red );
    }
    else if (estadoActual1==0){

    rectCelda.setFillColor( sf::Color::Blue );
    }
    else {

 rectCelda.setFillColor( sf::Color::Green );
    }

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
 _texture.loadFromFile("icono11.png");
_sprite.setTexture(_texture);
 }

 void  Imagen::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
target.draw(_sprite,states);
}
