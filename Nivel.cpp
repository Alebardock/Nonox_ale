
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
}/*
 void SiSePrecionaLaCelda(sf::Mouse Raton,Celda Matriz [5][5]){
        for (int x=0;x<5;x++){
        for (int y;y<5;y++){

     if(Raton.isButtonPressed(sf::Mouse::Left)){
 if(((int)Raton.getPosition().x+Raton.getPosition().y)/100>=Matriz[x][y].getX()+Matriz[x][y].getY()||
    ((int)Raton.getPosition().x+Raton.getPosition().y)/100<=(Matriz[x][y].getX()+Matriz[x][y].getY()+100)){
    Matriz[x][y].CambiarEstado();
    Matriz[x][y].SetTexture();
 }
 }
 }
        }
 }

*/
int  Nivel::traerNivel(const char* nombre ){
    Celda reg;
    FILE *pCeldas;
	pCeldas=fopen(nombre,"rb");
	if(pCeldas==NULL){
		return -1;
	}
	int cont =0;
    int x=0;
    int y=0;
    while(fread(&reg, sizeof reg, 1,pCeldas)==1){
            cont++;
            this->fila[x][y].setCelda(reg.getX(),reg.getY(),reg.getVisible(),reg.getPixel());
            y++;
            if(y==5){
               x++;
               y=0;
            }
            if(x==5){
                break ;
                }
   }
 fclose(pCeldas);
 return cont;
}
/*
    int grabarEnDisco(){
        Celda reg;
        FILE *pCeldas;
        pCeldas=fopen("Nivel1.dat", "ab");
        if(pCeldas==NULL) return -1;
        int grabo=0;
        for (int x=0;x<25;x++){
            reg.CargarCelda();
        grabo+=fwrite(&reg, sizeof reg,1, pCeldas);
        }
        fclose(pCeldas);
        return grabo;
    }*/


   int leerDeDisco(){
        Celda reg;
        FILE *pCeldas;
        pCeldas=fopen("Nivel1.dat", "rb");
        if(pCeldas==NULL) return -1;
        int leyo=0;
        while (fread(&reg, sizeof reg,1, pCeldas)){
                leyo++;
        reg.MostrarCelda();

        }
        fclose(pCeldas);
        return leyo;
    }


