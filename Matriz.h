/* 
 * File:   Matriz.h
 * Author: Leo Monsalvo
 *
 * Created on 23 de octubre de 2017, 08:51 PM
 */

#ifndef MATRIZ_H
#define MATRIZ_H

// Se definen las librerias necesarias
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Definimos la clase matriz junto con su contenido
class Matriz{
    
    //Sobre carga del operador istream 
    friend istream &operator >> (istream &, Matriz &);
    
public: //Se implementaran los metodos que se van a utilizar 
    
    Matriz (); //Constructor de matriz sin ningun paramatro
    void LlenarMO ( Matriz &)const; //Se llena la matriz original
    void LlenarMX ( Matriz &)const;//Se llena la matriz de sistema lineal x
    void LlenarMY ( Matriz &)const;//Llena matriz sistema lineal Y
    void LlenarMZ ( Matriz &)const; //Llena matriz sistema lineal Z
    void LLenarMK (Matriz &)const; //Llena matriz sistema lineal K
    float DetMO (Matriz &)const; //Metodo para hallar el determinante matriz original
    float DetMX (Matriz &)const; //Metodo para hallar el determinante de la matriz de X
    float DetMY (Matriz &)const;//Metodo para hallar el determinante de la matriz de Y
    float DetMZ (Matriz &)const;//Metodo para hallar el determinante de la matriz de Z
    float DetMK (Matriz &)const;//Metodo para hallar el determinante de la matriz de K
    float Cramer (Matriz &)const; //Metodo cramer para hallar sistema de ecuaciones
    void MuestraMO (Matriz &)const; //Impresion de la matriz
    void MatrizTrasnp (Matriz &)const; // Se obtiene la matriz transpuesta de la matriz original
    void MuestraMX (Matriz &)const;//Impresion matriz X
    void MuestraMY (Matriz &)const;//Impresion matriz Y
    void MuestraMZ (Matriz &)const; //Impresion matriz Z
    void MuestraMK (Matriz &)const; //Impresion matriz K
    
private://Atributos de la clase 
    
    float DetO; //Variable del determinante de la matriz original
    float VarO[16];//Variable auxiliar para hallar determinante Original
    float VarX[16];//Variable auxiliar para hallar determinante de X
    float VarY[16];//Variable auxiliar para hallar determinante de Y
    float VarZ[16];//Variable auxiliar para hallar determinante de Z
    float VarK[16];//Variable auxiliar para hallar determinante de K
    float matriz[4][4]; //Vector en donde se va a guardar la matriz original
    float matrizX[4][4];//Matriz donde se guarda la variable X
    float matrizY[4][4];//Matriz donde se guarda la variable Y
    float matrizZ[4][4];//Matriz donde se guarda la variable Z
    float matrizK[4][4]; //Matriz donde se guarda la variable K
    float Var[4];//Para determinante de las matrices de X,Y,Z,K
    int numF, numC; //Variables fila y columnas 
    float X,Y,Z,K; //Estos valores seran utilizados para los valores a los que estan igualados los sistemas
    //De ecuaciones lienales
    
};

//Constructor por defecto
Matriz::Matriz() {
    
    //Valores por defecto de los atributos para  no dañar el programa
    numF = 4; 
    numC = 4;
    DetO = 0.0 ;
    X = 0; //Variables de igualacion de los sistemas de ecuaciones
    Y = 0;
    Z = 0;
    K = 0;
    
    //A partir de aqui se llenan la matrices por defecto
    
    //Matriz Original por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matriz[i][j]= 0;
        }
    }
    
    //Matriz transpuesta por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matriz[j][i]= 0; 
        }
    }
    
    //Matriz de X por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matrizX[i][j]= 0;
        }
    }
    
    //Se llena el vector de 4 posiciones para variables de vectores X,Y,Z,K
    for (int i = 0;i<4;i++){
        Var[i]= 0;
    }
    
    //Se llena el vector de 16 posiciones para variables de vector original
    for (int i = 0;i<16;i++){
        VarO[i]= 0;
    }
    
    //Se llena el vector de 16 posiciones para variables de vector de X
    for (int i = 0;i<16;i++){
        VarX[i]= 0;
    }
    
    //Se llena el vector de 16 posiciones para variables de vector de Y
    for (int i = 0;i<16;i++){
        VarY[i]= 0;
    }
    
    //Se llena el vector de 16 posiciones para variables de vector de Z
    for (int i = 0;i<16;i++){
        VarZ[i]= 0;
    }
    
    //Se llena el vector de 16 posiciones para variables de vector de K
    for (int i = 0;i<16;i++){
        VarK[i]= 0;
    }
    
    //Matriz de Y por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matrizY[i][j]= 0;
        }
    }
    
    //Matriz de Z por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matrizZ[i][j]= 0;
        }
    }
    
    //Matriz de K por defecto
    for (int i = 0;i<numF;i++){
        for (int j = 0;j<numC;j++){
            matrizK[i][j]= 0;
        }
    }
    
}

//Sobre carga de operador istream para pedir datos!!!
istream &operator >> (istream &entrada, Matriz &a){
    
    // Se valida para que el numero de filas no sea menor a 0 y tampoco mayor a 4
    do{
        cout << "Ingrese numero de filas: "; 
        entrada >> a.numF;
        
    }while (a.numF < 1 || a.numF > 4);
    
    // Se valida para que el numero de columnas no sea menor a 0 y tampoco mayor a 4
    do{
        cout << "Ingrese el numero de columnas: ";
        entrada >> a.numC;
    }while (a.numC <1 || a.numC > 4);
    
    while(a.numF != a.numC){//Mientras las filas y columnas y filas sean diferentes se condiciona con 
        //Ciclo whie
        
        cout << "\nESTE PROGRAMA SOLO PERMITE MATRICES CUADRADAS\n";
        cout << "Ingrese nuevamente los valores !\n\n";
        
        do{
            cout << "Ingrese numero de filas: "; 
        entrada >> a.numF;
        }while (a.numF < 1 || a.numF > 4);
    
        // Se valida para que el numero de columnas no sea menor a 0 y tampoco mayor a 4
        do{
            cout << "Ingrese el numero de columnas: ";
            entrada >> a.numC;
        }while (a.numC <1 || a.numC > 4);
    }
    
    cout << "\nIngrese los valores de igualacion del sistema de ecuaciones lineales\n";
    //Ejemplo 2x+3y+4z = 2
            //5x+2y+2z = 0
            //4x+8y+9z = 3
    //Donde los valores que estan igualados en cada una de las ecuaciones corresponde a lo mencionado
    //Por el mensaje que es enviado por el programa
    
    cout <<"\nIngrese valor 1: ";
    cin >> a.X;
    cout <<"\nIngrese valor 2: ";
    cin >> a.Y;
    cout <<"\nIngrese valor 3: ";
    cin >> a.Z;
    cout <<"\nIngrese valor 4: ";
    cin >> a.K;
    
    return entrada; //Se retornan los datos de entrada
}

