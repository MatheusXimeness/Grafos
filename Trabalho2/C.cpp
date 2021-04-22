#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfsFogo( vector<pair<int,int>> posFogo, int R, int C, vector<vector<char>> &Labirinto, vector<vector<int>> &visitadosPorFogo){
    
    queue<pair<int, int>> fila;
    pair<int,int> coordenadas;

    for( int i = 0 ; i < posFogo.size() ; i++ ){
        fila.push(posFogo[i]);
    }
    
   // -----  Vertice auxiliar ----- //
    pair<int,int> vertice;
    
    while( !fila.empty() ){
        vertice.first  = fila.front().first; 
        vertice.second = fila.front().second; 
        fila.pop( ); 

        //visitaVertice() não sei se é necessário 
        // ----- Para todos os vizinhos ----- //    
            if( vertice.first+1 < R ) {
                if( visitadosPorFogo[ vertice.first+1 ][ vertice.second ] == 0 && Labirinto[ vertice.first+1 ][ vertice.second ] != '#' ) {  // se tiver tempo 0 e não for parede
                    if( Labirinto[ vertice.first+1 ][ vertice.second ] == '.' || Labirinto[ vertice.first+1 ][ vertice.second ]  == 'J' ) {  // se for igual a espaço vazio ou igual a joão
                        if ( visitadosPorFogo[ vertice.first ][ vertice.second ] >= visitadosPorFogo[ vertice.first+1 ][ vertice.second ] ){ // se a posição que o fogo está for maior que a posição que eu desejo entrar, se for menor não precisa 
                            visitadosPorFogo[ vertice.first+1 ][ vertice.second ] = visitadosPorFogo[ vertice.first ][ vertice.second ] + 1; // então eu somo o que eu tinha com mais um

                            fila.push( make_pair( vertice.first+1 , vertice.second ) ); // add na fila, pois ainda não foi visitado
                        }
                    }
                } 
            }
            if( vertice.first-1 >= 0 ) {
                if( visitadosPorFogo[ vertice.first-1 ][ vertice.second ] == 0 ) {
                    if( Labirinto[ vertice.first-1 ][ vertice.second ] == '.' || Labirinto[ vertice.first-1 ][ vertice.second ] == 'J' ) {
                        if ( visitadosPorFogo[ vertice.first ][ vertice.second ] >= visitadosPorFogo[ vertice.first-1 ][ vertice.second ] ){
                            visitadosPorFogo[ vertice.first-1 ][ vertice.second ] = visitadosPorFogo[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first-1 , vertice.second ) );
                        }
                    }
                } 
            }
            if( vertice.second+1 < C ) {
                if( visitadosPorFogo[ vertice.first  ][ vertice.second+1 ] == 0 ) {
                    if( Labirinto[ vertice.first  ][ vertice.second+1 ] == '.' || Labirinto[ vertice.first ][ vertice.second+1 ] == 'J' ) {
                        if ( visitadosPorFogo[ vertice.first ][ vertice.second ] >= visitadosPorFogo[ vertice.first ][ vertice.second+1 ] ) {
                            visitadosPorFogo[ vertice.first ][ vertice.second+1 ] = visitadosPorFogo[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first  , vertice.second+1 ) );
                        }
                    }
                } 
            }
            if( vertice.second-1 >= 0 ) {
                if( visitadosPorFogo[ vertice.first ][ vertice.second-1 ] == 0 ) {
                    if( Labirinto[ vertice.first  ][ vertice.second-1 ] == '.' || Labirinto[ vertice.first  ][ vertice.second-1 ] == 'J' ) {
                        if ( visitadosPorFogo[ vertice.first ][ vertice.second ] >= visitadosPorFogo[ vertice.first ][ vertice.second-1 ] ) {    
                            visitadosPorFogo[ vertice.first ][ vertice.second-1 ] = visitadosPorFogo[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first  , vertice.second-1 ) );
                        }
                    }
                } 
            }
        // ----- ------ //    
    }
}

