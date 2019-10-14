#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

int identificadorTipo(string tipo){
    int tokenTemp = 0;
    if(tipo == "enttok"){
        tokenTemp = 1;
    }
    if(tipo == "flotok"){
        tokenTemp = 2;
    }
    if(tipo == "cadtok"){
        tokenTemp = 3;
    }
    if(tipo == "cartok"){
        tokenTemp = 4;
    }
    if(tipo == "booltok"){
        tokenTemp = 5;
    }
    return tokenTemp;
}

bool validadorValorVariable(string lexema, int tokenTemp){
    bool valRet = false;
    if(tokenTemp == 1 && lexema == "NUM"){
        valRet = true;
    }
    if(tokenTemp == 2 && lexema == "DEC"){
        valRet = true;
    }
    if(tokenTemp == 3 && lexema == "PAL"){
        valRet = true;
    }
    if(tokenTemp == 4 && lexema == "LET"){
        valRet = true;
    }
    if(tokenTemp == 5 && lexema == "LOG"){
        valRet = true;
    }
    return valRet;
}

//Funcion que valida 
int validadorAsignacion(vector<string> VSin, int pos){
    //verifica si se ha ingresado un token de tipo dato
    int tokenTemp;
    if(VSin[pos] == TOKENST[1] || VSin[pos] == TOKENST[2] || VSin[pos] == TOKENST[3] || VSin[pos] == TOKENST[4] || VSin[pos] == TOKENST[5]){
        //avance de carro
        tokenTemp = identificadorTipo(VSin[pos]);
        cout<<"DECLARACION DE VARIABLE---------------------SINTACTICO\n";
        pos = pos+1;
        //verifica que acontinuacion cotenga un lexema adecuado para nombre de variable
        if(VSin[pos] == "VAR"){
            //avance de carro
            cout<<"NOMBRE DE VARIABLE ADECAUDA-----------------SINTACTICO\n";
             pos = pos+1;
            //verifica que acontinuacion contenga el simbolo asigando para asignacion
            if(VSin[pos] == ARITMT[6]){
                //avance de carro
                cout<<"SIMBOLO DE ASIGNACON CORRECTA---------------SINTACTICO\n";
                 pos = pos+1;
                //verifica si lo siguiente es un lexema adecuado segun el tipo de dato que se ha declarado
                if(validadorValorVariable(VSin[pos],tokenTemp)){
                    //avance de carro
                    cout<<"VALOR DE VARIABLE ADECUADA------------------SINTACTICO\n";
                     pos = pos+1;
                    //verifica que al final de la linea este el simbolo asignado para fin de linea
                    if(VSin[pos] == ESPT[11]){
                        //avance de carro
                        cout<<"SIMBOLO DE FIN DE LINEA CORRECTA------------SINTACTICO\n";
                    }else{
                        //se muere
                        cout<<"ERROR: se esperaba simbolo de fin de linea ';'\n";
                        exit(0);
                    }
                }else{
                    //se muere
                    cout<<"ERROR: valor no corresponde con tipo de dato\n";
                    exit(0);
                }
            }else{
                //se muere
                cout<<"ERROR: se esperaba simbolo de asignacion ':='\n"; 
                exit(0);
            }
        }else{
            //se muere
            cout<<"ERROR: se esperaba un nombre para la asginacion de la varible\n"; 
            exit(0);
        }
    }
    return pos;
}//validador asignacion