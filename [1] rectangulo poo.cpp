#include <iostream>
using namespace std;

class Rectangulo{
    private:
    int largo;
    int ancho;
    public:
    void setLargo(int valor){
        largo = valor;
    }
    void setAncho(int valor){
        ancho = valor;
    }
    int getLargo(){
        return largo;
    }
    int getAncho(){
        return ancho;
    }
//metodos extra
    int obArea(){
        return largo*ancho;
    }
    int obPerimetro(){
        return 2*largo + 2*ancho;
    }
    void imprimir(){
        cout << "El largo es "<<largo<<", y el ancho es "<<ancho<<"."<<endl;
    }
};

int main(){
Rectangulo *z;
z = new Rectangulo();
z->setLargo(10);
z->setAncho(5);
z->imprimir();
cout << "El largo es " << z->getLargo()<<endl;
cout << "El ancho es " << z->getAncho()<<endl;

cout << "El area es " << z->obArea()<<endl;
cout << "El perimetro es " << z->obPerimetro()<<endl;
    return 0;
}
