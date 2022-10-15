#include <iostream>
using namespace std;

class CuentaRut{
	private:
		int numero;
		int saldo;
		string rut;
		string nombre;
	public:
		CuentaRut(int valornum, string valorrut, string valornom){
			saldo = 0;
			numero = valornum;
			rut = valorrut;
			nombre = valornom;
		}
		void setRut(string valor){
			rut = valor;
		}
		void setNombre(string valor){
			nombre = valor;
		}
		void setNumero(int valor){
			numero = valor;
		}
		string getNombre(){
			return nombre;
		}
		string getRut(){
			return rut;
		}
		int getNumero(){
			return numero;
		}
		int getSaldo(){
			return saldo;
		}
	//metodos extra
		void imprimir(){
			cout << "\nRut: "<<rut<<"\nNombre: "<<nombre<<"\nCuenta: "<<numero<<"\nSaldo: "<<saldo<<endl;
		}
		void depositar(int monto){
			if(monto <= 0){
				cout << "Monto invalido"<<endl;
			}else{
				saldo = saldo + monto;
				cout << "Deposito efectuado exitosamente."<<endl;
			}
		}
		void girar(int monto){
			if(monto <= 0){
				cout << "Monto invalido"<<endl;
			}else{
				if(saldo - monto < 0){
					cout << "Saldo insuficiente."<<endl;
				}else{
					saldo = saldo - monto;
					cout << "Giro efectuado exitosamente."<<endl;
				}
			}
		}	
};

int main(){
	int numero, monto, opcion;
	string nom, rut;
	cout << "Ingrese numero de la cuenta: "<<endl;
	cin >> numero;
	cout << "Ingres nombre cliente: "<<endl;
	cin >> nom;
	cout << "Ingrese rut cliente: "<<endl;
	cin >> rut;
	CuentaRut *r;
	r = new CuentaRut(numero,rut,nom);

while(true){
	cout <<"1.- Depositar"<<endl;
	cout <<"2.- Girar"<<endl;
	cout <<"3.- Ver saldo de la cuenta"<<endl;
	cout <<"4.- Ver detalle completo de la cuenta"<<endl;
	cout <<"Otro.- Salir"<<endl;
	cin >> opcion;
	
	if(opcion < 1 || opcion > 4){
		break;
	}
	if(opcion == 1){
		cout << "Ingrese el monto a depositar: "<<endl;
		cin >> monto;
		r->depositar(monto);
	}
	if(opcion == 2){
		cout << "Ingrese el monto a girar: "<<endl;
		cin >> monto;
		r->girar(monto);
	}
	if(opcion == 3){
		cout << "El saldo de la cuenta es: "<<r->getSaldo()<<endl;
		cout << "\n";
	}
	if(opcion == 4){
		r->imprimir();
	}
}

}
