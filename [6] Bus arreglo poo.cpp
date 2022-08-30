#include <iostream>
using namespace std;

class Bus{
	private:
		int valorPremium;
		int valorNormal;
		int asientos[41];
	public:
		Bus(int _valorPremium,int _valorNormal){
			valorPremium = _valorPremium;
			valorNormal = _valorNormal;
			for(int i = 0;i < 41;i++){
				asientos[i] = 0;
			} 
			asientos [0] = 1;
		}
	void comprarPasaje(int pasaje){
		if(asientos[pasaje] == 0){
			asientos[pasaje] = 1;
			cout << "Asiento "<<pasaje<< " vendido exitosamente.";
			if(pasaje <= 10){
				cout << " Debe pagar valor Premium "<<valorPremium<<endl;
			}else{
				cout << " Debe pagar valor normal "<<valorNormal<<endl;			
				}
		}else{
			cout << "El asiento está ocupado, busque otro."<<endl;
		}
	}
	
	void devolverPasaje(int pasaje){
		if(asientos[pasaje] == 1){
			asientos[pasaje] == 0;
			cout<<"Asiento "<<pasaje<<" devuelto.";
			if(pasaje <= 10){
				cout << " Debe devolver valor Premium "<<valorPremium<<endl;
			}else{
				cout << " Debe devolver valor Normal "<<valorNormal<<endl;
			}
		}else{
			cout << "El asiento "<<pasaje<<" esta libre, imposible devolver."<<endl;
		}
	}
	
	void consultarPasaje(int pasaje){
		string tipoBus = "PREMIUM";
		int valorBus = valorPremium;
		string estado = "disponible";
		if(pasaje > 10){
			tipoBus = "NORMAL";
			valorBus = valorNormal;
		}
		if(asientos[pasaje] == 1){
			estado = "ocupado";
		}
		cout << "El asiento "<<pasaje<<" es tipo "<<tipoBus<<", vale "<<valorBus<<" y esta "<<estado<<endl;
	}
	
	int recaudacion(){
		int suma = 0;
		for(int i = 1; i < 41; i++){
			if(asientos[i] == 1 && i < 11){
				suma = suma + valorPremium;
			}
			else if(asientos[i] == 1 && i > 10){
				suma = suma + valorNormal;
			}
		}
		return suma;
	}
	
	void imprimir(){
		for(int i = 1; i < 41; i++){
			if(asientos[i] == 1){
				cout <<"X";
			}else{
				cout <<"-";
			}
			if(i % 4 == 0){
				cout<<"\n";
			}
			else if(i % 2 == 0){
				cout << " ";
			}
		}
	}
};

int main(){
	int vp, vn, asiento, opcion;
	cout<< "Ingrese valor asiento Premium: "<<endl;
	cin >> vp;
	cout<< "Ingrese valor asiento Normal: "<<endl;
	cin >> vn;
	Bus *b;
	b = new Bus(vp,vn);
	
	while(true){
		cout << "1.- Comprar pasaje"<<endl;
		cout << "2.- Devolver pasaje"<<endl;
		cout << "3.- Consultar asiento"<<endl;
		cout << "4.- Ver recaudacion"<<endl;
		cout << "5.- Detalle bus"<<endl;
		cout << "\nIngrese una opcion: "<<endl;
		cin >> opcion;
		if(opcion < 1 || opcion > 5){
			break;
		}
		if(opcion == 1){
			cout << "Ingrese asiento a comprar: "<<endl;
			cin >> asiento;
			b->comprarPasaje(asiento);
		}
		if(opcion == 2){
			cout << "Ingrese asiento a devolver: "<<endl;
			cin >> asiento;
			b->devolverPasaje(asiento); 
		}
		if(opcion == 3){
			cout << "Ingrese asiento a consultar: "<<endl;
			cin >> asiento;
			b->consultarPasaje(asiento);
		}
		if(opcion == 4){
			cout << "La recaudacion es: "<<b->recaudacion()<<endl;
		}
		if(opcion == 5){
			system("cls");
			b->imprimir();
		}
	}
}
