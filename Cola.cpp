#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregar(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void eliminar(Nodo *&, Nodo *&, int &);

int main() {
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int dato; 
    
    cout<<"Ingrese un numero: ";
    cin>>dato;
    agregar(frente,fin,dato);


    cout<<"\nIngrese un numero: ";
    cin>>dato;
    agregar(frente,fin,dato);

    cout<<"\nIngrese un numero: ";
    cin>>dato;
    agregar(frente,fin,dato);

    cout<<"\nEliminando elementos de la cola: ";
    while(frente != NULL){
        eliminar(frente,fin,dato);

        if(frente != NULL){
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<".";
        }
    }

    return 0;
}

void agregar(Nodo *&frente, Nodo *&fin, int n) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }
    else {
        fin->siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;

    cout<<"Elemento "<<n<<" insertado a cola exitosamente\n";
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true : false;
}

void eliminar(Nodo *&frente, Nodo *&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente -> siguiente;
    }

    delete aux;
}