/* 
 * File:   main.cpp
 * Author: Leo Monsalvo
 *
 * Created on 23 de octubre de 2017, 08:50 PM
 */

#include <iostream>
#include <stdlib.h> //Llamada de las libreriras a utilizar en el programa principal
#include <time.h>
#include "Matriz.h"

using namespace std;
void menu ();//Se crea la funcion menu

int main() { //Funcion principal
    
    Matriz A; //Se crea un objeto A de tipo Matriz !
    
    char op = '0'; //Contador que se usara para iterar el menu
    
    while (op >= '1' || op < '9' ){ //Ciclo while para establecer condicion de menu!
        
        menu(); //Llamado de la funcion menu () en el programa principal
        cin >> op;//Se le pide al usuario que escoja una opcion para proceder
        
        switch (op){ //Esocje depende a la variable op
            case '1':
            	cin >> A; //Se pide la matriz o el objeto de tipo Matriz (A)
                A.LlenarMO(A);//Llamado a la funcion con parametro para llenar la matriz (Llenar MatrizO)
                A.LlenarMX(A);//Se llena la Matriz de X
                A.LlenarMY(A);//Se llena la Matriz de Y
                A.LlenarMZ(A);//Se llena la Matriz de Z
                A.LLenarMK(A);//Se llena la matriz de K
                
                break;
            
            case '2':
                
                A.MuestraMO(A);//Funcion que permite mostrar la Matriz original
                
                break;
              
            case '3':
                
                A.MatrizTrasnp(A);
                
                break;    
                
            case '4':
                A.MuestraMX(A);//Funcion que permite hacer el llamado a las matrices X;Y;Z;K
                cout << "\n";
                A.MuestraMY(A); //Se imprimen las matrices
                cout << "\n";
                A.MuestraMZ(A);
                cout << "\n";
                A.MuestraMK(A);
                break;    
                
            case '5':
                A.DetMO(A);// Se halla el determinante de la matriz original
                
                break;   
            
            case '6':
                
                // Se hallan los determinantes de todas las matrices derivadas de la original
                cout << "\nDETERMINANTE DE LA MATRIZ X\n";
                A.DetMX(A);
                cout <<"\n";
                
                cout << "\nDETERMINANTE DE LA MATRIZ Y\n";
                A.DetMY(A);
                cout <<"\n";
                
                cout << "\nDETERMINANTE DE LA MATRIZ Z\n";
                A.DetMZ(A);
                cout <<"\n";
                
                cout << "\nDETERMINANTE DE LA MATRIZ K\n";
                A.DetMK(A);
                cout <<"\n";
                
                break;
            case '7':
                //Ultimo paso, se muestran los valores de todas las incognitas
                A.Cramer(A);
                break;
                
            case '8':
                cout << "\n\tGRACIAS POR USAR NUESTROS SERVICIOS!!!\n";//Mensaje de despedida!!!
                exit (1); //Se culmina el programa por la opcion dada    
                break;    
                
            default: //por defecto si el usuario escoge un numero fuera de rango, mandara este mensaje!
                cout << "\nERROR EN LA OPCION!\n";
                break;
            op = '0';    
        }
      
    }

    return 2017;

}

void menu (){ //Se establece lo que hara el menu!
    
    cout << "\n\tMATRICES EL PROFE JIREN ";
    cout << "\n1)DIGITE LOS DATOS DE LAS MATRICES";
    cout << "\n2)OBSERVE MATRIZ ORIGINAL";
    cout << "\n3)OBSERVE LA MATRIZ TRANSPUESTA ORIGINAL";
    cout << "\n4)OBSERVE LAS MATRICES X,Y,Z,K";
    cout << "\n5)HALLAR DETERMINANTE DE LA MATRIZ ORIGINAL";
    cout << "\n6)HALLAR DETERMINANTE DE LAS MATRICES X,Y,Z,K";
    cout << "\n7)HALLAR INCOGNITAS (CRAMER)";
    cout << "\n8)SALIR DEL PROGRAMA";
    cout <<"\n\nDigite una opcion valida: ";
}