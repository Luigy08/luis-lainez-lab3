#include<iostream>
#include <string>
using namespace std;
void imprimir(char**,int);
int binarioDecimal(int);
int decimalBinario(int);
int casteo(int);
int mover(char**,char,int);
int main(int argc,char const *argv[]){
	char** matriz;
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
				}while(size<10);
				matriz=new char*[size];
				for(int i=0;i<size;i++){
					matriz[i]=new char[size];
				}
				imprimir(matriz,size);
				char fila[size];
				bool valiEntrada;
				for(int i=0;i<size;i++){
					do{
						
						cout<<"Fila: "<<(i+1)<<endl;
						cin>>fila;
						valiEntrada=false;
						for(int j=0;j<size;j++){
							if(fila[j]=='5'){
								valiEntrada=true;
								cout<<"El 5 es invalido, ingrese nuevamente la fila"<<endl;
							}
						}
					}while(valiEntrada);
					for(int j=0;j<size;j++){
						matriz[i][j]=fila[j];
					}
					imprimir(matriz,size);
					cout<<endl;
				}
				imprimir(matriz,size);
				//--------------Jugar
				bool end=true;
				int puntosF=0;
				while(end){
					int temPuntos=0;
					char mov;
					cout<<"Ingrese movimiento (w,a,s,d): ";
					cin>>mov;
					temPuntos=mover(matriz,mov,size);
					cout<<temPuntos<<endl;
					if(temPuntos==5){
						puntosF-=temPuntos;
					}else{
						puntosF+=temPuntos;
					}
					if(temPuntos==3){
						end=false;
					}
					
					imprimir(matriz,size);
					cout<<"Puntos: "<<puntosF<<endl;
				}
				cout<<endl<<"\tGanaste"<<endl;
				for(int i=0;i<size;i++){
					delete[] matriz[i];
				}
				delete []matriz;
				break;
			}
			case 2:{
				cout<<"\tCalculadora Binaria"<<endl;
				int op2=0;
				while(op2!=4){
					cout<<"1.-Decimal a binario\n"<<"2.-Binario a decimal\n"<<"3.-Sumar binarios\n...\n";
					cin>>op2;
					switch(op2){
						case 1:{
							cout<<endl<<"\tDecimal a Binario"<<endl;
							int numero;
							cout<<"Numero: ";
							cin>>numero;
							//cout<<decimalBinario(numero)<<endl;
							break;					
						}
						case 2:{
							int numero;
							cout<<endl<<"\tBinario a decimal"<<endl;
							cout<<"Numero: ";
							cin>>numero;
							cout<<endl<<binarioDecimal(numero)<<endl;
							break;							
						}
						case 3:{
							int numero1,numero2;
							cout<<"\tSuma de Binarios"<<endl;
							cout<<"Primer Numero: ";
							cin>>numero1;
							cout<<"Segundo numero: ";
							cin>>numero2;
							
							
						}
					}
				}
			}
		}
	}
}
int suma(int binario1,int binario2){
	int b1[8]=binario1;
	int b2[8]=binario2;
	int tem=0;
	int salida=0;
	for(int i=8;i>=0;i--){
		if(b1[i]+b2[i]+tem=0){
				
		}
	}
}
int binarioDecimal(int numero){
	int mul=1;
	int salida=0;
	while(numero>0){
		int tem=mul*(numero%10);
		salida+=tem;
		mul*=2;
		numero=numero/10;
	}
	return salida;
}
int decimalBinario(int numero){
	int div=numero,tem;
	string binario="";
	while(div>2){
		tem=div%2;
		if(tem==1){
			binario="1"+binario;
			
		}else{
			binario="0"+binario;
		}
		div=div/2;
		
	}
	if(div==1){
		binario="1"+binario;
	}else{
		binario="0"+binario;
	}
	cout<<binario<<endl;


}
void imprimir(char** matriz,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}
int mover(char** matriz,char movimiento,int size){
	int filaAc=0,columnaAc=0;
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(matriz[i][j]=='2'){
				filaAc=i;
				columnaAc=j;
			
			}
		}
	}
	int puntos=0;
	cout<<matriz[filaAc][columnaAc]<<endl;
	if(movimiento=='w'){
		if(matriz[filaAc-1][columnaAc]!='0'){
			puntos=casteo(matriz[filaAc-1][columnaAc]);	
			matriz[filaAc-1][columnaAc]=matriz[filaAc][columnaAc];
			if(matriz[filaAc-1][columnaAc]!='-'){
				matriz[filaAc][columnaAc]='-';
				int resta=0;
				
				return puntos;
			}
			
		}
	}
	if(movimiento=='a'){
		if(matriz[filaAc][columnaAc-1]!='0'){
			puntos=casteo(matriz[filaAc][columnaAc-1]);
			matriz[filaAc][columnaAc-1]=matriz[filaAc][columnaAc];
			if(matriz[filaAc][columnaAc-1]!='-'){
                        	matriz[filaAc][columnaAc]='-';
				return puntos;
                        }
		
		}
	}
	if(movimiento=='s'){
		if(matriz[filaAc+1][columnaAc]!='0'){
			puntos=casteo(matriz[filaAc+1][columnaAc]);
			matriz[filaAc+1][columnaAc]=matriz[filaAc][columnaAc];
			if(matriz[filaAc+1][columnaAc]!='-'){
				matriz[filaAc][columnaAc]='-';
                                return puntos;
                        }
			
		}
	}
	if(movimiento=='d'){
		if(matriz[filaAc][columnaAc+1]!='0'){
			puntos=casteo(matriz[filaAc][columnaAc+1]);
			matriz[filaAc][columnaAc+1]=matriz[filaAc][columnaAc];
			if(matriz[filaAc][columnaAc+1]!='-'){
                        	matriz[filaAc][columnaAc]='-';
			        return puntos;
                        }
		
		}
	}
	
	return 0;
}int casteo(int numero){
	return (numero-48);

}
