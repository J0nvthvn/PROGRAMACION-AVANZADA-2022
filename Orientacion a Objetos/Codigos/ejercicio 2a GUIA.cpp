#include<iostream>
using namespace std;

class Grupo{
    int numerodeAlumnos;
    string nombre, telefono;
    public:
        Grupo(int numerodeAlumnos, string nombre, string telefono){
            this->nombre = nombre;
            this->numerodeAlumnos = numerodeAlumnos;
            this->telefono = telefono;
        }
        void setNombre(string nombre){
            this->nombre = nombre;
        }
        void setNumerodeAlumnos(int numerodeAlumnos){
            this->numerodeAlumnos = numerodeAlumnos;
        }
        void setTelefono(int telefono){
            this->telefono  = telefono;
        }
        string getNombre(){
            return nombre;
        }
        int getNumerodeAlumnos(){
            return numerodeAlumnos;
        }
        string getTelefono(){
            return telefono;
        }
        void imprimir(){
            cout<<"Numero de alumnos: "<<this->numerodeAlumnos<<"\nNombre encargado de grupo:"<<this->nombre<<"\nTelefono encargado de grupo: "<<this->telefono<<endl;
        }
};

class Agenda{
    private:
        Grupo* grupos[10];
        int bloque;
        int valorxAlumno = 10000;
        bool Disponibilidad = false; //bloque libre por defecto (NO SE OCUPA, BORRAR)
    public:
        Agenda(){
            for(int i = 0; i<10; i++){
                grupos[i] = NULL;
            }
        }
        
        bool agregarGrupoAutomatico(Grupo* gx){
            for(int i=0; i<10; i++){
                if(grupos[i] == NULL){
                    Disponibilidad = true;
                    grupos[i] = gx;
                    break;
                }
            }
            return Disponibilidad;
        }
        bool agregarGrupoBloque(Grupo* gp,int bloque){
            if(grupos[bloque] == NULL){
                grupos[bloque]  = gp;
                return true;
            }
        }

        int RecaudacionDiaria(){
            int contador = 0;
            for(int i = 0; i<10; i++){
                if(grupos[i] != NULL){
                    if(grupos[i]->getNumerodeAlumnos() <= 3){
                        contador = contador + grupos[i]->getNumerodeAlumnos()*valorxAlumno;
                    }
                    else if(grupos[i]->getNumerodeAlumnos() > 3){
                        contador = contador + (0.8*(grupos[i]->getNumerodeAlumnos()*valorxAlumno)); //20% de descuento si son mas de 3 alumnos 
                    }
                }
            }
            return contador;
        }
};

int main(){
    Agenda* agenda1 =  new Agenda();
    int opcion;
    int integrantes;
    string telefono, nombre;

    while(true){
        cout<<"1.- Ingresar grupo a la agenda."<<endl;
        cout<<"2.- Ver recaudacion."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>> opcion;

        if(opcion == 1){
            system("cls");
            cout<<"Ingrese cantidad de integrantes en el grupo: ";
            cin>>integrantes;
            cout<<"Ingrese nombre representante de grupo: ";
            cin>>nombre;
            cout<<"Ingrese telefono del representante de grupo: ";
            cin>>telefono;
            Grupo* g = new Grupo(integrantes,nombre,telefono);
            if(agenda1->agregarGrupoAutomatico(g) == true){
                
                cout<<"Hay un bloque disponible para el grupo... Agregando automaticamente."<<endl;
            }
            else if(agenda1->agregarGrupoAutomatico(g) == false){
                cout<<"No hay bloques disponibles para el grupo."<<endl;
            }
        }
        if(opcion == 2){
            cout<<"La recaudacion actual es: "<<agenda1->RecaudacionDiaria();
        }
    }
    return 0;
}