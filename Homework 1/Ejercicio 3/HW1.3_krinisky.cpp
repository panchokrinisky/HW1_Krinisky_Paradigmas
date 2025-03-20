/*
3.  Implemente  una  lista  enlazada  que  utilice  nodos  que  simplemente  contengan  un 
valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes 
funciones para manejar la lista: 
i. create_node(): devuelve un nodo. 
ii. push_front(): inserta un nodo al frente de la lista. 
iii. push_back(): inserta un nodo al final de la lista. 
iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa 
una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de 
agregar el nodo al final de la lista. 
v. erase():  borra  un  nodo  en  la  posición  que  se  le  pase  a  la  función.  Similar  a  la 
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar 
el último nodo. 
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”. 
Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y, 
muy importante para el ejercicio, sólo utilizar smart pointers.
*/
#include <iostream>
#include <memory>
using namespace std;
struct Node {
    int value; //valor en el nodo
    shared_ptr<Node> sig; //siguiente nodo
};

struct List{
    shared_ptr<Node> head; //El primer nodo de la lista
};



shared_ptr<Node> create_node(int value){ //Crea el nodo con un shared_ptr y le asigna valor y el sig a null
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->value = value;
    new_node->sig = nullptr;
    return new_node;
}

void push_front(int value, List *list){ //Crea un nodo y lo asigna a la head de la lista, pasando la antigua head a la 2da psocion
    shared_ptr<Node> new_node = create_node(value);
    new_node->sig = list->head;
    list->head = new_node;
    return;
}

void push_back(int value, List *list){ //Crea un nodo y lo pone en el ultimo lugar de la lista
    shared_ptr<Node> new_node = create_node(value);
    if (list->head ==nullptr){
        list->head = new_node;
        return;
    }
    shared_ptr<Node> actual = list->head;
    while(actual->sig != nullptr) actual = actual->sig;
    actual->sig = new_node;
    return;
}

void insert(int value, int pos, List *list){ //Inserta un nodo en el pos indicado, si se excede el indice se pone en la ultima posicion
    shared_ptr<Node> new_node = create_node(value);
    if (pos == 0){
        new_node->sig  = list->head;
        list->head = new_node;
        return;
    }
    shared_ptr<Node> actual = list->head;
    for (int i = 0; i<pos - 1; ++i){
        if (actual->sig == nullptr){
            actual->sig = new_node;
            cout << "El nodo fue insertado al final de la lista porque el indice era mas grande que el tamaño de la lista." << endl;
            return;
        }   
        actual = actual->sig;
    }
    new_node->sig = actual->sig;
    actual->sig = new_node;
    return;
}

void erase(int pos, List *list){ //Se elimina el nodo en el indice pos, si la lista esta vacia no hace nada y si se excede el inidice se elimina el ultimo nodo
    if (!list->head){
        cout << "La lista esta vacia, no se pudo borrar." << endl;
        return;
    }
    if (pos == 0) {
        list->head = list->head->sig;
        return;
    }
    shared_ptr<Node> actual = list->head;
    shared_ptr<Node> previo = nullptr;
    for (int i = 0; i < pos; ++i) {
        if (!actual->sig) {
            cout << "El nodo eliminado de la lista fue el ultimo ya que el indice era mayor al tamaño de la lista." << endl;
            if (previo) previo->sig = nullptr;
            else list->head = nullptr;
            return;
        }
        previo = actual;
        actual = actual->sig;
    }
    if (previo) previo->sig = actual->sig;
    return;
}

void print_list(List *list){ //Hace un print de todos los valores en la lista en el estilo valor1->valor2->...->FIN
    if (!list->head){
        cout << "La lista esta vacia." << endl;
        return;}
    shared_ptr<Node> actual = list->head;
    while(actual){
        cout << actual->value << " -> ";
        actual = actual->sig;
    }
    cout << "FIN" << endl;
    return;
}

int main(void) {
    List testList;

    //Tests con todos los casos importantes
    cout << "Insertar adelante" << endl;
    push_front(10, &testList);
    push_front(20, &testList);
    print_list(&testList);


    cout << "Insertar al final" << endl;
    push_back(30, &testList);
    push_back(40, &testList);
    print_list(&testList);

    cout << "Insertar en una pos especifica" << endl;
    insert(25, 2, &testList);
    insert(35, 4, &testList);
    print_list(&testList);

    cout << "Borrar primer nodo" << endl;
    erase(0, &testList);
    print_list(&testList);


    cout << "Borrar  nodo en pos especifica" << endl;
    erase(2, &testList);
    print_list(&testList);

    cout << "Borrar nodo final" << endl;
    erase(30, &testList); 
    print_list(&testList);

    cout << "Borrar en lista vacia" << endl;
    List emptyList;
    erase(0, &emptyList);
    print_list(&emptyList);

    return 0;
}