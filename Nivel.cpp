
#include "Nonograma.h"

using namespace std;

///nivel ----------------------------------
Nivel::Nivel(){

}

int Nivel:: CargarNiveles(const char* nombre){

    Matrix reg;

    FILE *pMatrix;

	pMatrix=fopen(nombre,"rb");

	if(pMatrix==NULL){
		return-1;
	}
           int cont=0;
           while(fread(&reg, sizeof reg, 1,pMatrix)==1){
          /// Niveles[cont]._Matriz.setMatrix(reg._Matriz);
fclose(pMatrix);
           }
return 1;
}



  void  CreaeNiveles(const char* nombre){

    Matrix reg;
    FILE *pMatrix;

	pMatrix=fopen(nombre,"ab");

	if(pMatrix==NULL){
		cout<<"No se pudo abrir " <<nombre<<endl;
	}
for( int x=0;x<3;x++){
           reg.CargarMatrix();
			fwrite(&reg, sizeof reg, 1,pMatrix);

        }

fclose(pMatrix);

}
