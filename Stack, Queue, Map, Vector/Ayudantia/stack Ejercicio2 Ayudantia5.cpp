#include <iostream>
#include <stack>
using namespace std;

class Disco{
    private:
        string nombre, tipo, cantante;
        int anioPublicacion, precio;
    public:
        Disco(string nombre, string tipo, string cantante, int anioPublicacion, int precio){
            this->nombre = nombre;
            this->tipo = tipo;
            this->cantante = cantante;
            this->anioPublicacion = anioPublicacion;
            this->precio = precio;
        }
        string getTipo(){ return tipo; }
        void info(){
            cout << "Nombre: "<<nombre<<"\nTipo: "<<tipo<<"\nCantante: "<<cantante<<"\nAnio: "<<anioPublicacion<<"\nPrecio: "<<precio<<endl;
        }
};
class UDPyme{
    private:
        stack<Disco*> cajaRandom;
        stack<Disco*> cajaRock;
        stack<Disco*> cajaPop;
        stack<Disco*> cajaReggaeton;
    public:
        UDPyme(){
            cajaRandom.push(new Disco("Disco1","Pop","Uwu",2000,10200));
            cajaRandom.push(new Disco("Disco2","Reggaeton","OWO",2020,8900));
            cajaRandom.push(new Disco("Disco3","Rock","Uwu",2000,10900));
            cajaRandom.push(new Disco("Disco4","Rock","Uwu",2000,8900));
        }
        void ordenar(){
            while(!cajaRandom.empty()){
                string tipo = cajaRandom.top()->getTipo();
                if(tipo == "Reggaeton"){
                    cajaReggaeton.push(cajaRandom.top());
                    cout << "Disco agregado a Reggaeton exitosamente."<<endl;
                    cajaRandom.top()->info();
                } else if(tipo == "Pop"){
                    cajaPop.push(cajaRandom.top());
                    cout << "Disco agregado a Pop exitosamente."<<endl;
                    cajaRandom.top()->info();
                } else if(tipo == "Rock"){
                    cajaRock.push(cajaRandom.top());
                    cout << "Disco agregado a Rock exitosamente."<<endl;
                    cajaRandom.top()->info();
                } else {
                    cout << "Error al ordenar disco."<<endl;
                }
                cajaRandom.pop();
                cout << "- - - - - - -"<<endl;
            }
            cout << "Caja ordenada exitosamente. "<<endl;
        }
};

int main(){
    UDPyme* tienda = new UDPyme();
    tienda->ordenar();
    return 0;
}