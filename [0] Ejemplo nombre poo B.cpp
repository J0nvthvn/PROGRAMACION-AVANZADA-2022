#include <iostream>
using namespace std;

class Persona
{
    protected:
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
    virtual void presentarse(){
        cout << "\nMi nombre es "<<nombre<< " y tengo "<<edad<<" anios. "<<endl;
    }
};

class Profesor : public Persona{
	private:
		int clases;
		string materia;
	public:
		Profesor(string nombre, int edad, string materia, int clases) : Persona(nombre,edad){
			this->materia = materia;
			this->clases = clases;
		}
		int getClases(){
			return clases;
		}
		string getMateria(){
			return materia;
		}
		virtual void presentarse(){
        	cout << "\nMi nombre es "<<nombre<< " y tengo "<<edad<<" anios. "<<endl;
    		cout << "Doy la materia de "<<materia<< " a "<<clases<<" clases."<<endl;
		}
};

int main(){
//crear objeto
Persona *p1 = new Persona("Benja",25);
Profesor *p2 = new Profesor("Roberto",35, "fisica", 4);

Persona *personas[] = {p1,p2};

for(int i=0; i<2;i++){
	personas[i]->presentarse();
	}

	return 0;
}

