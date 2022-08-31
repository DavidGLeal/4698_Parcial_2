/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	      Juan Reyes
        Brandon Masacela
        GRUPO: 3
  FECHA DE CREACION:        Miércoles, 14 de agosto de 2022 5:00 p.m. 	
  FECHA DE MODIFICACION:    Miércoles, 14 de agosto de 2022 9:15 a.m.
 * --------------------------
 * Planteamiento: Resolver el Problema de Cambio de Monedas
 * --------------------------
 * Este programa implementa una solución al problema del cambio de 
 * monedas.
 */
 
 #include "Cambio.h"
 
 void Cambio::funcionamiento(){
	cout << "Ingrese el valor a otorgar el cambios: "; cin >> total;   

    sort(values.begin(), values.end()); 

    vector<vector<vector<int>>> empty(total+1); 
    vector<vector<vector<int>>> lastRow(total+1);
    vector<vector<vector<int>>> curRow(total+1);

    for(int i=0; i<values.size(); i++) {
        for(int curSum=0; curSum<=total; curSum++){
            if(curSum==0) {       
				   
                curRow[curSum].push_back(vector<int> {}); 
                
            }else if(i==0) {
				
            }else if(values[i]>curSum){
				
                curRow[curSum] = lastRow[curSum];
                
            }else{
                curRow[curSum] = lastRow[curSum];
                vector<vector<int>> useCurCoin = curRow[curSum-values[i]];
                
                for(int k=0; k<useCurCoin.size(); k++){
                    useCurCoin[k].push_back(values[i]);
                    curRow[curSum].push_back(useCurCoin[k]);
                }               
            }    
        }        

        lastRow = curRow;
        curRow = empty;
    } 

    cout<<"Total number of combinations: "<<lastRow.back().size()<<endl;
    for (int i=0; i<lastRow.back().size(); i++) {
        for (int j=0; j<lastRow.back()[i].size(); j++) {
            if(j!=0)
                cout << " ";
            cout << lastRow.back()[i][j];
        }
        cout<<endl;
    }
}
 
