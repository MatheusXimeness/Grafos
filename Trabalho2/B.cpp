#include<iostream>
#include<vector>
using namespace std;

void dfs(int R, int C, int i, int j, vector<vector<bool>> &visitados, vector<vector<char>> &Fazenda){
    if(visitados[i][j] == true ) return;
    
    visitados[i][j] = true;
    
    if(i+1 < R)
        if(Fazenda[i+1][j] == 'S') Fazenda[i][j] = 'D'; 
    if(i-1 >= 0)
        if(Fazenda[i-1][j] == 'S') Fazenda[i][j] = 'D';
    if(j+1 < C)
        if(Fazenda[i][j+1] == 'S') Fazenda[i][j] = 'D';
    if(j-1 >= 0)
        if(Fazenda[i][j-1] == 'S') Fazenda[i][j] = 'D';

    if(i+1 < R && Fazenda[i+1][j] != 'D' && Fazenda[i+1][j] != 'S' )
        dfs(R, C, i+1, j, visitados, Fazenda);
    if(i-1 >= 0 && Fazenda[i-1][j] != 'D' && Fazenda[i-1][j] != 'S')
        dfs(R, C, i-1, j, visitados, Fazenda);
    if(j+1 < C && Fazenda[i][j+1] != 'D' && Fazenda[i][j+1] != 'S')
        dfs(R, C, i, j+1, visitados, Fazenda);
    if(j-1 >= 0 && Fazenda[i][j-1] != 'D' && Fazenda[i][j-1] != 'S')
        dfs(R, C, i, j-1, visitados, Fazenda);
}

int main(){
    int R, C; cin >> R >> C;          // linhas e colunas
    vector<vector<char>> Fazenda (R); // matriz que representa a fazenda
    char st;                          // variável que auxilia a leitura (temporária)

    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cin >> st;
            Fazenda[i].push_back(st);
        }
    }
    vector<vector<bool>> visitados(R, vector<bool> (C, false));
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            if(Fazenda[i][j] == 'W'){
                dfs(R, C, i, j, visitados, Fazenda);
            }
        }    
    }
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cout << Fazenda[i][j];
        }
        cout << endl;
    }
    return 0;
}