int bfsJoe(int posJoeI, int posJoeJ, int R, int C, vector<vector<char>> &Labirinto, vector<vector<int>> &visitadosPorJoe, vector<vector<int>> &visitadosPorFogo, vector<vector<bool>> &visitados ){
    
    queue<pair<int, int>> fila;
    pair<int,int> coordenadas;

    coordenadas = make_pair (posJoeI, posJoeJ);
    fila.push( coordenadas );
      

   // -----  Vertice auxiliar ----- //
    pair<int,int> vertice;
    
    while( !fila.empty() ){
        vertice.first  = fila.front().first; 
        vertice.second = fila.front().second; 
        fila.pop( ); 

        //visitaVertice() não sei se é necessário
        // ----- Para todos os vizinhos ----- //    
            if( vertice.first+1 < R ) {
                if( visitadosPorJoe[ vertice.first+1 ][ vertice.second ] == 0 && Labirinto[ vertice.first+1 ][ vertice.second ] != '#' ) {  // se tiver tempo 0 e não for parede
                    if( Labirinto[ vertice.first+1 ][ vertice.second ] == '.' && Labirinto[ vertice.first+1 ][ vertice.second ]  != 'F' ) {  // se for igual a espaço vazio e diferente de fogo
                        if ( visitadosPorJoe[ vertice.first ][ vertice.second ] >= visitadosPorJoe[ vertice.first+1 ][ vertice.second ] ){ // se a posição que o Joe está for maior que a posição que eu desejo entrar, se for menor não precisa 
                            visitadosPorJoe[ vertice.first+1 ][ vertice.second ] = visitadosPorJoe[ vertice.first ][ vertice.second ] + 1; // então eu somo o que eu tinha com mais um

                            fila.push( make_pair( vertice.first+1 , vertice.second ) ); // add na fila, pois ainda não foi visitado
                        }
                    }
                    // ------------- Junção ------------ //
                    if( visitadosPorJoe[ vertice.first+1 ][ vertice.second ] < visitadosPorFogo[ vertice.first+1 ][ vertice.second ] ) {  // se o tempo do Joe for menor que o fogo e diferente de parede
                        if( vertice.first+1 == R-1 ) {  // se pude chegar no limite
                            return visitadosPorJoe[ vertice.first+1 ][ vertice.second ] +1;   
                        } 
                    } 
                // -------------  -------------- //
                }
            }

            if( vertice.first-1 >= 0 ) {
                if( visitadosPorJoe[ vertice.first-1 ][ vertice.second ] == 0 && Labirinto[ vertice.first-1 ][ vertice.second ] != '#') {
                    if( Labirinto[ vertice.first-1 ][ vertice.second ] == '.' && Labirinto[ vertice.first-1 ][ vertice.second ] != 'F' ) {
                        if ( visitadosPorJoe[ vertice.first ][ vertice.second ] >= visitadosPorJoe[ vertice.first-1 ][ vertice.second ] ){
                            visitadosPorJoe[ vertice.first-1 ][ vertice.second ] = visitadosPorJoe[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first-1 , vertice.second ) );
                        }
                    }
                     // ------------- Junção ------------ //

                    if( visitadosPorJoe[ vertice.first-1 ][ vertice.second ] < visitadosPorFogo[ vertice.first-1 ][ vertice.second ] ) {  // se o tempo do Joe for menor que o fogo e diferente de parede
                        if( vertice.first-1 == 0 ) {  // se pude chegar no limite
                            return visitadosPorJoe[ vertice.first-1 ][ vertice.second ] +1;   
                        } 
                    }
                // -------------  -------------- // 
                }

            }
            if( vertice.second+1 < C ) {
                if( visitadosPorJoe[ vertice.first  ][ vertice.second+1 ] == 0 && Labirinto[ vertice.first ][ vertice.second+1 ] != '#') {
                    if( Labirinto[ vertice.first  ][ vertice.second+1 ] == '.' && Labirinto[ vertice.first ][ vertice.second+1 ] != 'F' ) {
                        if ( visitadosPorJoe[ vertice.first ][ vertice.second ] >= visitadosPorJoe[ vertice.first ][ vertice.second+1 ] ) {
                            visitadosPorJoe[ vertice.first ][ vertice.second+1 ] = visitadosPorJoe[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first  , vertice.second+1 ) );
                        }
                    }
                    // ------------- Junção ------------ //

                    if( visitadosPorJoe[ vertice.first ][ vertice.second+1 ] < visitadosPorFogo[ vertice.first ][ vertice.second+1 ] ) {  // se o tempo do Joe for menor que o fogo e diferente de parede                       
                        if( vertice.second+1 == C-1 ) {  // se pude chegar no limite                          
                            return visitadosPorJoe[ vertice.first ][ vertice.second+1 ] +1;   
                        } 
                    }
                // -------------  -------------- // 
                }
                
            }
            if( vertice.second-1 >= 0 ) {
                if( visitadosPorJoe[ vertice.first ][ vertice.second-1 ] == 0 && Labirinto[ vertice.first ][ vertice.second-1 ] != '#') {
                    if( Labirinto[ vertice.first  ][ vertice.second-1 ] == '.' && Labirinto[ vertice.first  ][ vertice.second-1 ] != 'F' ) {
                        if ( visitadosPorJoe[ vertice.first ][ vertice.second ] >= visitadosPorJoe[ vertice.first ][ vertice.second-1 ] ) {    
                            visitadosPorJoe[ vertice.first ][ vertice.second-1 ] = visitadosPorJoe[ vertice.first ][ vertice.second ] + 1;

                            fila.push( make_pair( vertice.first  , vertice.second-1 ) );
                        }
                    }
                     // ------------- Junção ------------ //

                    if( visitadosPorJoe[ vertice.first ][ vertice.second-1 ] < visitadosPorFogo[ vertice.first ][ vertice.second-1 ] ) {  // se o tempo do Joe for menor que o fogo e diferente de parede                      
                        if( vertice.second-1 == 0) {  // se pude chegar no limite
                            return visitadosPorJoe[ vertice.first ][ vertice.second-1 ] +1;   
                        }
                    }
                
                // -------------  -------------- //
                }              
            }
        // ----- ------ //    
    }
    return 0;
}


