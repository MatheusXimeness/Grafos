#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfsFogo(int R, int C, vector<vector<char>> &Labirinto, vector<vector<int>> &visitadosPorFogo){
    
    queue<pair<int, int>> fila;
    pair<int,int> coordenadas;

    for( int i = 0 ; i < R ; i++ ) {
        for ( int j = 0 ; j < C ; j++ ) {
            visitadosPorFogo[i][j] = 0;
            if ( Labirinto[i][j] == 'F' ) {
                coordenadas = make_pair (i,j);
                fila.push( coordenadas );
            }
        }
    }
    
   
    pair<int,int> vertice;
    
    while( !fila.empty() ){
        vertice.first  = fila.front().first; 
        vertice.second = fila.front().second; 
        fila.pop( ); 

        //visitaVertice() não sei se é necessário
        // ----- Para todos os vizinhos ----- //    
            if( vertice.first+1 < R ) {
                if( visitadosPorFogo[ vertice.first+1 ][ vertice.second ] == 0 ) {
                    if( Labirinto[ vertice.first+1 ][ vertice.second ] == '.' || Labirinto[ vertice.first+1 ][ vertice.second ]  == 'J' ) {
                        visitadosPorFogo[ vertice.first+1 ][ vertice.second ]++;

                        fila.push( make_pair( vertice.first+1 , vertice.second ) );
                        cout << "i: " << vertice.first+1  << " j: " << vertice.second << endl;
                    }
                } else { //caso seja maior que 0
                    if ( visitadosPorFogo[ vertice.first ][ vertice.second ] < visitadosPorFogo[ vertice.first+1 ][ vertice.second ] )
                        visitadosPorFogo[ vertice.first ][ vertice.second ]++;
                    cout << "oi4" << endl;
                }
            }
            if( vertice.first-1 < R ) {
                if( visitadosPorFogo[ vertice.first-1 ][ vertice.second ] == 0 ) {
                    if( Labirinto[ vertice.first-1 ][ vertice.second ] == '.' || Labirinto[ vertice.first-1 ][ vertice.second ] == 'J' ) {
                        visitadosPorFogo[ vertice.first-1 ][ vertice.second ]++;

                        fila.push( make_pair( vertice.first-1 , vertice.second ) );
                        cout << "i: " << vertice.first+-1  << " j: " << vertice.second << endl;
                    }
                } else { //caso seja maior que 0
                     if ( visitadosPorFogo[ vertice.first ][ vertice.second ] < visitadosPorFogo[ vertice.first-1 ][ vertice.second ] ){
                        visitadosPorFogo[ vertice.first ][ vertice.second ]++;
                     }

                    cout << "ooooi3" << endl;
                }
            }
            if( vertice.second+1 < C ) {
                if( visitadosPorFogo[ vertice.first  ][ vertice.second+1 ] == 0 ) {
                    if( Labirinto[ vertice.first  ][ vertice.second+1 ] == '.' || Labirinto[ vertice.first ][ vertice.second+1 ] == 'J' ) {
                        visitadosPorFogo[ vertice.first  ][ vertice.second+1 ]++;

                        fila.push( make_pair( vertice.first  , vertice.second+1 ) );
                        cout << "i: " << vertice.first  << " j: " << vertice.second+1 << endl;

                    }
                } else  if ( visitadosPorFogo[ vertice.first ][ vertice.second ] < visitadosPorFogo[ vertice.first ][ vertice.second+1 ] ){ //caso seja maior que 0
                    visitadosPorFogo[ vertice.first ][ vertice.second ]++;

                    cout << "ooooi2" << endl;
                }
            }
            if( vertice.second-1 < C ) {
                if( visitadosPorFogo[ vertice.first ][ vertice.second-1 ] == 0 ) {
                    if( Labirinto[ vertice.first  ][ vertice.second-1 ] == '.' || Labirinto[ vertice.first  ][ vertice.second-1 ] == 'J' ) {
                        visitadosPorFogo[ vertice.first  ][ vertice.second-1 ]++;

                        fila.push( make_pair( vertice.first  , vertice.second-1 ) );
                        cout << "i: " << vertice.first << " j: " << vertice.second-1 << endl;

                    }
                } else if ( visitadosPorFogo[ vertice.first ][ vertice.second ] < visitadosPorFogo[ vertice.first ][ vertice.second-1 ] ){ //caso seja maior que 0
                    visitadosPorFogo[ vertice.first ][ vertice.second ]++;

                    cout << "ooooi1" << endl;
                }
            }
        // ----- ------ //    
    }
}

/*void bfsFogo (int R, int C, int i, int j, vector<vector<pair<bool, int>>> &visitadosPorFogo, vector<vector<char>> &Labirinto){
    if(visitadosPorFogo[i][j].first == true) return;
    visitadosPorFogo[i][j].first = true;
    visitadosPorFogo[i][j].second++;
    
    if(i+1 < R){
        if(Labirinto[i+1][j] == '.' || Labirinto[i+1][j] == 'J'){
            visitadosPorFogo[i+1][j].second++;
            visitadosPorFogo[i+1][j].first = true;
            Labirinto[i+1][j] = 'F';
            dfsFogo(R, C, i+1, j, visitadosPorFogo, Labirinto);
        }
    }

    if(i-1 >= 0){
        if(Labirinto[i-1][j] == '.' || Labirinto[i-1][j] == 'J'){
            visitadosPorFogo[i-1][j].second++;
            visitadosPorFogo[i-1][j].first = true;
            Labirinto[i-1][j] = 'F';
            dfsFogo(R, C, i-1, j, visitadosPorFogo, Labirinto);
        }
    }
        
    if(j+1 < C){
        if(Labirinto[i][j+1] == '.' || Labirinto[i][j+1] == 'J'){
            visitadosPorFogo[i][j+1].second++;
            visitadosPorFogo[i][j+1].first = true;
            Labirinto[i][j+1] = 'F';
            dfsFogo(R, C, i, j+1, visitadosPorFogo, Labirinto);
        }
    }
        
    if(j-1 >= 0){
        if(Labirinto[i][j-1] == '.' || Labirinto[i][j-1] == 'J'){
            visitadosPorFogo[i][j-1].second++;
            visitadosPorFogo[i][j-1].first = true;
            Labirinto[i][j-1] = 'F';
            dfsFogo(R, C, i, j-1, visitadosPorFogo, Labirinto);
        }
    }
}*/

void solve(int R, int C){
    vector<vector<char>> Labirinto (R);
    vector<vector<int>> visitadosPorJoe (R, vector<int> (C)); // confere com != 0
    vector<vector<int>> visitadosPorFogo(R, vector<int> (C));
    
    char st;

    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0; j < C ; j++ ) {
            cin >> st;
            Labirinto[i].push_back(st);
        }
    }


    bfsFogo( R, C, Labirinto, visitadosPorFogo );
        
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cout << visitadosPorFogo[i][j];
        }    
        cout << endl;
    }
    /*
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            if(Labirinto[i][j] == 'F')
                dfs(R, C, i, j, visitados, Labirinto);
        }
    }*/

}

int main(){
    int nTeste; cin >> nTeste;
    int R, C;
    for(int i = 0 ; i < nTeste ; i++){
        cin >> R >> C;
        solve(R, C);
    }

    return 0;
}