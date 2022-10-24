#include "iostream"
#include "vector"
using namespace std;

class Alumno{
    private:
        string rut, nombre;
        vector<float> notas;
    public:
        Alumno(string rut, string nombre){
            this->rut = rut;
            this->nombre = nombre;
        }
        void ingresarNota(vector<float> notas_ing){
            int n = notas_ing.size();
            for(int i = 0; i < n; i++){
                notas.push_back(notas_ing.at(i));
            }
        }
        void ingresarNota(float nota){
            notas.push_back(nota);
        }
        float promedio(){
            int n = notas.size();
            float suma = 0;
            for(int i = 0; i < n; i++){
                suma += notas.at(i);
            }
            return suma / n;
        }
        void lista(){
            int n = notas.size();
            cout << "- - - - - - -"<<endl;
            for (int i = 0; i < n; i++){
                cout << "Nota "<<i+1<<": ["<<notas[i]<<"]"<<endl;
            }
            cout << "- - - - - - -"<<endl;
        }
};
main(){
    Alumno* alumno = new Alumno("123456","uwu");
    vector<float> notas = {2,4.5,6};
    alumno->ingresarNota(7);
    alumno->ingresarNota(notas);
    alumno->lista();
    cout << "Promedio: ["<<alumno->promedio()<<"]."<<endl;
    return 0;
}