void solve(int R, int C){

    vector<vector<char>> Labirinto (R);
    vector<vector<int>> visitadosPorJoe (R, vector<int> (C)); // confere com != 0
    vector<vector<int>> visitadosPorFogo(R, vector<int> (C));
    vector<vector<bool>> visitados(R, vector<bool> (C, false));
    
    char st;
    pair<int,int> posJoe;
    pair<int,int> coordenadas;
    vector<pair<int,int>> posFogo;

    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0; j < C ; j++ ) {
            cin >> st;
            Labirinto[i].push_back(st);

            visitadosPorJoe[i][j] = 0;
            visitadosPorFogo[i][j] = 0;

            if(Labirinto[i][j] ==  'J'){
                posJoe.first = i;
                posJoe.second = j;
            }

            if(Labirinto[i][j] == 'F'){
                coordenadas = make_pair (i,j);
                posFogo.push_back( coordenadas );
            }
        }
    }

    // ----- Retorna uma matriz com os momentos em que cada um acessou a célula ----- //
        bfsFogo( posFogo, R, C, Labirinto, visitadosPorFogo );
        int resposta = bfsJoe ( posJoe.first, posJoe.second, R, C, Labirinto, visitadosPorJoe, visitadosPorFogo, visitados );
    // ----- ----- //

    // ----- Teste para ver se os tempos foram inseridos corretamente ----- //    
        /*for(int i = 0 ; i < R ; i++){
            for(int j = 0; j < C ; j++){
                cout << visitadosPorFogo[i][j]; || cout << visitadosPorJoe[i][j]; 
            }    
            cout << endl;
        }*/
    // ----- ----- //

    
    //int resposta = bfsComparaMomentos( posJoe.first, posJoe.second, R, C, visitadosPorJoe, visitadosPorFogo, visitados, Labirinto );
    if( resposta > 0 ) {
        cout << resposta << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

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