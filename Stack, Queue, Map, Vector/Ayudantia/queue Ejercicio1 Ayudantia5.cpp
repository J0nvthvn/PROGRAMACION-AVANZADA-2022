#include "iostream"
#include "queue"
using namespace std;

class Estudiante{
    private:
        string rut;
        int saldo;
    public:
        Estudiante(string rut){
            this->rut = rut;
            this->saldo = 30000;
        }
        string getRut(){ return rut; }
        int getSaldo(){ return saldo; }
        void setRut(){ this->rut = rut; }
        void setSaldo(int descuento){
            this->saldo -= descuento;
        }
};
class Casino{
    private:
        queue<Estudiante*> fila;
        int tickets;
    public:
        Casino(){
            this->tickets = 500;
        }
        void imprimirFila(){
            queue<Estudiante*> aux = fila;
            int tamanio = aux.size();
            for(int i = 0; i < tamanio; ++i){
                cout << "Estudiante numero ["<<i+1<<"]: "<<aux.front()->getRut()<<endl;
                aux.pop();
            }
        }
        void ingreso(Estudiante* e){
            fila.push(e);
            cout << "Estudiante "<<e->getRut()<<" ingresado exitosamente a la fila. "<<endl;
        }
        bool stock(){
            return tickets > 0;
        }
        void venta(){
            if(stock()){
                if(fila.front()->getSaldo() - 1000 < 0){
                    cout << "Al estudiante "<<fila.front()->getRut()<<" no le queda saldo."<<endl;
                } else {
                    fila.front()->setSaldo(1000);
                    tickets--;
                    cout << "Ticket vendido al estudiante "<<fila.front()->getRut()<<" exitosamente."<<endl;
                }
                fila.pop();
            } else {
                cout << "No quedan mas tickets."<<endl;
            }
        }
};
main(){
    Casino* casino = new Casino();
    casino->ingreso(new Estudiante("123456"));
    casino->ingreso(new Estudiante("987654"));
    casino->ingreso(new Estudiante("687524"));
    casino->ingreso(new Estudiante("953343"));
    casino->ingreso(new Estudiante("654348"));
    casino->imprimirFila();
    casino->venta();
    casino->venta();
    casino->imprimirFila();
    return 0;
}