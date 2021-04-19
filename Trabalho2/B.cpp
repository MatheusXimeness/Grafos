#include<iostream>
#include<vector>
using namespace std;


bool cacadaSangrenta (int R, int C, int i, int j, vector<vector<char>> &Fazenda){
    if(i+1 < R)
        if(Fazenda[i+1][j] == 'S') return true; 
    if(i-1 >= 0)
        if(Fazenda[i-1][j] == 'S') return true;
    if(j+1 < C)
        if(Fazenda[i][j+1] == 'S') return true;
    if(j-1 >= 0)
        if(Fazenda[i][j-1] == 'S') return true;
    return false;
}

void dfs(int R, int C, int i, int j, vector<vector<bool>> &visitados, vector<vector<char>> &Fazenda){
    // se já visitou ou está visitando uma ovelha
    if(visitados[i][j] == true || Fazenda[i][j] == 'S') return; 
    
    // marca como visitada a célula atual
    visitados[i][j] = true;
    
    // ----- colocando cachorros ----- //
        if(i+1 < R)
            if(Fazenda[i+1][j] == 'S') Fazenda[i][j] = 'D'; 
        if(i-1 >= 0)
            if(Fazenda[i-1][j] == 'S') Fazenda[i][j] = 'D';
        if(j+1 < C)
            if(Fazenda[i][j+1] == 'S') Fazenda[i][j] = 'D';
        if(j-1 >= 0)
            if(Fazenda[i][j-1] == 'S') Fazenda[i][j] = 'D';
    // -----  ----- //

    // ----- Procurando novas ovelhas ----- //
        if(i+1 < R && Fazenda[i+1][j] != 'D' && Fazenda[i+1][j] != 'W')
            dfs(R, C, i+1, j, visitados, Fazenda);
        if(i-1 >= 0 && Fazenda[i-1][j] != 'D' && Fazenda[i-1][j] != 'W')
            dfs(R, C, i-1, j, visitados, Fazenda);
        if(j+1 < C && Fazenda[i][j+1] != 'D' && Fazenda[i][j+1] != 'W')
            dfs(R, C, i, j+1, visitados, Fazenda);
        if(j-1 >= 0 && Fazenda[i][j-1] != 'D' && Fazenda[i][j-1] != 'W')
            dfs(R, C, i, j-1, visitados, Fazenda);
    // -----  ----- //
}

int main(){

    // ----- declarando variáveis ----- //
        int R, C; cin >> R >> C;                                    // linhas e colunas
        vector<vector<char>> Fazenda (R);                           // matriz que representa a fazenda
        char st;                                                    // variável que auxilia a leitura (temporária)
        vector<vector<bool>> visitados(R, vector<bool> (C, false)); // matriz que faz com que o lobo não visite duas células iguais
    // -----  ----- //

    // ----- leitura ----- //
        for(int i = 0 ; i < R ; i++){
            for(int j = 0; j < C ; j++){
                cin >> st;
                Fazenda[i].push_back(st);
            }
        }
    // -----  ----- //
    

    // ----- descobrindo se é impossível ----- //
        for(int i = 0 ; i < R ; i++){
            for(int j = 0; j < C ; j++){
                if( Fazenda[i][j] == 'W' && cacadaSangrenta(R, C, i, j, Fazenda) ) {
                    cout << "No" << endl;
                    return 0;           
                }
            }   
        }
    // ----- ----- //
    
    // ----- descobrindo qual a possibilidade de proteger todas ----- //
        for(int i = 0 ; i < R ; i++){
            for(int j = 0; j < C ; j++){
                if(Fazenda[i][j] == 'W')
                    dfs(R, C, i, j, visitados, Fazenda);
            }
        }
        cout << "Yes" << endl;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0; j < C ; j++){
                cout << Fazenda[i][j];
            }
            if( i !=R )
                cout << endl;
        }
    // -----  ----- //
    return 0;

}