void Matriz::LlenarMO( Matriz &a) const{
    
    //Si el numero de filas es mayor o igual a 2 y menor o igual a 4 este entrara en el ciclo
    if ((a.numF >=2 && a.numF <=4) && (a.numC >=2 && a.numC <=4)){
        if (a.numF == 2 && a.numC ==2){
            
            //Nos dice que tipo de matriz es y su orden 
            cout << "\nEs una matriz cuadrada, puede proceder a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
            cout << "\n";
            
            //Ciclo anidado que nos permite rellenar la matriz desde sus filas hasta columnas 
            for (int i = 0; i<a.numF; i++){
                for (int j = 0; j<a.numC; j++){
                cout << "Ingrese valor en la posicion ["<<i+1<<"]["<<j+1<<"]: ";
                cin >> a.matriz[i][j]; 
            }
        }
            
        }else{//Si no se cumple la condicion entonces es porque es esta!
            if (a.numF == 3 && a.numC == 3){
                
                cout << "\nEs una matriz cuadrada, puede proceder a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
                cout << "\n";
                for (int i = 0; i<a.numF; i++){
                    for (int j = 0; j<a.numC; j++){
                    cout << "Ingrese valor en la posicion ["<<i+1<<"]["<<j+1<<"]: ";
                    cin >> a.matriz[i][j]; 
                    }
                }
                
            }else{//Si tampoco se cumple aquella es porque es esta
                if (a.numF ==4 && a.numC ==4){
                    
                    cout << "\nEs una matriz cuadrada, puede proceder a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
                    cout << "\n";
                    for (int i = 0; i<a.numF; i++){
                        for (int j = 0; j<a.numC; j++){
                        cout << "Ingrese valor en la posicion ["<<i+1<<"]["<<j+1<<"]: ";
                        cin >> a.matriz[i][j]; 
                        }
                    }
                    
                }else{//Si las filas son diferentes a las columnas no se puede trabajar
                    //Puesto que el programa solo trabaja con matrices cuadradas
                    if (a.numF != a.numC){
                        cout << "\nLas matrices no son de orden cuadrado, no se puede trabajar con ellas\n";
                    }
                }
            }
        }
    }
}

//Funcion para llenar la matriz de X respecto a la matriz original
void Matriz::LlenarMX( Matriz &a) const{
    
    if (a.numF == 2 && a.numC ==2){ //Se condiciona el programa
            
        cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
        
        cout << "\n";
        //Se copian los valores de la matriz original en la matriz de X
        for (int i = 0; i<a.numF;i++){
            for (int j = 0; j<a.numC;j++){
                a.matrizX[i][j] = a.matriz[i][j];
            }
        }
        //Se cambian los valores de la matriz X reemplazando tal cual como se haría en un sistema
        //De ecuaciones
        for (int i = 0; i<a.numF;i++){
            for (int j = 0;j<a.numF;j++){
                a.matrizX[0][0] = a.X;
                a.matrizX[1][0] = a.Y;
            }
        }
    }else{
        if (a.numF == 3 && a.numC == 3){
                
            cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
            
            cout << "\n";
            //Se llena la matriz con los respectivos nuevamente, debido a que es otra condicion
            for (int i = 0; i<a.numF;i++){
                for (int j = 0;j<a.numF;j++){
                    a.matrizX[i][j]=a.matriz[i][j];
                }
            }
            //Se copian los valores para una nueva condicion
            for (int i = 0; i<a.numF; i++){
                for (int j = 0; j<a.numC; j++){
                    
                    a.matrizX[0][0] = a.X;
                    a.matrizX[1][0] = a.Y;
                    a.matrizX[2][0] = a.Z;
                    
                }
            }
        }else{
            if (a.numF == 4 && a.numC == 4){
                cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
                
                cout << "\n";
                
                //Se llena la matriz con los respectivos nuevamente, debido a que es otra condicion
                for (int i = 0; i<a.numF;i++){
                    for (int j = 0;j<a.numF;j++){
                        a.matrizX[i][j]=a.matriz[i][j];
                    }
                }
                
                //Se copian los valores para una nueva condicion
                for (int i = 0; i<a.numF; i++){
                    for (int j = 0; j<a.numC; j++){
                    
                        a.matrizX[0][0] = a.X;
                        a.matrizX[1][0] = a.Y;
                        a.matrizX[2][0] = a.Z;
                        a.matrizX[3][0] = a.K;
                    }
                }
            }
        }    
    }
}

void Matriz::LlenarMY( Matriz &a) const{
    
    if (a.numF == 2 && a.numC ==2){ //Se condiciona el programa
            
        cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
        
        cout << "\n";
        //Se copian los valores de la matriz original en la matriz de X
        for (int i = 0; i<a.numF;i++){
            for (int j = 0; j<a.numC;j++){
                a.matrizY[i][j] = a.matriz[i][j];
            }
        }
        //Se cambian los valores de la matriz X reemplazando tal cual como se haría en un sistema
        //De ecuaciones
        for (int i = 0; i<a.numF;i++){
            for (int j = 0;j<a.numF;j++){
                a.matrizY[0][1] = a.X;
                a.matrizY[1][1] = a.Y;
            }
        }
    }else{
        if (a.numF == 3 && a.numC == 3){
                
            cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
            
            cout << "\n";
            //Se llena la matriz con los respectivos nuevamente, debido a que es otra condicion
            for (int i = 0; i<a.numF;i++){
                for (int j = 0;j<a.numF;j++){
                    a.matrizY[i][j]=a.matriz[i][j];
                }
            }
            //Se copian los valores para una nueva condicion
            for (int i = 0; i<a.numF; i++){
                for (int j = 0; j<a.numC; j++){
                    
                    a.matrizY[0][1] = a.X;
                    a.matrizY[1][1] = a.Y;
                    a.matrizY[2][1] = a.Z;
                    
                }
            }
        }else{
            if (a.numF == 4 && a.numC == 4){
                cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;
                
                cout << "\n";
                
                //Se llena la matriz con los respectivos nuevamente, debido a que es otra condicion
                for (int i = 0; i<a.numF;i++){
                    for (int j = 0;j<a.numF;j++){
                        a.matrizY[i][j]=a.matriz[i][j];
                    }
                }
                
                //Se copian los valores para una nueva condicion
                for (int i = 0; i<a.numF; i++){
                    for (int j = 0; j<a.numC; j++){
                    
                        a.matrizY[0][1] = a.X;
                        a.matrizY[1][1] = a.Y;
                        a.matrizY[2][1] = a.Z;
                        a.matrizY[3][1] = a.K;
                    }
                }
            }
        }    
    }
}

