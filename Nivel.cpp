
#include "Nonograma.h"
using namespace std;

///nivel ----------------------------------
Nivel::Nivel(){
F =5;
C=5;
}

void Nivel::CargarNivel(int F,int C,const char* nombre){

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
void Nivel:: drawNivel(sf::RenderTarget& Ventana,sf::RenderStates states)
{

for (int x=0;x<5;x++){
   for (int y=0;y<5;y++){

    Ventana.draw(fila[x][y].cuadrito);

      }
   }
}
void Nivel::setMatriz(){

 for (int x=0;x<5;x++){
   for (int y=0;y<5;y++){
    fila[x][y].CargarCelda();
      }
   }
}
void Nivel::CambiarEstado(){
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        for (int x=0;x<5;x++){
          for (int y=0;y<5;y++){
            this->fila[x][y].CambiarEstado();
            this->fila[x][y].SetTexture();
           }
        }
       }
}

/*

void Nivel::traerNivel(short int F,const char* nombre){

    Celda reg;
    FILE *pCeldas;

	pCeldas=fopen(nombre,"rb");
	if(pCeldas==NULL){
		cout<<"No se pudo abrir " <<nombre<<endl;
	}
	short int x=0;

    while(fread(&reg, sizeof reg, 1,pCeldas)==1){
         this->_Level[x].setX(reg.getX());
     this->_Level[x].setY(reg.getY());
    this->_Level[x].setVisible(reg.getVisible());
    this->_Level[x].setPixel(reg.getPixel());
    cout<<reg.estadoActual()<<"  "<<endl;
        x++;
    if (x==F)
       { break;
          }
/*
    this->_Level[x][y].setX(reg.getX());
    this->_Level[x][y].setY(reg.getY());
    this->_Level[x][y].setVisible(reg.getVisible());
    this->_Level[x][y].setPixel(reg.getPixel());
    cont++;
    }

system("pause");
fclose(pCeldas);
}*/
