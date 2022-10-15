#include <iostream>
#include <map>
using namespace std;

class NotasDeAlumnos{
    private:
        map<string,float> notas;
    public:
        void agregarNota(string nombre, float nota){
            if(notas.find(nombre) != notas.end()){
                cout<<"Alumno ya existe, su nota es un: ["<<notas[nombre]<<"], y no puede ser reemplazada por un ["<<nota<<"]."<<endl;
            }else{
                notas[nombre] = nota;
                cout<<"Nota agregada correctamente."<<endl;
            }
        }
        void crearOReepmlazar(string nombre, float nota){
            if(notas.find(nombre) != notas.end()){
                cout<<"Alumno ya existe, se reemplaza su ["<<notas[nombre]<<"] por un ["<<nota<<"]."<<endl;
                notas[nombre] = nota;
            }else{
                notas[nombre] = nota;
                cout<<"Nota de alumno creada correctamente."<<endl;
            }
        }
        void imprimirNotas(){
            map<string, float> :: iterator i;
            for(i = notas.begin(); i != notas.end(); i++){
                cout<<i->first<<" .... "<<"["<<i->second<<"]"<<endl;
            }
        }
        void buscarNotaAlumno(string nombre){
            if(notas.find(nombre) != notas.end()){
                cout<<"La nota de : "<<nombre<<" es ["<<notas[nombre]<<"]."<<endl;
            }else{
                cout<<nombre<<" no existe. "<<endl;
            }
        }
};

main(){
    NotasDeAlumnos* a = new NotasDeAlumnos();
    a->agregarNota("juan",3.3);
    a->agregarNota("pepe",6);
    a->agregarNota("luli",5.5);
    a->agregarNota("laila",2);
    a->crearOReepmlazar("juan",7);
    a->imprimirNotas();
}