void Matriz::LlenarMZ( Matriz &a) const{

    if (a.numF == 2 && a.numC == 2){
        cout << "\n LA MATRIZ EN Z ES INEXISTENTE\n";
    }
    
    if (a.numF == 3 && a.numC == 3){
                
        cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;

        cout << "\n";
        //Se llena la matriz con los respectivos nuevamente, debido a que es otra condicion
        for (int i = 0; i<a.numF;i++){
            for (int j = 0;j<a.numF;j++){
                a.matrizZ[i][j]= a.matriz[i][j];
            }
        }   
        //Se copian los valores para una nueva condicion
        for (int i = 0; i<a.numF; i++){
            for (int j = 0; j<a.numC; j++){

                a.matrizZ[0][2] = a.X;
                a.matrizZ[1][2] = a.Y;
                a.matrizZ[2][2] = a.Z;

            }   
        }
    }else{
           if (a.numF == 4 && a.numC == 4){
               cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " <<a.numF <<"X" << a.numC;

               cout << "\n";
               //Se copian los valores para una nueva condicion
               for (int i = 0;i<a.numF;i++){
                   for (int j = 0;j<a.numC;j++){
                       a.matrizZ[i][j]= a.matriz[i][j];
                   }
               }
               for (int i = 0; i<a.numF; i++){
                   for (int j = 0; j<a.numC; j++){

                       a.matrizZ[0][2] = a.X;
                       a.matrizZ[1][2] = a.Y;
                       a.matrizZ[2][2] = a.Z;
                       a.matrizZ[3][2] = a.K;
                   }
               }          
           }
        }
}

void Matriz::LLenarMK(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2) {
        cout << "\n LA MATRIZ EN K ES INEXISTENTE\n";
    }

    if (a.numF == 3 && a.numC == 3) {
        cout << "\nLa MATRIZ EN K ES INEXISTENTE\n";
 
    } else{
        if (a.numF == 4 && a.numC == 4) {
            cout << "\nEs una matriz cuadrada, se procede a llenarla " << "Orden " << a.numF << "X" << a.numC;

            cout << "\n";
            //Se copian los valores para una nueva condicion
            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {
                    a.matrizK[i][j] = a.matriz[i][j];
                }
            }
            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {

                    a.matrizK[0][3] = a.X;
                    a.matrizK[1][3] = a.Y;
                    a.matrizK[2][3] = a.Z;
                    a.matrizK[3][3] = a.K;
                }
            }
        }
    }
    
}

void Matriz::MuestraMO(Matriz &a)const{ //Funcion encargada de mostrar la matriz original
    
    //Para mostrar la matriz se anidan los ciclos para que recorran todo el vector enseñando los valores
    //Para cada una de las posiciones existente    
    cout << "\nMATRIZ ORIGINAL\n";
    for (int i = 0; i < a.numF; i++) {
        for (int j = 0; j < a.numC; j++) {
            cout << "|" << a.matriz[i][j] << "  |";
        }
        cout << "\n";
    }
}

void Matriz::MatrizTrasnp(Matriz &a) const{
    
    //Notese que para obtener la matriz transpuesta intercambiamos las filas y columnas
    cout << "\nMATRIZ TRANSPUESTA ORIGINAL\n";
    for (int i = 0; i < a.numF; i++) {
        for (int j = 0; j < a.numC; j++) {
            cout << "|" << a.matriz[j][i] << "  |"; //Se intercambian las filas y columnas
                                                    //Y asi se obtiene la matriz traspuesta
        }
        cout << "\n";
    }
    
}


void Matriz::MuestraMX(Matriz &a) const{
    
    //Se condiciona para poder recorrer la matriz dependiendo del numero de filas y columnas existentes

    cout << "\nMATRIZ DE X\n";
    for (int i = 0; i < a.numF; i++) {
        for (int j = 0; j < a.numC; j++) {
            cout << "|" << a.matrizX[i][j] << "  |";
        }
        cout << "\n";
    }
    
}

void Matriz::MuestraMY(Matriz &a) const{
    
    //Se condiciona para poder recorrer la matriz dependiendo del numero de filas y columnas existentes
    if (a.numF == 2 && a.numC ==2){
        
        cout << "\nMATRIZ DE Y\n";
        for (int i = 0; i<a.numF;i++){
            for (int j = 0; j<a.numC; j++){
                cout << "|" <<  a.matrizY[i][j] << "  |";
            }
            cout << "\n";
        }    
    }else{//Condicion no cumplida, entra en esta
        if (a.numF == 3 && a.numC == 3){
            
            cout << "\nMATRIZ DE Y\n";
            for (int i = 0; i<a.numF;i++){
                for (int j = 0; j<a.numC; j++){
                    cout << "|" <<  a.matrizY[i][j] << "  |";
                }
                cout << "\n";
            }
            
        }else{//Ultima condicion es esta... El usuario debe saber que es de orden nxn y hasta donde llega
            if(a.numF == 4 && a.numC == 4){
                
                cout << "\nMATRIZ DE Y\n";
                for (int i = 0; i<a.numF;i++){
                    for (int j = 0; j<a.numC; j++){
                        cout << "|" <<  a.matrizY[i][j] << "  |";
                    }
                cout << "\n";
                }
                
            }
        }
    }
    
}

void Matriz::MuestraMZ(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2){
        cout << "\nMATRIZ DE Z\n";
        for (int i = 0; i < a.numF; i++) {
            for (int j = 0; j < a.numC; j++) {
                cout << "|" << "MATRIZ DE Z INEXISTENTE" << "  |";
            }
            cout << "\n";
        }
    }
    
    if (a.numF == 3 && a.numC == 3) {

        cout << "\nMATRIZ DE Z\n";
        for (int i = 0; i < a.numF; i++) {
            for (int j = 0; j < a.numC; j++) {
                cout << "|" << a.matrizZ[i][j] << "  |";
            }
            cout << "\n";
        }

    } else {//Ultima condicion es esta... El usuario debe saber que es de orden nxn y hasta donde llega
        if (a.numF == 4 && a.numC == 4) {

            cout << "\nMATRIZ DE Z\n";
            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {
                    cout << "|" << a.matrizZ[i][j] << "  |";
                }
                cout << "\n";
            }

        }
    }
}

