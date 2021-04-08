#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    // ------ DECLARANDO VARIÁVEIS ----- //
        int numTest;             // número de casos teste
        int VERTICES, ARESTAS;   // número de VÉRTICES e número de ARESTAS
        vector<vector<bool>> MI; // matriz de incidência
        int booleanoDaMatriz;    // irá setar os valores da matriz
    // ----- ----- //

    // ----- LEITURA ----- //    
        cin >> numTest; // lendo número de casos teste
        
        for( int i=0 ; i<numTest ;i++ ){
            cin >> VERTICES >> ARESTAS;

            for( int j = 0 ; j < VERTICES ; j++ ){
                for( int k = 0 ; k < ARESTAS ; k++ ){
                    cin >> booleanoDaMatriz;
                    if(booleanoDaMatriz == 1){
                        MI[i].push_back(true);
                    } else {
                        MI[i].push_back(false);   
                    }     
                }
            }
            // ----- CONFERINDO SE DADA A MATRIZ POSSO OBTER UM GRAFO SIMPLES NAO DIRECIONADO ----- //
                int contTrueInLines = 0;
                
                for( int i = 0 ; i < VERTICES ; i++ ){
                    for ( int j = 0 ; j < ARESTAS ; j++ ){
                        if(MI[i][j] == true) contTrueInLines++;
                    }
                    if(contTrueInLines < ARESTAS - 1) {
                        contTrueInLines = 0;
                    } else { 
                        cout << "No" << endl;
                        break;
                    }
                }
                cout << "Yes" << endl;  
            // ----- ----- //    
        }
    // ----- ----- //
    

    return 0;
}