#include<iostream>
using namespace std;
void imprimir(char**,int);
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
							decimalBinario(numero);
							break;					
						}
					}
				}
			}
		}
	}
}
int decimalBinario(int numero){
	int div=numero,tem;
	int con=0;
	int acumulado[con];
	while(div>2){
		tem=div%2;
		if(tem==1){
			acumulado[con]=1;
		}else{
			acumulado[con]=0;
		}
		div=div/2;
		con++;
	}
	for(int i=con;i>0;i--){
		cout<<acumulado[i];
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
	cout<<matriz[filaAc][columnaAc]<<endl;
	if(movimiento=='w'){
		if(matriz[filaAc-1][columnaAc]!='0'){
			matriz[filaAc-1][columnaAc]=matriz[filaAc][columnaAc];
			if(matriz[filaAc-1][columnaAc]!='-'){
				matriz[filaAc][columnaAc]='-';
				int resta=0;
				
				return casteo(matriz[filaAc-1][columnaAc]);
			}
			
		}
	}
	if(movimiento=='a'){
		if(matriz[filaAc][columnaAc-1]!='0'){
			matriz[filaAc][columnaAc-1]=matriz[filaAc][columnaAc];
			if(matriz[filaAc][columnaAc-1]!='-'){
                        	matriz[filaAc][columnaAc]='-';
				return casteo(matriz[filaAc][columnaAc-1]);
                        }
		
		}
	}
	if(movimiento=='s'){
		if(matriz[filaAc+1][columnaAc]!='0'){
			matriz[filaAc+1][columnaAc]=matriz[filaAc][columnaAc];
			if(matriz[filaAc+1][columnaAc]!='-'){
				matriz[filaAc][columnaAc]='-';
                                return casteo(matriz[filaAc+1][columnaAc]);
                        }
			
		}
	}
	if(movimiento=='d'){
		if(matriz[filaAc][columnaAc+1]!='0'){
			cout<<"Entro 1";
			matriz[filaAc][columnaAc+1]=matriz[filaAc][columnaAc];
			if(matriz[filaAc][columnaAc+1]!='-'){
                        	matriz[filaAc][columnaAc]='-';
			        return casteo(matriz[filaAc][columnaAc+1]);
                        }
		
		}
	}
	
	return 0;
}int casteo(int numero){
	if(numero==49){
		return numero-48;
	}
	if(numero==51){
		return numero-48;
	}
	if(numero==53){
		return numero-48;
	}

}