void Matriz::MuestraMK(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2){
        cout << "\nMATRIZ DE K\n";
        for (int i = 0; i < a.numF; i++) {
            for (int j = 0; j < a.numC; j++) {
                cout << "|" << "MATRIZ DE K INEXISTENTE" << "  |";
            }
            cout << "\n";
        }
    }
    
    if (a.numF == 3 && a.numC == 3) {

        cout << "\nMATRIZ DE K\n";
        for (int i = 0; i < a.numF; i++) {
            for (int j = 0; j < a.numC; j++) {
                cout << "|" << "MATRIZ DE K INEXISTENTE" << "  |";
            }
            cout << "\n";
        }

    } else {//Ultima condicion es esta... El usuario debe saber que es de orden nxn y hasta donde llega
        if (a.numF == 4 && a.numC == 4) {

            cout << "\nMATRIZ DE K\n";
            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {
                    cout << "|" << a.matrizZ[i][j] << "  |";
                }
                cout << "\n";
            }

        }
    }
    
}

float Matriz::DetMO(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2){
        
        for (int i = 0;i<a.numF;i++){
            for (int j = 0;j<a.numC;j++){
                //Se halla el determinante inmediato
                a.DetO = (a.matriz[0][0]*a.matriz[1][1])-(a.matriz[0][1]*a.matriz[1][0]);
            }
        }
        
        //Propiedad que dice que si el determinante es diferente de 0
        if (a.DetO !=0){
            cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
            cout << "\nDETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
            cout << "\n";
        }else{
            
            //Si el determinate de la matriz original es 0, entonces puede que sea incompatible
            if(a.DetO == 0){
                cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                cout << "DETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
                cout << "\n";
            }
        }
        
        
    }else{
        if (a.numF == 3 && a.numC == 3){
            
            for (int i = 0;i<a.numF;i++){
                for (int j = 0;j<a.numC;j++){
                    //Se halla el cofactor numero 1
                    a.VarO[0] = (a.matriz[0][0]*((a.matriz[1][1]*a.matriz[2][2])-(a.matriz[1][2]*a.matriz[2][1])));
                    //Se halla el cofactor numero 2
                    a.VarO[1] = -(a.matriz[0][1]*((a.matriz[1][0]*a.matriz[2][2])-(a.matriz[1][2]*a.matriz[2][0])));
                    //Ultimo cofactor numero 3
                    a.VarO[2] = (a.matriz[0][2]*((a.matriz[1][0]*a.matriz[2][1])-(a.matriz[1][1]*a.matriz[2][0])));
                }
            }
            a.DetO = a.VarO[0]+a.VarO[1]+a.VarO[2];
            
            if (a.DetO !=0){
                cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                cout << "\nDETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
                cout << "\n";
            }else{
                if(a.DetO == 0){
                    cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                    cout << "DETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
                    cout << "\n";
                }   
            }
            
        }else{
            if (a.numF == 4 && a.numC == 4){
                for (int i = 0;i<a.numF;i++){
                    for (int j = 0;j<a.numC;j++){
                        
                        //Estas opereciones son necesarias para hallar los cofactores de una matriz tan grande
                        //Cada operacion es vital para determinar los valores de forma exacta!!!
                        a.VarO[0] = (a.matriz[1][1]*((a.matriz[2][2]*a.matriz[3][3])-(a.matriz[2][3]*a.matriz[3][2])));
                        a.VarO[1] = -(a.matriz[1][2]*((a.matriz[2][1]*a.matriz[3][3])-(a.matriz[2][3]*a.matriz[3][1])));
                        a.VarO[2] = (a.matriz[1][3]*((a.matriz[2][1]*a.matriz[3][2])-(a.matriz[2][2]*a.matriz[3][1])));
                        //Se halla el primer cofactor
                        a.VarO[3] = (a.VarO[0]+a.VarO[1]+a.VarO[2])*a.matriz[0][0];
                        
                        a.VarO[4] = (a.matriz[0][1]*((a.matriz[2][2]*a.matriz[3][3])-(a.matriz[2][3]*a.matriz[3][2])));
                        a.VarO[5] = -(a.matriz[0][2]*((a.matriz[2][1]*a.matriz[3][3])-(a.matriz[2][3]*a.matriz[3][1])));
                        a.VarO[6] = (a.matriz[0][3]*((a.matriz[2][1]*a.matriz[3][2])-(a.matriz[2][2]*a.matriz[3][1])));
                        //Se halla el segundo cofactor
                        a.VarO[7] = (a.VarO[4]+a.VarO[5]+a.VarO[6])*-a.matriz[1][0];
                        
                        a.VarO[8] = (a.matriz[0][1]*((a.matriz[1][2]*a.matriz[3][3])-(a.matriz[1][3]*a.matriz[3][2])));
                        a.VarO[9] = -(a.matriz[0][2]*((a.matriz[1][1]*a.matriz[3][3])-(a.matriz[1][3]*a.matriz[3][1])));
                        a.VarO[10] = (a.matriz[0][3]*((a.matriz[1][1]*a.matriz[3][2])-(a.matriz[1][2]*a.matriz[3][1])));
                        //Se halla el 3er cofactor
                        a.VarO[11] = (a.VarO[8]+a.VarO[9]+a.VarO[10])*a.matriz[2][0];
                        
                        a.VarO[12] = (a.matriz[0][1]*((a.matriz[1][2]*a.matriz[2][3])-(a.matriz[1][3]*a.matriz[2][2])));
                        a.VarO[13] = -(a.matriz[0][2]*((a.matriz[1][1]*a.matriz[2][3])-(a.matriz[1][3]*a.matriz[2][1])));
                        a.VarO[14] = (a.matriz[0][3]*((a.matriz[1][1]*a.matriz[2][2])-(a.matriz[1][2]*a.matriz[2][1])));
                        //Se halla el 4to cofactor
                        a.VarO[15] = (a.VarO[12]+a.VarO[13]+a.VarO[14])*-a.matriz[3][0];
                        
                    }
                }
                a.DetO = a.VarO[3]+a.VarO[7]+a.VarO[11]+a.VarO[15];
                
                if (a.DetO !=0){
                    cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                    cout << "\nDETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
                    cout << "\n";
                }else{
                    if(a.DetO == 0){
                        cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                        cout << "DETERMINANTE DE LA MATRIZ ORIGINAL: " << a.DetO;
                        cout << "\n";
                    }   
                }
                
            }
        }
    }
    // Se retorna el determinante final
    return a.DetO;
}

