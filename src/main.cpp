#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
//archivos necesarios
#include "headers/CodeReader.h"
#include "headers/analizador_lexicografico/lexicoGrafico.h"
#include "headers/AnalizadorSintactico.h"

using namespace std;

int main (void){

  //generar el vector con los strings de cada palabra para ser analizados
  vector<string> algo,algoAnalizado;
  algo = CodeReader("./data/code.txt");
  algoAnalizado = AnalizadorLexicoGrafico(algo);
  //for de prueba borrar todo esto
  cout<<"ALGO ANALIZADO \n";
  for(int i =0; i< algoAnalizado.size(); i++){
    cout<<algoAnalizado[i]<<"\n";
  }//for de prueba borrar
  AnalizadorSintactico(algoAnalizado);
  return 0;
}//main

/*   esto es mas para el sintactico
      //funcion en manejador que obtiene el token correspondiente  
      tokenTemp = obtenerTokens(algo,i);
      //funcion que avanza el carro una posicion y se encarga de validar variables
      i = bloque(algo,tokenTemp,i);
      }//if
    else{
    cout<<algo[i]<<"\n";
    }//else*/
