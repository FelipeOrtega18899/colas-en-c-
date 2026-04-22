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
    pilas(){
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = top;
        top = nuevo;
    }
    void pop() {
        if (isEmpty()) {
            cout << "La pila esta vacia. No se puede eliminar." << endl;
            return;
        }
        Nodo* auxiliar = top;
        cout << "Elemento eliminado: " << top->dato << endl;
        top = top->siguiente;
        delete auxiliar;
    }
    void topElement() {
        if (isEmpty()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        cout << "Elemento en la cima: " << top->dato << endl;
    }
    void imprimir() {
        if (isEmpty()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        Nodo* auxiliar = top;
        while (auxiliar != nullptr) {
            cout << auxiliar->dato << " ";
            auxiliar = auxiliar->siguiente;
        }
        cout << endl;
    }
    void contar () {
        int contador = 0;
        Nodo* auxiliar = top;
        while (auxiliar != nullptr) {
            contador++;
            auxiliar = auxiliar->siguiente;
        }
        cout << "Cantidad de elementos en la pila: " << contador << endl;
    }
    void vaciar() {
        while (top != nullptr) {
            Nodo* auxiliar = top;
            top = top->siguiente;
            delete auxiliar;
        }
    }
};

void menu() {
    cout << "1. Push (insertar)" << endl;
    cout << "2. Pop (eliminar)" << endl;
    cout << "3. Top (mostrar cima)" << endl;
    cout << "4. Imprimir pila" << endl;
    cout << "5. Contar elementos" << endl;
    cout << "6. Vaciar pila" << endl;
    cout << "0. Salir" << endl;
};

int main() {
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
                pila.push(valor);
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                pila.topElement();
                break;
            case 4:
                pila.imprimir();
                break;
            case 5:
                pila.contar();
                break;
            case 6:
                pila.vaciar();
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}


    