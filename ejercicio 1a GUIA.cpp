#include <iostream>
using namespace std;

class Reloj{
    private:
        int hora;
        int minutos;
        int segundos;
    public:
        Reloj(int hora, int minutos, int segundos){
            this->hora = hora;
            this->minutos = minutos;
            this->segundos = segundos;
        }
        void setHora(int hora){
            this->hora = hora;
        }
        void setMinutos(int minutos){
            this->minutos = minutos;
        }
        void setSegundos(int segundos){
            this->segundos = segundos;
        }
        int getHora(){
            return hora;
        }
        int getMinutos(){
            return minutos;
        }
        int getSegundos(){
            return segundos;
        }
        
        void imprimir(){
            cout<<hora<<":"<<minutos<<":"<<segundos<<endl;
        }
        void ajustarHoraOficial(Reloj* ho){ //El objeto "ho" cuenta con la hora oficial
            if(this->getHora() > ho->getHora()){
                cout<<"El reloj esta ADELANTADO."<<endl;
                this->setHora(ho->getHora()); //cambiar la HORA
                this->setMinutos(ho->getMinutos()); //cambiar los MINUTOS
                this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
            }
            else if(this->getHora() == ho->getHora()){
                if(this->getMinutos() == ho->getMinutos()){
                    if(this->getSegundos() == ho->getSegundos()){
                        cout<<"El reloj esta A LA HORA."<<endl; //en este caso NO SE CAMBIA LA HORA
                    }
                    else if(this->getSegundos() > ho->getSegundos()){
                        cout<<"El reloj esta ADELANTADO."<<endl;
                        this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
                    }
                    else if(this->getSegundos() < ho->getSegundos()){
                        cout<<"El reloj esta ATRASADO."<<endl;
                        this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
                    }
                }
                else if(this->getMinutos() > ho->getMinutos()){
                    cout<<"El reloj esta ADELANTADO."<<endl;
                    this->setMinutos(ho->getMinutos()); //cambiar los MINUTOS
                    this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
                }
                else if(this->getMinutos() < ho->getMinutos()){
                    cout<<"El reloj esta ATRASADO."<<endl;
                    this->setMinutos(ho->getMinutos()); //cambiar los MINUTOS
                    this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
                }
            }
            else if(this->getHora() < ho->getHora()){
                cout<<"El reloj esta ATRASADO."<<endl;
                this->setHora(ho->getHora()); //cambiar la HORA
                this->setMinutos(ho->getMinutos()); //cambiar los MINUTOS
                this->setSegundos(ho->getSegundos()); //cambiar los SEGUNDOS
            }
        }
};

int main(){

    Reloj ha(11,59,59); //hora ACTUAL
    Reloj* ho = new Reloj(11,59,59); //hora OFICIAL
    
    cout<<"Hora actual: ";
    ha.imprimir();
    cout<<"Hora oficial: ";
    ho->imprimir();
    ha.ajustarHoraOficial(ho);
    cout<<"Hora modificada: ";
    ha.imprimir();
    return 0;
}