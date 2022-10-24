#include <iostream>
using namespace std;

class Vehiculo{
    protected:
        int cantidad, ruedas;
        string color;
    public:
        Vehiculo(int ruedas, string color){
            this->cantidad = 20;
            this->ruedas = ruedas;
            this->color = color;
        }
        void info(){
            cout << "Stock disponible: "<<cantidad<<endl;
            cout << "Ruedas: "<<ruedas<<endl;
            cout << "Color: "<<color<<endl;
        }
        void setCantidad() { this->cantidad -=1; }
        int getCantidad() { return this->cantidad; }
};
class Auto : public Vehiculo{
    protected:
        int cantPasajeros;
        float velocidad;
    public:
        Auto(int ruedas, string color, int cantPasajeros, float velocidad) : Vehiculo(ruedas, color){
            this->cantPasajeros = cantPasajeros;
            this->velocidad = velocidad;
        }
        void info(){
            cout << "Stock disponible: "<<cantidad<<endl;
            cout << "Ruedas: "<<ruedas<<endl;
            cout << "Color: "<<color<<endl;
            cout << "Cantidad de pasajeros: "<<cantPasajeros<<endl;
            cout << "Velocidad: "<<velocidad<<endl;
        }
};
class Camion : public Vehiculo{
    protected:
        float carga;
    public:
        Camion(int ruedas, string color, float carga) : Vehiculo(ruedas, color){
            this->carga = carga;
        }  
        void info(){
            cout << "Stock disponible: "<<cantidad<<endl;
            cout << "Ruedas: "<<ruedas<<endl;
            cout << "Color: "<<color<<endl;
            cout << "Carga: "<<carga<<endl;
        }
};
main(){
    Camion *c = new Camion(4,"verde",400);
    Auto* a = new Auto(4,"azul",5,899);
    Vehiculo* vehiculos[2] = {a,c};
    int opcion;
    while(true){
        cout << "- - - - - - - - - - - - -"<<endl;
        cout << "1.- Ver stock."<<endl;
        cout << "2.- Vender vehiculo."<<endl;
        cout << "3.- Salir."<<endl;
        cout << "- - - - - - - - - - - - -"<<endl;
        cout << "Ingrese una opcion: "<<endl;
        cin >> opcion;
        if(opcion == 1){
            system("cls");
            cout << "- - - - - - - - - - - - -"<<endl;
            cout << "1.- Stock Auto.\n2.- Stock Camion."<<endl;
            cout << "- - - - - - - - - - - - -"<<endl;
            cout << "Ingrese una opcion: "<<endl;
            cin >> opcion;
            if(opcion ==1){
                cout << "STOCK: "<<vehiculos[0]->getCantidad()<<endl;
            } else if(opcion == 2) {
                cout << "STOCK: "<<vehiculos[1]->getCantidad()<<endl;
            } else {
                cout << "Opcion invalida. Intente nuevamente."<<endl; 
            }
        } else if(opcion == 2){
            system("cls");
            cout << "- - - - - - - - - - - - -"<<endl;
            cout << "1.- Vender Auto.\n2.- Vender Camion."<<endl;
            cout << "- - - - - - - - - - - - -"<<endl;
            cout << "Ingrese una opcion: "<<endl;
            cin >> opcion;
            if(opcion == 1){
                vehiculos[0]->setCantidad();
                vehiculos[0]->info();
            } else if(opcion == 2){
                vehiculos[1]->setCantidad();
                vehiculos[1]->info();
            } else {
                cout << "Opcion invalida. Intente nuevamente."<<endl;
            }
        } else if(opcion == 3){
            cout << "Saliendo del menu."<<endl;
            break;
        } else {
            cout << "Opcion invalida. Intente nuevamente."<<endl;
        }
    }
}