float Matriz::DetMX(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2){
        
        for (int i = 0;i<a.numF;i++){
            for (int j = 0;j<a.numC;j++){
                //Se halla el determinante inmediato
                a.Var[0] = (a.matrizX[0][0]*a.matrizX[1][1])-(a.matrizX[0][1]*a.matrizX[1][0]);
            }
        }
        if (a.Var[0] !=0){
            cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
            cout << "\nDETERMINANTE DE LA MATRIZ DE X: " << a.Var[0];
            cout << "\n";
        }else{
            if(a.Var[0] == 0){
                cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                cout << "DETERMINANTE DE LA MATRIZ X: " << a.Var[0];
                cout << "\n";
            }
        }
        
        
    }else{
        if (a.numF == 3 && a.numC == 3){
            
            for (int i = 0;i<a.numF;i++){
                for (int j = 0;j<a.numC;j++){
                    //Se halla el cofactor numero 1
                    a.VarX[0] = (a.matrizX[0][0]*((a.matrizX[1][1]*a.matrizX[2][2])-(a.matrizX[1][2]*a.matrizX[2][1])));
                    //Se halla el cofactor numero 2
                    a.VarX[1] = -(a.matrizX[0][1]*((a.matrizX[1][0]*a.matrizX[2][2])-(a.matrizX[1][2]*a.matrizX[2][0])));
                    //Ultimo cofactor numero 3
                    a.VarX[2] = (a.matrizX[0][2]*((a.matrizX[1][0]*a.matrizX[2][1])-(a.matrizX[1][1]*a.matrizX[2][0])));
                }
            }
            a.Var[0] = a.VarX[0]+a.VarX[1]+a.VarX[2];
            
            if (a.Var[0] !=0){
                cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                cout << "\nDETERMINANTE DE LA MATRIZ X: " << a.Var[0];
                cout << "\n";
            }else{
                if(a.Var[0] == 0){
                    cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                    cout << "DETERMINANTE DE LA MATRIZ X: " << a.Var[0];
                    cout << "\n";
                }   
            }
            
        }else{
            if (a.numF == 4 && a.numC == 4){
                for (int i = 0;i<a.numF;i++){
                    for (int j = 0;j<a.numC;j++){
                        
                        //Estas opereciones son necesarias para hallar los cofactores de una matriz tan grande
                        //Cada operacion es vital para determinar los valores de forma exacta!!!
                        a.VarX[0] = (a.matrizX[1][1]*((a.matrizX[2][2]*a.matrizX[3][3])-(a.matrizX[2][3]*a.matrizX[3][2])));
                        a.VarX[1] = -(a.matrizX[1][2]*((a.matrizX[2][1]*a.matrizX[3][3])-(a.matrizX[2][3]*a.matrizX[3][1])));
                        a.VarX[2] = (a.matrizX[1][3]*((a.matrizX[2][1]*a.matrizX[3][2])-(a.matrizX[2][2]*a.matrizX[3][1])));
                        //Se halla el primer cofactor
                        a.VarX[3] = (a.VarX[0]+a.VarX[1]+a.VarX[2])*a.matrizX[0][0];
                        
                        a.VarX[4] = (a.matrizX[0][1]*((a.matrizX[2][2]*a.matrizX[3][3])-(a.matrizX[2][3]*a.matrizX[3][2])));
                        a.VarX[5] = -(a.matrizX[0][2]*((a.matrizX[2][1]*a.matrizX[3][3])-(a.matrizX[2][3]*a.matrizX[3][1])));
                        a.VarX[6] = (a.matrizX[0][3]*((a.matrizX[2][1]*a.matrizX[3][2])-(a.matrizX[2][2]*a.matrizX[3][1])));
                        //Se halla el segundo cofactor
                        a.VarX[7] = (a.VarX[4]+a.VarX[5]+a.VarX[6])*-a.matrizX[1][0];
                        
                        a.VarX[8] = (a.matrizX[0][1]*((a.matrizX[1][2]*a.matrizX[3][3])-(a.matrizX[1][3]*a.matrizX[3][2])));
                        a.VarX[9] = -(a.matrizX[0][2]*((a.matrizX[1][1]*a.matrizX[3][3])-(a.matrizX[1][3]*a.matrizX[3][1])));
                        a.VarX[10] = (a.matrizX[0][3]*((a.matrizX[1][1]*a.matrizX[3][2])-(a.matrizX[1][2]*a.matrizX[3][1])));
                        //Se halla el 3er cofactor
                        a.VarX[11] = (a.VarX[8]+a.VarX[9]+a.VarX[10])*a.matrizX[2][0];
                        
                        a.VarX[12] = (a.matrizX[0][1]*((a.matrizX[1][2]*a.matrizX[2][3])-(a.matrizX[1][3]*a.matrizX[2][2])));
                        a.VarX[13] = -(a.matrizX[0][2]*((a.matrizX[1][1]*a.matrizX[2][3])-(a.matrizX[1][3]*a.matrizX[2][1])));
                        a.VarX[14] = (a.matrizX[0][3]*((a.matrizX[1][1]*a.matrizX[2][2])-(a.matrizX[1][2]*a.matrizX[2][1])));
                        //Se halla el 4to cofactor
                        a.VarX[15] = (a.VarX[12]+a.VarX[13]+a.VarX[14])*-a.matrizX[3][0];
                        
                    }
                }
                a.Var[0] = a.VarX[3]+a.VarX[7]+a.VarX[11]+a.VarX[15];
                
                if (a.Var[0] !=0){
                    cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                    cout << "\nDETERMINANTE DE LA MATRIZ X: " << a.Var[0];
                    cout << "\n";
                }else{
                    if(a.Var[0] == 0){
                        cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                        cout << "DETERMINANTE DE LA MATRIZ X: " << a.Var[0];
                        cout << "\n";
                    }   
                }
                
            }
        }
    }
    //Retorna el determinante de la matriz X
    return a.Var[0];
}

