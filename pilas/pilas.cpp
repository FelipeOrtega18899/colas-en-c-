#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};

class pilas
{
private:
    Nodo* top;
public:
    pilas(/* args */);
    ~pilas();
};

pilas::pilas(/* args */)
{
    top = nullptr;
}

pilas::~pilas()
{
}

void menu()
{
    cout << "1. Agregar elemento a la pila" << endl;
    cout << "2. Eliminar elemento de la pila" << endl;
    cout << "3. Mostrar elementos de la pila" << endl;
    cout << "4. Salir" << endl;
}

int main()
{
    pilas pila;
    int valor, opcion;

    do {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                // Agregar valor a la pila
                break;
            case 2:
                // Eliminar elemento de la pila
                break;
            case 3:
                // Mostrar elementos de la pila
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);






    return 0;
}


    