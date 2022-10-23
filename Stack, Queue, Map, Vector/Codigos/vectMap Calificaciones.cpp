#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Calificaciones{
    private:
        map<string, vector<float> > lista;
        int tope;
    public:
        Calificaciones(int tope){
            this->tope = tope;
        }
        
        void agregarNotaAlumno(string nombre, float nota){
            cout<<"TV:"<<nombre<<" -- "<<lista[nombre].size()<<endl;
            if(lista[nombre].size() == tope){
                cout << "Excede el maximo de notas. "<<endl;
            }else{
                lista[nombre].push_back(nota);
                cout << "Nota de alumno "<<nombre<<" agregada. "<<endl;
                /*
                    lista[nombre] es un vector, por ende, si pongo
                    lista[nombre].push_back() estoy agregando un
                    elemento al vector.
                */
            }
        }
        
        void recorrer(){
            map<string, vector<float> > :: iterator rec;
            for (rec = lista.begin(); rec != lista.end(); rec++){
                cout << rec->first<<endl; // rec->first es la llave, o en este caso, el nombre.
                vector<float> aux = rec->second; // rec->second es el contenido, o sea el vector de float
                cout << "Tiene "<<aux.size()<<" notas. "<<endl;
                for(int i = 0; i < aux.size(); i++){
                    cout <<"Nota "<<i+1<<": "<<aux[i]<<endl;
                }
                cout << "--------------\n"<<endl;
            }
        }
        
        void promediosPorAlumno(){
            cout << "Promedio de alumnos."<<endl;
            cout << "------------------\n"<<endl;
            map<string, vector<float> > :: iterator rec;
            for(rec = lista.begin(); rec != lista.end(); rec++){
                cout << rec->first<<endl;
                float suma = 0;
                vector<float> aux = rec->second;
                for(int i = 0; i < aux.size(); i++){
                    suma = suma + aux[i];
                }
                cout <<"Promedio del alumno: "<<suma/aux.size()<<endl;
            }
            cout << "--------------\n"<<endl;
        }
        void buscarNotasDeUnAlumno(string nombre){
            if(lista.find(nombre) == lista.end()){ //pregunto si nombre NO existr
                cout << nombre << " no existe en la lista o map. "<<endl;
            }else{ //existe en el map porque lista.find(nombre) != lista.end()
                cout << nombre << " si existe en la lista o map. "<<endl;
                cout << lista.find(nombre)->first << endl;
                vector <float> aux = lista.find(nombre)->second;
                cout << "Sus notas son: "<<endl;
                for(int i = 0; i < aux.size(); i++){
                    cout << aux[i] <<endl;
                }
            }
        }
};
main(){
    Calificaciones* c = new Calificaciones(2);
    c->agregarNotaAlumno("juan",3);
    c->agregarNotaAlumno("juan",4);
    c->agregarNotaAlumno("juan",5);
    c->agregarNotaAlumno("diego",7);
    c->agregarNotaAlumno("pedro",6);
    c->agregarNotaAlumno("diego",4);
    c->agregarNotaAlumno("pedro",5);
    c->agregarNotaAlumno("juan",3);
    c->agregarNotaAlumno("juan",4);
    c->agregarNotaAlumno("juan",5);
    c->agregarNotaAlumno("diego",7);
    c->agregarNotaAlumno("pedro",6);
    c->agregarNotaAlumno("diego",4);
    c->agregarNotaAlumno("pedro",5);
    c->recorrer();
    c->promediosPorAlumno();
    string nombre;
    while(true){
        cout << "Ingrese nombre: "<<endl;
        cin >> nombre;
        c->buscarNotasDeUnAlumno(nombre);
    }
}