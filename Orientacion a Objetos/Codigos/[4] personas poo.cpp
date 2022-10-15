#include <iostream>
using namespace std;

class Persona{
	private:
		string rut;
		int edad;
		string signo;
	public:
		Persona(string valrut,int valedad,string valsigno){
			rut = valrut;
			edad = valedad;
			signo = valsigno;
		}
	Persona(){
		
	}
	void setRut(string valor){
		rut = valor;
	}
	void setEdad(int valor){
		edad = valor;
	}
	void setSigno(string valsigno){
		signo = valsigno;
	}
	string getRut(){
		return rut;
	}
	int getEdad(){
		return edad;
	}
	string getSigno(){
		return signo;
	}
	void imprimir(){
		cout << "Rut: "<<rut<<" Edad: "<<edad<<" Signo: "<<signo<<endl;
	}
};

int main(){
	Persona *p1 = new Persona("1-9",45,"Libra");
	Persona *p2 = new Persona("2-7",45,"Capricornio");
	
	if(p1->getEdad() > p2->getEdad()){
		cout << p1->getRut()<< "es mayor que "<<p2->getRut()<<endl;
	}
	else if(p1->getEdad() < p2->getEdad()){
		cout << p1->getRut()<< "es menor que "<<p2->getRut()<<endl;
	}else{
		cout << p1->getRut()<<" tiene la misma edad que "<<p2->getRut()<<endl;
	}
	return 0;
}
