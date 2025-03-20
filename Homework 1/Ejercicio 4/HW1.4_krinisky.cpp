/*
4.  Recursión y ejecución en tiempo de compilación: 
a. Se requiere el código de una función recursiva que compare dos variables que 
contengan texto e indique mediante una variable bool si son iguales (true si son 
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea 
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre 
la funcionalidad de su código con un texto de, al menos, 64 caracteres. 
b. El  componente high_resolution_clock  de  <chrono>  permite  calcular  el tiempo 
de ejecución de un proceso al hacer: 
 
#include <chrono> 
... 
 
auto startTime = std::chrono::high_resolution_clock::now(); 
miProcesoAMedir(); 
auto endTime = std::chrono::high_resolution_clock::now(); 
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( 
endTime - startTime); 
 
std::cout  <<  “A  miProcesoAMedir  le  tomó:  “  <<  elapsedTime.count()  <<  “ 
nanosegundos” << std::endl; 
 
Utilice  esté  código  y  las  modificaciones  necesarias  que  crea  conveniente  para 
verificar cuanto tiempo toma la ejecución del código del ejercicio 4.1.
*/

#include <iostream>
#include <chrono> 
using namespace std;

bool comparison_recur_char(const char* letra1 , const char* letra2){ //Compara usando char recursivamente
    if (*letra1 == '\0' && *letra2 == '\0') return true;
    if (*letra1 != *letra2) return false;
    return comparison_recur_char(letra1+1,letra2+1);
}

bool comparison_recur_str(const string& palabra1,const string& palabra2,int i = 0){ //Compara usando string recursivamente
    if (palabra1.length() && palabra2.length()) return true;
    if (palabra1[i] != palabra2[i]) return false;
    return comparison_recur_str(palabra1, palabra2, i+1);
}


int main(void){
    string palabra1 = "Hola me llamo Francisco Krinisky y estudio en la Universidad de San Andres, Saludos";
    string palabra2 = "Hola me llamo Francisco Krinisky y estudio en la Universidad de San Andres, Saludos";

    //Tiempo de ejecucion de comparison_recur_char
    auto startTime_char = chrono::high_resolution_clock::now(); 
    comparison_recur_char(&palabra1[0],&palabra2[0]); 
    auto endTime_char = chrono::high_resolution_clock::now(); 
    auto elapsedTime_char = chrono::duration_cast<chrono::nanoseconds>( endTime_char - startTime_char); 
    
    std::cout  <<  "A  comparison_recur_char  le  tomó:  "  <<  elapsedTime_char.count()  <<  " nanosegundos." << std::endl;

    //Tiempo de ejecucion de comparison_recur_str
    auto startTime_str = chrono::high_resolution_clock::now(); 
    comparison_recur_str(&palabra1[0],&palabra2[0]); 
    auto endTime_str = chrono::high_resolution_clock::now(); 
    auto elapsedTime_str = chrono::duration_cast<chrono::nanoseconds>( endTime_str - startTime_str); 
    
    std::cout  <<  "A  comparison_recur_str  le  tomó:  "  <<  elapsedTime_str.count()  <<  " nanosegundos." << std::endl;
    return 0;
}



/*
Conclusion:
No pude llegar a una conclusion exacta de cual funcion es mas efectiva ya que a veces comparison_recur_str es mas rapida pero otras veces pasa lo contrario.
Pero en la mayoria de los casos comparison_recur_str es mas rapida
*/


