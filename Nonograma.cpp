#include <iostream>
#include "Nonograma.h"
///Imagen-------------------------------

 Imagen::Imagen( const std::string &imagen){
 _texture.loadFromFile(imagen);
_sprite.setTexture(_texture);
 }


 void  Imagen::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
target.draw(_sprite,states);
}


///Celda-----------------------------
Celda::Celda(){

    this->_x=0;
    this->_y=0;
    this->_visible=false;
    this-> _pixel=false;
    this->_sprite.setPosition(_x,_y);
    setTexture(estadoActual());
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
   this->_sprite.setPosition(_x,_y);
    setTexture(estadoActual());
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
    this->_sprite.setPosition(_x,_y);
     setTexture(estadoActual());
}


short int Celda::estadoActual(){
    return (((-1 + 2 * (int)_pixel)) * ((int) _visible));
}

void Celda::setX(const short  int x)
{_x=x;}

void Celda::setY(const short int y)
{_y=y;}

void Celda::setVisible(bool visible)
{_visible=visible;}

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






void  Celda::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
    target.draw(_sprite,states);
}

void Celda::setTexture(int estadoActual ){

if (estadoActual==-1){
    _texture.loadFromFile(celdaText[0]);
    }
    else if (estadoActual==0){

       _texture.loadFromFile(celdaText[1]);
    }
    else {
            _texture.loadFromFile(celdaText[2]);
    }

}

void Celda::setSprite(){
_sprite.setTexture(_texture);
}

///nivel ----------------------------------
Nivel::Nivel(){

F =5;
C=5;
strcpy(_nombre, "non.jpg");


}



void Nivel::traerNivel(short int F,short int C,const char* nombre){

    Celda reg;
    FILE *pCeldas;

	pCeldas=fopen(nombre,"rb");
	if(pCeldas==NULL){
		cout<<"No se pudo abrir " <<nombre<<endl;
	}
	short int x=0;
	short int y=0;
    while(fread(&reg, sizeof reg, 1,pCeldas)==1){
          y++;
          if(y%C-1==0){
            y=0;
            x++;
          }

    this->_Level[x][y].setX(reg.getX());
    this->_Level[x][y].setY(reg.getY());
    this->_Level[x][y].setVisible(reg.getVisible());
    this->_Level[x][y].setPixel(reg.getPixel());
    }

fclose(pCeldas);
}

void CargarNivel(int F,int C,const char* nombre){

    Celda reg;
    FILE *pCeldas;

	pCeldas=fopen(nombre,"ab");///como queremos agregar registros usamos el modo ab

	if(pCeldas==NULL){
		cout<<"No se pudo abrir " <<nombre<<endl;
	}
 int cont=0;

     for (short int x=0;x<F;x++){
		for (short int y=0;y<C;y++){
            cont++;
            cout<<" ELEMENTO "<<cont<<endl;
            reg.CargarCelda();
			fwrite(&reg, sizeof reg, 1,pCeldas);

        }
     }
fclose(pCeldas);
}
void Nivel::drawNivel(sf::RenderWindow Ventana,short int F,short int C){

     for (short int x=0;x<F;x++){
		for (short int y=0;y<C;y++){
            Ventana.draw(this->_Level[x][y]);

        }
     }
}


