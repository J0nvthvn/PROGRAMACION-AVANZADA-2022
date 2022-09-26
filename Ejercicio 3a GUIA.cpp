#include <iostream>
using namespace std;

class Deportista{
    private:
        string nombre, especialidadDeportiva;
        int sueldo;
    public:
        Deportista(){

        }
        Deportista(string nombre, string especialidadDeportiva, int sueldo){
            this->nombre = nombre;
            this->especialidadDeportiva = especialidadDeportiva;
            this->sueldo = sueldo;
        }
        void setNombre(string nombre){
            this->nombre = nombre;
        }
        void setEspecialidadDeportiva(string especialidadDeportiva){
            this->especialidadDeportiva = especialidadDeportiva;
        }
        void setSueldo(int sueldo){
            this->sueldo = sueldo;
        }
        string getNombre(){
            return nombre;
        }
        string getEspecialidadDeportiva(){
            return especialidadDeportiva;
        }
        int getSueldo(){
            return sueldo;
        }
        void imprimir(){
            cout<<"Nombre: "<<this->nombre<<", Especialidad deportiva: "<<this->especialidadDeportiva<<", Sueldo: "<<this->sueldo<<endl;
        }
};

class AvionOlimpico{
    private:
        Deportista* deportistas[100];
    public:
        AvionOlimpico(){
            for (int i = 0; i < 100; i++){
                deportistas[i] = NULL;
            }
        }

        void ingresarDeportista(Deportista* d){
            bool encontro = false;
            for(int i = 0; i<100; i++){
                if(deportistas[i] == NULL){
                    deportistas[i] = d;
                    encontro = true;
                    cout<<"Deportista agregado en la posicion ["<<i<<"]."<<endl;
                    break;
                }
            }
            if(encontro == false){
                cout<<"No hay espacio para agregar al deportista"<<endl;
            }
        }
        
        void imprimirComitiva(){
            for (int i = 0; i < 100; i++)
            {
                if(deportistas[i] != NULL){
                    cout<<"Asiento ["<<i<<"]: ";
                    deportistas[i]->imprimir();
                }
            }    
        }
};

int main(){
    int opcion;
    string nombre,especialidad;
    int sueldo;
    AvionOlimpico* ao1 = new AvionOlimpico();
    
    while(true){
        cout<<"\n1.- Ingresar deportista: "<<endl;
        cout<<"2.- Imprimir comitiva: "<<endl;
        cout<<"\nIngrese una opcion: "<<endl;
        cin>>opcion;
        if(opcion < 1 || opcion > 2){
            break;
        }
        if(opcion == 1){
            system("cls");
            cout<<"Ingrese nombre: "<<endl;
            cin>>nombre;
            cout<<"Ingrese especialidad deportiva: "<<endl;
            cin>>especialidad;
            cout<<"Ingrese sueldo: "<<endl;
            cin>>sueldo;
            Deportista* d = new Deportista(nombre,especialidad,sueldo);
            ao1->ingresarDeportista(d);
        }
        if(opcion == 2){
            system("cls");
            ao1->imprimirComitiva();
        }
    }
    return 0;
}