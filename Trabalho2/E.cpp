#include<iostream>
#include<vector>
using namespace std;

bool dfsBipartido ( vector<vector<int>> const &lista, int vertice, vector<int> &cor, int corVertice ) {
    if(cor[vertice] != -1){
        if(cor[vertice] != corVertice )
            return false;
        else 
            return true;
    }
    cor[vertice] = corVertice;

    auto i = lista.at(vertice);
    for(auto const & j:i){
        int outraCor = 1 - corVertice;
        bool resposta = dfsBipartido (lista, j, cor, outraCor);
        if(!resposta) return false;
    }

    return true;
}


int solve ( int vertices, vector<vector<int>> const &lista ) {

    vector<int> Cor(vertices, -1);

    for ( int i=0; i<vertices ;i++ ){
        if (Cor[i] != -1) continue;
        
        if( !dfsBipartido ( lista, i, Cor, 0 ) ){

            cout << "NO" << endl;
            return 0;
        } 
    }

    cout << "YES" << endl;
    return 0;
}

int main () {
    
    bool isReading = true;
    while ( isReading ){
        int vertices; cin >> vertices;

        if ( vertices == 0  ){ // se chegou no final da leitura
             break; 
        }
 
        vector<vector<int>> lista (vertices);

        int e1, e2;
        while(true){
            cin >> e1 >> e2;

            if ( e1 == 0 && e2 == 0 ) {
                solve (vertices, lista);
                break;
            }
            lista[e1-1].push_back(e2-1);
            lista[e2-1].push_back(e1-1);
        }
    }

    return 0;
}