float Matriz::DetMY(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2) {

        for (int i = 0; i < a.numF; i++) {
            for (int j = 0; j < a.numC; j++) {
                //Se halla el determinante inmediato
                a.Var[1] = (a.matrizY[0][0] * a.matrizY[1][1])-(a.matrizY[0][1] * a.matrizY[1][0]);
            }
        }
        if (a.Var[1] != 0) {
            cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
            cout << "\nDETERMINANTE DE LA MATRIZ DE Y: " << a.Var[1];
            cout << "\n";
        } else {
            if (a.Var[1] == 0) {
                cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                cout << "DETERMINANTE DE LA MATRIZ Y: " << a.Var[1];
                cout << "\n";
            }
        }


    } else {
        if (a.numF == 3 && a.numC == 3) {

            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {
                    //Se halla el cofactor numero 1
                    a.VarY[0] = (a.matrizY[0][0]*((a.matrizY[1][1] * a.matrizY[2][2])-(a.matrizY[1][2] * a.matrizY[2][1])));
                    //Se halla el cofactor numero 2
                    a.VarY[1] = -(a.matrizY[0][1]*((a.matrizY[1][0] * a.matrizY[2][2])-(a.matrizY[1][2] * a.matrizY[2][0])));
                    //Ultimo cofactor numero 3
                    a.VarY[2] = (a.matrizY[0][2]*((a.matrizY[1][0] * a.matrizY[2][1])-(a.matrizY[1][1] * a.matrizY[2][0])));
                }
            }
            a.Var[1] = a.VarY[0] + a.VarY[1] + a.VarY[2];

            if (a.Var[1] != 0) {
                cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                cout << "\nDETERMINANTE DE LA MATRIZ Y: " << a.Var[1];
                cout << "\n";
            } else {
                if (a.Var[1] == 0) {
                    cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                    cout << "DETERMINANTE DE LA MATRIZ Y: " << a.Var[1];
                    cout << "\n";
                }
            }

        } else {
            if (a.numF == 4 && a.numC == 4) {
                for (int i = 0; i < a.numF; i++) {
                    for (int j = 0; j < a.numC; j++) {

                        //Estas opereciones son necesarias para hallar los cofactores de una matriz tan grande
                        //Cada operacion es vital para determinar los valores de forma eYacta!!!
                        a.VarY[0] = (a.matrizY[1][1]*((a.matrizY[2][2] * a.matrizY[3][3])-(a.matrizY[2][3] * a.matrizY[3][2])));
                        a.VarY[1] = -(a.matrizY[1][2]*((a.matrizY[2][1] * a.matrizY[3][3])-(a.matrizY[2][3] * a.matrizY[3][1])));
                        a.VarY[2] = (a.matrizY[1][3]*((a.matrizY[2][1] * a.matrizY[3][2])-(a.matrizY[2][2] * a.matrizY[3][1])));
                        //Se halla el primer cofactor
                        a.VarY[3] = (a.VarY[0] + a.VarY[1] + a.VarY[2]) * a.matrizY[0][0];

                        a.VarY[4] = (a.matrizY[0][1]*((a.matrizY[2][2] * a.matrizY[3][3])-(a.matrizY[2][3] * a.matrizY[3][2])));
                        a.VarY[5] = -(a.matrizY[0][2]*((a.matrizY[2][1] * a.matrizY[3][3])-(a.matrizY[2][3] * a.matrizY[3][1])));
                        a.VarY[6] = (a.matrizY[0][3]*((a.matrizY[2][1] * a.matrizY[3][2])-(a.matrizY[2][2] * a.matrizY[3][1])));
                        //Se halla el segundo cofactor
                        a.VarY[7] = (a.VarY[4] + a.VarY[5] + a.VarY[6])*-a.matrizY[1][0];

                        a.VarY[8] = (a.matrizY[0][1]*((a.matrizY[1][2] * a.matrizY[3][3])-(a.matrizY[1][3] * a.matrizY[3][2])));
                        a.VarY[9] = -(a.matrizY[0][2]*((a.matrizY[1][1] * a.matrizY[3][3])-(a.matrizY[1][3] * a.matrizY[3][1])));
                        a.VarY[10] = (a.matrizY[0][3]*((a.matrizY[1][1] * a.matrizY[3][2])-(a.matrizY[1][2] * a.matrizY[3][1])));
                        //Se halla el 3er cofactor
                        a.VarY[11] = (a.VarY[8] + a.VarY[9] + a.VarY[10]) * a.matrizY[2][0];

                        a.VarY[12] = (a.matrizY[0][1]*((a.matrizY[1][2] * a.matrizY[2][3])-(a.matrizY[1][3] * a.matrizY[2][2])));
                        a.VarY[13] = -(a.matrizY[0][2]*((a.matrizY[1][1] * a.matrizY[2][3])-(a.matrizY[1][3] * a.matrizY[2][1])));
                        a.VarY[14] = (a.matrizY[0][3]*((a.matrizY[1][1] * a.matrizY[2][2])-(a.matrizY[1][2] * a.matrizY[2][1])));
                        //Se halla el 4to cofactor
                        a.VarY[15] = (a.VarY[12] + a.VarY[13] + a.VarY[14])*-a.matrizY[3][0];

                    }
                }
                a.Var[1] = a.VarY[3] + a.VarY[7] + a.VarY[11] + a.VarY[15];

                if (a.Var[1] != 0) {
                    cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                    cout << "\nDETERMINANTE DE LA MATRIZ Y: " << a.Var[1];
                    cout << "\n";
                } else {
                    if (a.Var[1] == 0) {
                        cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                        cout << "DETERMINANTE DE LA MATRIZ Y: " << a.Var[1];
                        cout << "\n";
                    }
                }

            }
        }
    }
    return a.Var[1];
}

