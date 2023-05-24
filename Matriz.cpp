#include "Nonograma.h"
using namespace std;
Matrix::Matrix(){

     for ( int x=0;x<12;x++){
		for (int y=0;y<12;y++){
            _Matriz[x][y].setCelda(0,0,0,0,0);

          }
     }
}
void Matrix::setMatrix( Matrix auxi){

     for ( int x=0;x<12;x++){
		for (int y=0;y<12;y++){
            this->_Matriz[x][y]=auxi._Matriz[x][y];

          }
     }

}


void Matrix::CargarMatrix(){

 int Tam;
 int cont=0;

std::cout<<"Ingrese Tamaño del nivel " <<endl;
std::cin>>Tam;
     for ( int x=0;x<Tam;x++){
		for (int y=0;y<Tam;y++){
                cont++;
            cout<<" ELEMENTO "<<cont<<endl;
            _Matriz[x][y].CargarCelda();
         }
     }
}
void Matrix:: MostrarMatrix(){
    int cont =0;
     for ( int x=0;x<12;x++){
		for (int y=0;y<12;y++){
                cont++;
                if (_Matriz[x][y].getActivo()==1){
            cout<<" ELEMENTO "<<cont<<endl;
            _Matriz[x][y].MostrarCelda();
                }
         }
     }
}
void Matrix::siCliquea(sf::Mouse Raton, sf::RenderWindow & Ventana){

    for (int x=0;x<12;x++){
       for (int y=0;y<12;y++){
    sf::RectangleShape cuadrito=_Matriz[x][y].rectCelda;
           if(Raton.isButtonPressed(sf::Mouse::Left)){
if (cuadrito.getPosition().x <=Raton.getPosition(Ventana).x
    && cuadrito.getPosition().x >=Raton.getPosition(Ventana).x - 25
    && cuadrito.getPosition().y <= Raton.getPosition(Ventana).y
    && cuadrito.getPosition().y >= Raton.getPosition(Ventana).y-25)
{
   _Matriz[x][y].CambiarEstado();
   _Matriz[x][y].SetColorCelda();
}

               }
           }

 }
}

void Matrix::drawMatrix(sf::RenderWindow & ventana){


 for (int x=0;x<12;x++){
    for (int y=0;y<12;y++){
           if (_Matriz[x][y].getActivo()){
            ventana.draw(_Matriz[x][y].rectCelda);
           }

  }

 }


}
