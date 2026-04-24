#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class colas
{
private:
    Nodo* inicial;
    Nodo* final;
public:
    colas(){
        inicial = nullptr;
        final = nullptr;
    };
    void encolar(int dato){
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return;
        }
        Nodo* nuevo = new Nodo();
        nuevo->dato = dato;
        nuevo->siguiente = nullptr;

        if (final != nullptr) {
            final->siguiente = nuevo;
        }
        final = nuevo;
        if (inicial == nullptr) {
            inicial = nuevo;
        }
    };
    void desencolar(int dato){
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return;
        }
        Nodo* temp = inicial;
        inicial = inicial->siguiente;
        delete temp;
        
    };
    int peek() {
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return -1; 
        }
        return inicial->dato;

    };
    bool estaVacia() {
        return inicial == nullptr;
    };
    void imprimirCola() {
        if (estaVacia()){
            cout << "La cola está vacía." << endl;
            return;
        }
        Nodo* temp = inicial;
        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
    };
    void eliminarCola() {
        while (!estaVacia()) {
            desencolar(0);
        }
    };
};

void menu() {
    cout << "1. Enqueue (Insertar al final)" << endl;
    cout << "2. Dequeue ()" << endl;
    cout << "3. Peek()" << endl;
    cout << "4. ¿Está vacía?" << endl;
    cout << "5. Imprimir cola" << endl;
    cout << "6. Eliminar cola" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: ";
};


int main (){
    int opcion, valor;
    colas cola;

    do {
        menu();
        cin >> opcion;  
        switch (opcion) {
            case 1:
                cout << "Ingrese un valor para encolar: ";
                cin >> valor;
                cola.encolar(valor);
                break;
            case 2:
                cola.desencolar(valor);
                break;
            case 3:
                cout << "Frente de la cola: " << cola.peek() << endl;
                break;
            case 4:
                if (cola.estaVacia()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    cout << "La cola no está vacía." << endl;
                }
                break;
            case 5:
                cola.imprimirCola();
                break;
            case 6:
                cola.eliminarCola();
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 0);

}