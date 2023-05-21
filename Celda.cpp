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
}

void Celda::CargarCelda(){
float  x;
 float y;
   bool Activo;
   bool pixel;
   bool visible;
   cout<<"ingrese X"<<endl;
   cin>>x;
   this->_x=x;
   cout<<"ingrese Y"<<endl;
   cin>>y;
   this->_y=y;
   cout<<"ingrese visibilidad (0-1)"<<endl;
   cin>>Activo;
   this->_Activo=Activo;
   cout<<"ingrese si es pixel (0-1)"<<endl;
   cin>>pixel;
   this->_pixel=pixel;
   cout<<"ingrese si es una Activa (0-1)"<<endl;
   cin>>visible;
   this->_visible=visible;
   SetColorCelda();
    rectCelda.setPosition(getY(),getX());
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
    this->_x=x;
    this->_y=y;
    this->_Activo=Activo;
    this-> _pixel=pixel;
    this-> _visible=visible;
    SetColorCelda();
    rectCelda.setPosition(getY(),getX());

}


short int Celda::estadoActual(){
    return (((-1 + 2 *(int)_pixel)) * ((int)_visible));
}
 void Celda::setVisible(bool visible){
 _visible=visible;
 }
 bool Celda::getVisible()
{
    return _visible;
}
void Celda::setX( float x)
{_x=x;}

void Celda::setY( float y)
{_y=y;}

void Celda::setActivo(bool Activo)
{this->_Activo=Activo;}

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

 void Celda::CambiarEstado()
 {
    if  (!_visible){
   setActivo(true);
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

 void  Celda::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
target.draw(rectCelda,states);
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
