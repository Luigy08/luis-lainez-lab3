#include<iostream>
using namespace std;
void imprimir(char**,int);
int main(int argc,char const *argv[]){
	int op=0;
	while(op!=3){
		cout<<"1.-Ejercicio #1"<<endl<<"2.-Ejercicio #2"<<endl<<"...";
		cin>>op;
		switch(op){
			case 1:{
				int size;
				cout<<"\tLaberinto"<<endl;
				do{
					cout<<"Tamaño: ";
					cin>>size;
					if(size<10){
						cout<<"El tamaño debe ser mayor a 9"<<endl;
					}
				while(size<10);
				char** matriz=new char*[size];
				for(int i=0;i<size;i++){
					matriz[i]=new char[size];
				}
				imprimir(matriz,size);
				char fila[size];
				char entrada;
				for(int i=0;i<size;i++){
					cout<<"Fila: "<<(i+1)<<endl;
					cin>>fila;
					
					matriz[i]=fila;
				}
				imprimir(matriz,size);
				/*for(int i=0;i<size;i++){
					delete[] matriz[i];
				}
				delete []matriz;*/
			}
		}
	}
}
void imprimir(char** matriz,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}
int mover(int** matriz,char movimiento,int size){
	int filaAc=0,columnaAc=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(matriz[i][j]=='2'){
				filaAc=i;
				columnaAc=j;
				break;
			}
		}
	}
	if(movimiento=='w'){
		if(matriz[filaAc-1][columnaAc]!='0'){
			matriz[filaAc-1][columnaAc]==matriz[filaAc][columnaAc];
			matriz[filaAc][columnaAc]=='-';
		}
	}
	if(movimiento=='a'){
		if(matriz[filaAc][columnaAc-1]!='0'){
			matriz[filaAc][columnaAc-1]==matriz[filaAc][columnaAc-1];
			matriz[filaAc][columnaAc]=='-';
		}
	}
	if(movimiento=='s'){
		if(matriz[filaAc+1][columnaAc]!='0'){
			matriz[filaAc+1][columnaAc]==matriz[filaAc][columnaAc];
			matriz[filaAc][columnaAc]=='-';
		}
	}
	if(movimiento=='d'){
		if(matriz[filaAc][columnaAc+1]!=0){
			matriz[filaAc][columnaAc+1]==matriz[filaAc][columnaAc];
			matriz[filaAc][columnaAc]=='-';
		}
	}
	return 
}
