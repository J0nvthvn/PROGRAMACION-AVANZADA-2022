#include <iostream>
using namespace std;

class Fraccion{
	private:
		int numerador;
		int denominador;
	public:
		Fraccion(int valnum, int valden){
			numerador = valnum;
			denominador = valden;
		}
	void setNumerador(int valor){
		numerador = valor;
	}
	void setDenominador(int valor){
		denominador = valor;
	}
	int getNumerador(){
		return numerador;
	}
	int getDenominador(){
		return denominador;
	}
	
	void imprimir(){
		simplificar();
		if(numerador % denominador == 0){
			cout << numerador / denominador << endl;
		}
		else if(numerador > denominador){
			cout << numerador / denominador <<" "<< numerador % denominador << 
			" / "<< denominador<<endl;
		}else{
			cout <<numerador<<" / "<<denominador<<endl;
		}
	}
	
	void simplificar(){
	//primero buscamos el menor
	int menor = numerador;
	if(denominador < menor){
		menor = denominador;
	}
	for(int i = menor; i > 1; i--){
		if(numerador % i == 0 && denominador % i == 0){
			numerador = numerador / i;
			denominador = denominador / i;
		}
	}
	}
};

Fraccion *suma(Fraccion *g1, Fraccion *g2){
	int den = g1->getDenominador() * g2->getDenominador();
	int num = g1->getNumerador()* g2->getDenominador() + g2->getNumerador() * g1->getDenominador();
	Fraccion *resultado = new Fraccion(num,den);
	return resultado;
}

Fraccion *multiplica(Fraccion *g1, Fraccion *g2){
	int den = g1->getDenominador() * g2->getDenominador();
	int num = g1->getNumerador() * g2->getNumerador();
	Fraccion *resultado = new Fraccion(num,den);
	return resultado;
	
}
int main(){
	Fraccion *f1 = new Fraccion(1,2);
	Fraccion *f2 = new Fraccion(1,4);
	Fraccion *res = suma(f1,f2);
	res->imprimir();
	return 0;
}
