/*
c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se 
realice  en  tiempo  de  compilación  y obtenga  el  tiempo  de  ejecución.  Compare 
este  tiempo  con  el  obtenido  en  el  ejercicio  4.2  y  justifique  brevemente  la 
diferencia (puede escribir su conclusión como un comentario al final del código 
de este item). 
*/


#include <iostream>
#include <chrono> 
using namespace std;

constexpr bool comparison_recur_char(const char* letra1 , const char* letra2){ //Compara usando char recursivamente en tiempo de compilacion, por eso usa constexpr
    if (*letra1 == '\0' && *letra2 == '\0') return true;
    if (*letra1 != *letra2) return false;
    return comparison_recur_char(letra1+1,letra2+1);
}

constexpr bool comparison_recur_str(const char* palabra1,const char* palabra2,int i = 0){ //Compara usando string recursivamente en tiempo de compilacion, por eso usa constexpr
    if (palabra1[i] == '\0'  && palabra2[i] == '\0') return true; //Tuve que modificar la anterior comapracion que usana en el 4 porque no se podia hacer eso en tiempo de compilacion.
    if (palabra1[i] != palabra2[i]) return false;
    return comparison_recur_str(palabra1, palabra2, i+1);
}


int main(void){
    constexpr const char* palabra1 = "Hola me llamo Francisco Krinisky y estudio en la Universidad de San Andres, Saludos";
    constexpr const char* palabra2 = "Hola me llamo Francisco Krinisky y estudio en la Universidad de San Andres, Saludos";

    //Tiempo de ejecucion de comparison_recur_char en compilacion
    auto startTime_char = chrono::high_resolution_clock::now(); 
    comparison_recur_char(&palabra1[0],&palabra2[0]); 
    auto endTime_char = chrono::high_resolution_clock::now(); 
    auto elapsedTime_char = chrono::duration_cast<chrono::nanoseconds>( endTime_char - startTime_char); 
    
    std::cout  <<  "A  comparison_recur_char  le  tomó:  "  <<  elapsedTime_char.count()  <<  " nanosegundos." << std::endl;

    //Tiempo de ejecucion de comparison_recur_str en compilacion
    auto startTime_str = chrono::high_resolution_clock::now(); 
    comparison_recur_str(&palabra1[0],&palabra2[0]); 
    auto endTime_str = chrono::high_resolution_clock::now(); 
    auto elapsedTime_str = chrono::duration_cast<chrono::nanoseconds>( endTime_str - startTime_str); 
    
    std::cout  <<  "A  comparison_recur_str  le  tomó:  "  <<  elapsedTime_str.count()  <<  " nanosegundos." << std::endl;
    return 0;
}

/*
Conclusion:
Cuando comparo en tiempo de compilacion mi funcion comparison_recur_str pasa a ser mas rapida en lograr completar la comparacion.
*/