float Matriz::DetMZ(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2) {

        cout << "\nDETERMINANTE INEXISTENTE DEBIDO A QUE LA MATRIZ ES DE ORDEN 2X2\n";


    } else {
        if (a.numF == 3 && a.numC == 3) {

            for (int i = 0; i < a.numF; i++) {
                for (int j = 0; j < a.numC; j++) {
                    //Se halla el cofactor numero 1
                    a.VarZ[0] = (a.matrizZ[0][0]*((a.matrizZ[1][1] * a.matrizZ[2][2])-(a.matrizZ[1][2] * a.matrizZ[2][1])));
                    //Se halla el cofactor numero 2
                    a.VarZ[1] = -(a.matrizZ[0][1]*((a.matrizZ[1][0] * a.matrizZ[2][2])-(a.matrizZ[1][2] * a.matrizZ[2][0])));
                    //Ultimo cofactor numero 3
                    a.VarZ[2] = (a.matrizZ[0][2]*((a.matrizZ[1][0] * a.matrizZ[2][1])-(a.matrizZ[1][1] * a.matrizZ[2][0])));
                }
            }
            a.Var[2] = a.VarZ[0] + a.VarZ[1] + a.VarZ[2];

            if (a.Var[2] != 0) {
                cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                cout << "\nDETERMINANTE DE LA MATRIZ Z: " << a.Var[2];
                cout << "\n";
            } else {
                if (a.Var[2] == 0) {
                    cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                    cout << "DETERMINANTE DE LA MATRIZ Z: " << a.Var[2];
                    cout << "\n";
                }
            }

        } else {
            if (a.numF == 4 && a.numC == 4) {
                for (int i = 0; i < a.numF; i++) {
                    for (int j = 0; j < a.numC; j++) {

                        //Estas opereciones son necesarias para hallar los cofactores de una matriz tan grande
                        //Cada operacion es vital para determinar los valores de forma eZacta!!!
                        a.VarZ[0] = (a.matrizZ[1][1]*((a.matrizZ[2][2] * a.matrizZ[3][3])-(a.matrizZ[2][3] * a.matrizZ[3][2])));
                        a.VarZ[1] = -(a.matrizZ[1][2]*((a.matrizZ[2][1] * a.matrizZ[3][3])-(a.matrizZ[2][3] * a.matrizZ[3][1])));
                        a.VarZ[2] = (a.matrizZ[1][3]*((a.matrizZ[2][1] * a.matrizZ[3][2])-(a.matrizZ[2][2] * a.matrizZ[3][1])));
                        //Se halla el primer cofactor
                        a.VarZ[3] = (a.VarZ[0] + a.VarZ[1] + a.VarZ[2]) * a.matrizZ[0][0];

                        a.VarZ[4] = (a.matrizZ[0][1]*((a.matrizZ[2][2] * a.matrizZ[3][3])-(a.matrizZ[2][3] * a.matrizZ[3][2])));
                        a.VarZ[5] = -(a.matrizZ[0][2]*((a.matrizZ[2][1] * a.matrizZ[3][3])-(a.matrizZ[2][3] * a.matrizZ[3][1])));
                        a.VarZ[6] = (a.matrizZ[0][3]*((a.matrizZ[2][1] * a.matrizZ[3][2])-(a.matrizZ[2][2] * a.matrizZ[3][1])));
                        //Se halla el segundo cofactor
                        a.VarZ[7] = (a.VarZ[4] + a.VarZ[5] + a.VarZ[6])*-a.matrizZ[1][0];

                        a.VarZ[8] = (a.matrizZ[0][1]*((a.matrizZ[1][2] * a.matrizZ[3][3])-(a.matrizZ[1][3] * a.matrizZ[3][2])));
                        a.VarZ[9] = -(a.matrizZ[0][2]*((a.matrizZ[1][1] * a.matrizZ[3][3])-(a.matrizZ[1][3] * a.matrizZ[3][1])));
                        a.VarZ[10] = (a.matrizZ[0][3]*((a.matrizZ[1][1] * a.matrizZ[3][2])-(a.matrizZ[1][2] * a.matrizZ[3][1])));
                        //Se halla el 3er cofactor
                        a.VarZ[11] = (a.VarZ[8] + a.VarZ[9] + a.VarZ[10]) * a.matrizZ[2][0];

                        a.VarZ[12] = (a.matrizZ[0][1]*((a.matrizZ[1][2] * a.matrizZ[2][3])-(a.matrizZ[1][3] * a.matrizZ[2][2])));
                        a.VarZ[13] = -(a.matrizZ[0][2]*((a.matrizZ[1][1] * a.matrizZ[2][3])-(a.matrizZ[1][3] * a.matrizZ[2][1])));
                        a.VarZ[14] = (a.matrizZ[0][3]*((a.matrizZ[1][1] * a.matrizZ[2][2])-(a.matrizZ[1][2] * a.matrizZ[2][1])));
                        //Se halla el 4to cofactor
                        a.VarZ[15] = (a.VarZ[12] + a.VarZ[13] + a.VarZ[14])*-a.matrizZ[3][0];

                    }
                }
                a.Var[2] = a.VarZ[3] + a.VarZ[7] + a.VarZ[11] + a.VarZ[15];

                if (a.Var[2] != 0) {
                    cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                    cout << "\nDETERMINANTE DE LA MATRIZ Z: " << a.Var[2];
                    cout << "\n";
                } else {
                    if (a.Var[2] == 0) {
                        cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                        cout << "DETERMINANTE DE LA MATRIZ Z: " << a.Var[2];
                        cout << "\n";
                    }
                }

            }
        }
    }
    return a.Var[2];
}

float Matriz::DetMK(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2) {

        cout << "\nDETERMINANTE INEXISTENTE DEBIDO A QUE LA MATRIZ ES DE ORDEN 2X2\n";


    } else {
        if (a.numF == 3 && a.numC == 3) {

            cout << "\nEl DETERMINANTE NO EXISTE DEBIDO A QUE LA MATRIZ ES DE ORDEN 3X3\n";

        } else {
            if (a.numF == 4 && a.numC == 4) {
                for (int i = 0; i < a.numF; i++) {
                    for (int j = 0; j < a.numC; j++) {

                        //Estas opereciones son necesarias para hallar los cofactores de una matriz tan grande
                        //Cada operacion es vital para determinar los valores de forma eZacta!!!
                        a.VarK[0] = (a.matrizK[1][1]*((a.matrizK[2][2] * a.matrizK[3][3])-(a.matrizK[2][3] * a.matrizK[3][2])));
                        a.VarK[1] = -(a.matrizK[1][2]*((a.matrizK[2][1] * a.matrizK[3][3])-(a.matrizK[2][3] * a.matrizK[3][1])));
                        a.VarK[2] = (a.matrizK[1][3]*((a.matrizK[2][1] * a.matrizK[3][2])-(a.matrizK[2][2] * a.matrizK[3][1])));
                        //Se halla el primer cofactor
                        a.VarK[3] = (a.VarK[0] + a.VarK[1] + a.VarK[2]) * a.matrizK[0][0];

                        a.VarK[4] = (a.matrizK[0][1]*((a.matrizK[2][2] * a.matrizK[3][3])-(a.matrizK[2][3] * a.matrizK[3][2])));
                        a.VarK[5] = -(a.matrizK[0][2]*((a.matrizK[2][1] * a.matrizK[3][3])-(a.matrizK[2][3] * a.matrizK[3][1])));
                        a.VarK[6] = (a.matrizK[0][3]*((a.matrizK[2][1] * a.matrizK[3][2])-(a.matrizK[2][2] * a.matrizK[3][1])));
                        //Se halla el segundo cofactor
                        a.VarK[7] = (a.VarK[4] + a.VarK[5] + a.VarK[6])*-a.matrizK[1][0];

                        a.VarK[8] = (a.matrizK[0][1]*((a.matrizK[1][2] * a.matrizK[3][3])-(a.matrizK[1][3] * a.matrizK[3][2])));
                        a.VarK[9] = -(a.matrizK[0][2]*((a.matrizK[1][1] * a.matrizK[3][3])-(a.matrizK[1][3] * a.matrizK[3][1])));
                        a.VarK[10] = (a.matrizK[0][3]*((a.matrizK[1][1] * a.matrizK[3][2])-(a.matrizK[1][2] * a.matrizK[3][1])));
                        //Se halla el 3er cofactor
                        a.VarK[11] = (a.VarK[8] + a.VarK[9] + a.VarK[10]) * a.matrizK[2][0];

                        a.VarK[12] = (a.matrizK[0][1]*((a.matrizK[1][2] * a.matrizK[2][3])-(a.matrizK[1][3] * a.matrizK[2][2])));
                        a.VarK[13] = -(a.matrizK[0][2]*((a.matrizK[1][1] * a.matrizK[2][3])-(a.matrizK[1][3] * a.matrizK[2][1])));
                        a.VarK[14] = (a.matrizK[0][3]*((a.matrizK[1][1] * a.matrizK[2][2])-(a.matrizK[1][2] * a.matrizK[2][1])));
                        //Se halla el 4to cofactor
                        a.VarK[15] = (a.VarK[12] + a.VarK[13] + a.VarK[14])*-a.matrizK[3][0];

                    }
                }
                a.Var[3] = a.VarK[3] + a.VarK[7] + a.VarK[11] + a.VarK[15];

                if (a.Var[3] != 0) {
                    cout << "\nEl SISTEMA ES COMPATIBLE DETERMINADO, DEBIDO A QUE EL DETERMINANTE ES DIFERENTE DE 0\n";
                    cout << "\nDETERMINANTE DE LA MATRIZ K: " << a.Var[3];
                    cout << "\n";
                } else {
                    if (a.Var[3] == 0) {
                        cout << "\nEL SISTEMA ES INCOMPATIBLE O COMPATIBLE INDETERMINADO DEBIDO A QUE EL DETERMINANTE ES 0\n";
                        cout << "DETERMINANTE DE LA MATRIZ K: " << a.Var[3];
                        cout << "\n";
                    }
                }

            }
        }
    }
    return a.Var[3];
}

