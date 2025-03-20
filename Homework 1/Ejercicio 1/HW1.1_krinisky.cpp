/*
1.a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva 
una matriz cuadrada con valores
*/

#include <iostream>
#include <typeinfo>
#include <vector>
#include <stdexcept>

using namespace std;


int** creatematrix(size_t n ){
    try{
        int** matrix = new int*[n];

        for (size_t i = 0; i<n; ++i){
            matrix[i] = new int[n];
        } //Trata de crear la matriz, si falla avisa al usuario y detiene el programa
        int value = 1;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                matrix[i][j] = value++;
            }
        }
        return matrix;
    } catch (bad_alloc& e){
        cerr << "Error en la asignacion de memoria: " << e.what() << endl;
        throw;
    }
}
/* b.  Proveer  un  código  que  imprima  el  contenido  de  la  matriz,  utilizando  un  único  ciclo 
for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:  */

void readmatrix(int** matrix, size_t n){
    for (int i = n*n - 1 ;i>=0;i--){
        size_t f = i/n;
        size_t c = i % n;
        cout << "Matriz[" << f << "][" << c << "] = " << matrix[f][c] << endl;
    }
    return;
}

int main(){
    size_t n = 4;
    int** matriz = creatematrix(n);
    readmatrix(matriz,n);
    return 0;
}
