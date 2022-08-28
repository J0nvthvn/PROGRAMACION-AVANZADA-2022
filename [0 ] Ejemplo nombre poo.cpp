#include <iostream>
using namespace std;

class Persona
{
    private:
    string nombre;
    int edad;
    public:
    Persona(string _nombre, int _edad){
        nombre = _nombre;
        edad = _edad;
    } 
    string getNombre(){
        return nombre;
    }
    int getEdad(){
        return edad;
    }
    void setNombre(string _nombre){
        nombre = _nombre;
    }
    void setEdad(int _edad){
        edad = _edad;
    }
    //metodos extra
    void presentarse(){
        cout << "\nMi nombre es "<<nombre<< " y tengo "<<edad<<" anios. "<<endl;
    }
};

int main(){
//crear objeto
//(METODO SIN PUNTERO)
Persona p1("Pablo ",25); //forma a
Persona p2 = Persona("Pedro",30); //forma b
//(METODO CON PUNTERO)
// Persona *p3 = new Persona("Sofia", 27);

cout << "El nombre es: "<<p1.getNombre()<<endl;

return 0;
}