float Matriz::Cramer(Matriz &a) const{
    
    if (a.numF == 2 && a.numC == 2){
        
        //Si todos los determinantes son 0 entonces el sistema es compatible indeterminado
        if (a.DetO == 0 & a.Var[0] == 0 && a.Var[1] == 0){
            cout << "\nESTE SISTEMA DE ECUACIONES LINEALES ES COMPATIBLE INDETERMINADO\n";
            cout << "\nINFINITAS SOLUCIONES\n";
            cout << "\nDEBIDO A QUE LAS DIVISIONES SON 0/0\n";
        }else{
            //Si los determinantes son distintos de 0 entonces existen soluciones
            if (a.DetO != 0 && a.Var[0] != 0 && a.Var[1] != 0){
                cout << "\nRESULTADOS DE LAS INCOGNITAS\n";
                cout << "ICOGNITA 1: " << a.Var[0]/a.DetO;
                cout << "\nINCOGNITA 2: " << a.Var[1]/a.DetO;
                cout << "\n";
            }else{
                //Pero si el determinante original es igual a 0 y los otros determinantes no, entonces
                //Es incompatible
                if (a.DetO == 0 && a.Var[0] != 0 && a.Var[1] != 0){
                    cout << "\nEL SISTEMA DE ECUACIONES ES INDETERMINADO\n";
                    cout << "\nDEBIDO A QUE LAS DIVISIONES SON (Xnumero/0)\n";
                }
            }
        }
        
    //Aca se aplicaran las mismas condiciones, solo que con matrices extras !!!    
    }else{
        if (a.numF == 3 && a.numC == 3){
            
            if (a.DetO == 0 & a.Var[0] == 0 && a.Var[1] == 0 && a.Var[2] == 0){
                cout << "\nESTE SISTEMA DE ECUACIONES LINEALES ES COMPATIBLE INDETERMINADO\n";
                cout << "\nINFINITAS SOLUCIONES\n";
                cout << "\nDEBIDO A QUE LAS DIVISIONES SON 0/0\n";
            }else{
                if (a.DetO != 0 && a.Var[0] != 0 && a.Var[1] != 0 && a.Var[2] != 0){
                    cout << "\nRESULTADOS DE LAS INCOGNITAS\n";
                    cout << "ICOGNITA 1: " << a.Var[0]/a.DetO;
                    cout << "\nINCOGNITA 2: " << a.Var[1]/a.DetO;
                    cout <<"\nINCOGNITA 3: " << a.Var[2]/a.DetO;
                    cout << "\n";
                    
                }else{
                    if (a.DetO == 0 && a.Var[0] != 0 && a.Var[1] != 0 && a.Var[2] != 0){
                        cout << "\nEL SISTEMA DE ECUACIONES ES INDETERMINADO\n";
                        cout << "\nDEBIDO A QUE LAS DIVISIONES SON (Xnumero/0)\n";
                    }
                }
            }            
            
        }else{
            if (a.numF == 4 && a.numC == 4){
                
                if (a.DetO == 0 & a.Var[0] == 0 && a.Var[1] == 0 && a.Var[2] == 0 && a.Var[3] == 0){
                    cout << "\nESTE SISTEMA DE ECUACIONES LINEALES ES COMPATIBLE INDETERMINADO\n";
                    cout << "\nINFINITAS SOLUCIONES\n";
                    cout << "\nDEBIDO A QUE LAS DIVISIONES SON 0/0\n";
                }else{
                    if (a.DetO != 0 && a.Var[0] != 0 && a.Var[1] != 0 && a.Var[2] != 0 && a.Var[3] != 0){
                        cout << "\nRESULTADOS DE LAS INCOGNITAS\n";
                        cout << "ICOGNITA 1: " << a.Var[0]/a.DetO;
                        cout << "\nINCOGNITA 2: " << a.Var[1]/a.DetO;
                        cout <<"\nINCOGNITA 3: " << a.Var[2]/a.DetO;
                        cout <<"\nINCOGNITA 4: " << a.Var[3]/a.DetO;
                        cout << "\n";
                    
                    }else{
                        if (a.DetO == 0 && a.Var[0] != 0 && a.Var[1] != 0 && a.Var[2] != 0 && a.Var[3] != 0){
                            cout << "\nEL SISTEMA DE ECUACIONES ES INDETERMINADO\n";
                            cout << "\nDEBIDO A QUE LAS DIVISIONES SON (Xnumero/0)\n";
                        }
                    }
                }
                
            }
        }
    }
    
}

#endif /* MATRIZ_H */