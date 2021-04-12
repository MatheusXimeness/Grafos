#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    // ------ DECLARANDO VARIÁVEIS ----- //
        int numTest;             // número de casos teste
        int VERTICES, ARESTAS;   // número de VÉRTICES e número de ARESTAS
        int booleanoDaMatriz;    // irá setar os valores da matriz
    // ----- ----- //

    // ----- LEITURA ----- //    
        cin >> numTest; // lendo número de casos teste
        
        for( int i=0 ; i<numTest ;i++ ){
            cin >> VERTICES >> ARESTAS;
            vector<vector<bool>> MI(VERTICES, vector<bool>(ARESTAS, false)); // inicializando uma matriz de incidencia setada com false

            for( int j = 0 ; j < VERTICES ; j++ ){
                for( int k = 0 ; k < ARESTAS ; k++ ){
                    cin >> booleanoDaMatriz;

                    if(booleanoDaMatriz == 1){
                        MI[j][k] = true;
                    }
                }
            }
            // ----- CONFERINDO SE DADA A MATRIZ POSSO OBTER UM GRAFO SIMPLES NAO DIRECIONADO ----- //
                int contIguais = 0;  // conta a existencia de arestas diferentes incidindo em dois vertices
                int cont1emCol = 0;  // conta a quantidade de 1's nas colunas
                int contErrados = 0; // caso aconteça alguma falha registra o erro

                for ( int y = 0 ; y < ARESTAS  ; y++ ){
                    for(int z = 0 ; z < VERTICES ; z++){
                        if(MI[z][y] == true) cont1emCol++;
                    }
                    if(cont1emCol!=2) contErrados++;
                    cont1emCol = 0;
                }

                for( int x = 0 ; x < ARESTAS - 1 ; x++ ){
                    for ( int y = x + 1 ; y < ARESTAS  ; y++ ){
                        for(int z = 0 ; z < VERTICES ; z++){
                            if(MI[z][x] == MI[z][y] && MI[z][x] == true){
                                contIguais++;
                            }
                        }
                        if(contIguais >= 2){
                            contErrados++;
                        }
                        contIguais = 0;
                    }
                }
            
                if(contErrados>0) cout << "No" << "\n";
                else cout << "Yes" << "\n";
            // ----- ----- //    
        }
    // ----- ----- //
    

    return 0;
}