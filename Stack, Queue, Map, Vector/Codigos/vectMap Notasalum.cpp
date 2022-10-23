#include <iostream>
#include <map>
#include <vector>
using namespace std;

class NotasDeAlumnos{
    private:
        map<string, vector<float> > notas;
    public:
        void agregarNota(string nombre, float nota){
            notas[nombre].push_back(nota);
        }
        void listar(){
            map<string, vector<float> > ::iterator i;
            for( i = notas.begin(); i!= notas.end(); i++){
                cout<<"Alumno: "<< i->first <<" sus notas son: "<<endl;
                for(int j = 0; j < i->second.size(); j++){
                    cout<<i->second[j]<<endl;
                }
            }
        }
};

main(){
    NotasDeAlumnos*a = new NotasDeAlumnos();
    a->agregarNota("Juan",7);
    a->agregarNota("Juan",6);
    a->agregarNota("Juan",5);
    a->agregarNota("Pepe",6);
    a->agregarNota("Luli",5.5);
    a->agregarNota("Laila",2);
    a->agregarNota("Juan",1);
    a->agregarNota("Juan",3);
    a->agregarNota("Juan",6);
    a->agregarNota("Pepe",6);
    a->agregarNota("Luli",5.5);
    a->agregarNota("Laila",7);
    a->listar();
}