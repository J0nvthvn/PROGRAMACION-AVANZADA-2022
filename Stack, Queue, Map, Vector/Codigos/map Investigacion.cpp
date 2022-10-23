#include "iostream"
#include "map"
using namespace std;

class Investigacion{
    private:
        map<string, int> revistas; 
        /* 
            llave string nombre de la revista,
            el contenido int contador
        */
    public:
        Investigacion(){
            revistas["Nature"] = 0;
            revistas["Science"] = 0;
            revistas["Astrophys"] = 0;
        }
        void acumularenRevista(string nombreRevista){
            if(nombreRevista == "Nature" || nombreRevista == "Science" || nombreRevista == "Astrophys"){
                revistas[nombreRevista] = revistas[nombreRevista] + 1;
            }
        }
        void eliminarArticuloRevista(string nombreRevista){
            if(nombreRevista == "Nature" || nombreRevista == "Science" || nombreRevista == "Astrophys"){
                if(revistas[nombreRevista] > 0){
                    revistas[nombreRevista] = revistas[nombreRevista] - 1;
                }
            }
        }
        void imprimirEstadisticas(){
            cout << "ESTADISTICAS INVESTIGACION"<<endl;
            cout<<"Nature "<<revistas["Nature"]<<" articulos"<<endl;
            cout<<"Science "<<revistas["Science"]<<" articulos"<<endl;
            cout<<"Astrophys "<<revistas["Astrophys"]<<" articulos"<<endl;
            
            float suma = revistas["Nature"] + revistas["Science"] + revistas["Astrophys"];
            if(suma > 0){
                cout << "Nature "<<revistas["Nature"]/suma*100.0<<" %"<<endl;
                cout << "Science "<<revistas["Science"]/suma*100.0<<" %"<<endl;
                cout << "Astrophys "<<revistas["Astrophys"]/suma*100.0<<" %"<<endl;
            }
            cout << "----------------------\n"<<endl;
        }
    
};
main(){
    Investigacion* inv = new Investigacion();
    inv->imprimirEstadisticas();
    inv->acumularenRevista("Nature");
    inv->acumularenRevista("Nature");
    inv->acumularenRevista("Science");
    inv->acumularenRevista("Nature");
    inv->acumularenRevista("Nature");
    inv->acumularenRevista("Astrophys");
    inv->acumularenRevista("Astrophys");
    inv->eliminarArticuloRevista("Nature");
    inv->imprimirEstadisticas();
}