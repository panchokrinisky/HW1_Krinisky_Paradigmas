#include <iostream>
#include <fstream>  
using namespace std;
/*
2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en
funcionamiento. Para ello, se utiliza un sistema de log que almacena los eventos
relevantes. Cada evento recibe una etiqueta que indica su nivel de importancia o
gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y
CRITICAL.
a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un
archivo mediante el llamado a una función logMessage definida en pseudo código de
la siguiente manera:

void logMessage(String mensaje, Integer/Otro NivelSeveridad)

Donde NivelSeveridad corresponderá con unas de las leyendas previamente
mencionadas. El formato esperado en una línea del archivo de log es el siguiente:
[ERROR] <Mensaje>
[INFO] <Mensaje>
etc.
Verifique su funcionamiento con al menos una entrada de cada tipo
*/
/*
b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad. 
Para  el  caso  del  código  del  ejercicio  2.a,  se  requiere  tener  la  habilidad  de  agregar 
mensajes  personalizados  para  registrar  otro  tipo  de  eventos.  Los  requisitos  son  los 
siguientes: 
 
i. Todos los nuevos mensajes deben ser invocados con logMessage. 
ii. Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el 
archivo y la línea de código donde sucedió este error, es decir: 
logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código) 
iii. Se  requiere  la posibilidad  de  registrar un  mensaje  de “Acceso  de  Usuario”  a  la 
aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma 
debe ser ingresada de la siguiente manera: 
logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario) 
Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc. 

iv. Se  requiere  un  código  que  pruebe  que  el  sistema  verifica  la  funcionalidad 
requerida  y  que  además  demuestre  que  puede  capturar  un  error  en  runtime, 
crear una entrada en el log y después detener la ejecución del programa y salir 
del mismo con un código de error (return 1). 

*/

void logMensaje( string mensaje, int nivelSeveridad){
    string etiqueta;
    switch (nivelSeveridad){ //Use un switch para elegir el caso, si no es un numero dentro de los parametros se etiquetara como [???]
        case 1: etiqueta = "[DEBUG]";break;
        case 2: etiqueta = "[INFO]";break;
        case 3: etiqueta = "[WARNING]";break;
        case 4: etiqueta = "[ERROR]";break;
        case 5: etiqueta = "[CRITICAL]";break;
        default: etiqueta = "[???]";break;
    }
    ofstream log("myLog.txt",ios::app);
    if (log.is_open()) {
        log << etiqueta << " " << mensaje << endl;
        log.close();}
        else {
            cout << "Error al abrir el archivo.\n";}

}

void logMensaje(string accessmessage, string username){
    ofstream log("myLog.txt",ios::app);
    if (log.is_open()) {
        log << "[SECURITY] " << accessmessage << " - Usuario: " << username << endl;
        log.close();}
        else {
            cout << "Error al abrir el archivo.\n";}
    return;
}

void logMensaje(string errormessage, string file, int codeline){
    ofstream log("myLog.txt",ios::app);
    if (log.is_open()) {
        log << "[ERROR] " << errormessage << " en el archivo: " << file << " en la linea " << codeline << endl;
        log.close();}
        else {
            cout << "Error al abrir el archivo.\n";}
    return;
}
int main(){
    ofstream log("myLog.txt",ios::app);
    if (log.is_open()) {
        log << "log information:\n";
        log.close();}
        else {
            cout << "Error al abrir el archivo.\n";}
    int opcion;
    do{ //Esto es un while hasta que se elija la opcion 4 para salir del programa, se elije una opcion y luego de ejecutarse se vuelve a preguntar
        cout << "Seleccione el tipo de mensaje a registrar:\n";
        cout << "1 = Mensaje con nivel de severidad (DEBUG, INFO, WARNING, ERROR, CRITICAL)\n";
        cout << "2 = Error con archivo\n";
        cout << "3 = Acceso de usuario (SECURITY)\n";
        cout << "4 = Salir del programa\n";
        cout << "5 = Testing\n";
        cout << "Opcion: " << endl;
        cin >> opcion;
        
       if (cin.fail()) { //Caso en el q se elija algo distinto a un int
            cout << "Opcion invalida. escoja un numero valido.\n";
            cin.clear();
            cin.ignore(10000, '\n');  
            continue;
        }
        cin.ignore();

        if (opcion == 1){
            int error;
            cout << "Ingresar tipo de error:\n1 = [DEBUG]\n2 = [INFO]\n3 = [WARNING]\n4 = [ERROR]\n5 = [CRITICAL]" << endl;
            cin >> error;
            if (error < 1 || error > 5) {
                cout << "Opcion inválida. Debe ingresar un número entre 1 y 5." << endl;
            } else {
                cout << "Has elegido la opción " << error << "." << endl;
            }
            cin.ignore();
            string logMessage;
            cout << "Ingresar el Mensaje acerca del evento:" << endl;
            getline(cin,logMessage);
            logMensaje(logMessage,error);
            cout<< "Mensaje añadido exitosamente.\n";}
        else if (opcion == 2){
            string errorMessage;
            string file;
            int line;
            cout << "Por favor ingrese el tipo de error recibido: " << endl;
            getline(cin, errorMessage);
            cout << "Por favor ingrese el nombre del archivo: " << endl;
            getline(cin, file);
            cout << "Por favor ingrese el numero de la linea del error: " << endl;
            cin >> line;
            logMensaje(errorMessage,file,line);
            cout<< "Mensaje añadido exitosamente.\n";}
        else if (opcion == 3){
            string accessmessage;
            string username;
            cout << "Por favor ingrese el mensaje de acceso: " << endl;
            getline(cin, accessmessage);
            cout << "Por favor ingrese el nombre del usuario: " << endl;
            getline(cin, username);
            logMensaje(accessmessage,username);
            cout<< "Mensaje añadido exitosamente.\n";}
        else if (opcion == 4){
            cout << "Saliendo del programa...";
            return 0;}
        else if (opcion == 5){ //Este es el testing, primero se hacen 3 casos de las funciones y luego se intenta dividir por cero para lograr un runtime error y anotarlo en el log
            logMensaje("El sistema ha iniciado correctamente.", 2);
            logMensaje("inicio sesion.", "panchokrinisky");
            logMensaje("No se emcontro el archivo", "datos.txt", 45);

            try {
                int a = 5;
                int b = 0;
                if (b == 0) {
                    throw runtime_error("Se intento dividir por cero");
                }
                int c = a / b;
                cout << "Resultado: " << c << endl;
            } catch (exception& error) {
                logMensaje(error.what(), "HW1.2_krinisky.cpp", __LINE__);
                cout << "Error detectado. Saliendo del programa..." << endl;
                return 1;
            }
            cout << "El programa termino correctamente." << endl;
            return 0;
        }
        else{
            cout << "Opcion no valida, intente de nuevo" << endl;
            continue;}
    }while (opcion !=4);
}


