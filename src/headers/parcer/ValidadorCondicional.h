#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Archivos Necesarios

//Fucion que valida
int validadorCondicional(vector<string> VSin, int pos){
  int posTemp,posTempAux;
    if(VSin[pos] == TOKENST[6] || VSin[pos] == TOKENST[7]){
        //todo bien 
        cout<<"DECLARACION DE CONDICIONAL------------------SINTACTICO\n";
        posTemp = est.conversion(pos);//<---aca agarro la posicion real de la linea
        pos = pos+1;
        if(VSin[pos] == ESPT[7]){
        //todobien
        cout<<"PARENTESIS QUE INDICA INICIO DE CONDICION---SINTACTICO\n";
        pos = pos+1;
            if(VSin[pos] == "VAR"){
                //todo bien
                cout<<"LLAMADA A UNA VARIABLE CORRECTA-------------SINTACTICO\n";
                pos = pos+1;
                if(VSin[pos] == ESPT[4] || VSin[pos] == ESPT[5] || VSin[pos] == ESPT[6]){
                    //todo bien
                    cout<<"SIMBOLO DE COMPARACION----------------------SINTACTICO\n";
                    pos = pos+1;
                    if(VSin[pos] == "VAR"){
                       //todo bien
                       cout<<"LLAMADA A UNA VARIABLE CORRECTA-------------SINTACTICO\n";
                       pos = pos+1;
                       if(VSin[pos] == ESPT[8]){
                        //todobien
                        cout<<"PARENTESIS QUE INDICA FIN DE CONDICION------SINTACTICO\n";
                        pos = pos+1;
                            if(VSin[pos] == ESPT[0]){
                                //todobien
                                cout<<"CORCHETE  QUE INDICA INICIO DE CODIGO-------SINTACTICO\n";
                                pos = pos+1;
                                posTempAux = posTemp; 
                                while(VSin[pos] != ESPT[1] && pos != VSin.size()-1){
                                    cout<<"CODIGO DENTRO DE CONDICIONAL----------------SINTACTICO\n";   
                                    pos = pos+1;                                  
                                }
                                if(pos != VSin.size()-1){
                                    cout<<"CORCHETE QUE INDICA FIN DE CODIGO-----------SINTACTICO\n";
                                }else{
                                    cout<<"En linea: "<<est.VectorLineas[posTempAux]<<" "<<ERRORES[25];
                                }
                            }else{
                            //se muere
                            //cout<<ERRORES[2];
                            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[2];
                            exit(0);
                            }
                        }else{
                        //se muere
                        //cout<<ERRORES[3];
                        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[3];
                        exit(0);
                        }
                    }else{
                    //se muere
                    //cout<<ERRORES[4];
                    cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[4];
                    exit(0);
                    }
                }else{
                //se muere
                //cout<<ERRORES[5];
                cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[5];
                exit(0);
                }
            }else{
            //se muere
            //cout<<ERRORES[4];
            cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[4];
            exit(0);
            }
        }else{
        //se muere
        //cout<<ERRORES[6];
        cout<<"En linea: "<<est.VectorLineas[posTemp]<<" "<<ERRORES[6];
        exit(0);
        }
    }
    return pos;
}//validador condicional
