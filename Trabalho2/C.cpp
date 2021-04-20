#include<iostream>
#include<vector>
using namespace std;

void dfs(int R, int C, int i, int j, vector<vector<bool>> &visitadosPorJoe, vector<vector<char>> &Labirinto){
    if(visitadosPorJoe[i][j] == true) return;
    visitadosPorJoe[i][j] = true;
    if(i+1 < R){
        if(visitadosPorJoe[i+1][j] == false){
            Labirinto[i+1][j] = 'J';



        }
    }
    if(i-1 >= 0){}
        
    if(j+1 < C){}
        
    if(j-1 >= 0){}
    
}

void dfsFogo (int R, int C, int i, int j, vector<vector<pair<bool, int>>> &visitadosPorFogo, vector<vector<char>> &Labirinto){
    if(visitadosPorFogo[i][j].first == true) return;
    visitadosPorFogo[i][j].first = true;
    visitadosPorFogo[i][j].second++;
    
    if(i+1 < R){
        if(Labirinto[i+1][j] == '.' || Labirinto[i+1][j] == 'J'){
            visitadosPorFogo[i+1][j].second++;
            visitadosPorFogo[i+1][j].first = true;
            dfsFogo(R, C, i+1, j, visitadosPorFogo, Labirinto);
        }
    }

    if(i-1 >= 0){
        if(Labirinto[i-1][j] == '.' || Labirinto[i-1][j] == 'J'){
            visitadosPorFogo[i-1][j].second++;
            visitadosPorFogo[i-1][j].first = true;
            dfsFogo(R, C, i-1, j, visitadosPorFogo, Labirinto);
        }
    }
        
    if(j+1 < C){
        if(Labirinto[i][j+1] == '.' || Labirinto[i][j+1] == 'J'){
            visitadosPorFogo[i][j+1].second++;
            visitadosPorFogo[i][j+1].first = true;
            dfsFogo(R, C, i, j+1, visitadosPorFogo, Labirinto);
        }
    }
        
    if(j-1 >= 0){
        if(Labirinto[i][j-1] == '.' || Labirinto[i][j-1] == 'J'){
            visitadosPorFogo[i][j-1].second++;
            visitadosPorFogo[i][j-1].first = true;
            dfsFogo(R, C, i, j-1, visitadosPorFogo, Labirinto);
        }
    }
}

void solve(int R, int C){
    vector<vector<char>> Labirinto (R);
    vector<vector<pair<bool,int>>> visitadosPorJoe(R, vector<pair<bool,int>> (C));
    vector<vector<pair<bool,int>>> visitadosPorFogo(R, vector<pair<bool,int>> (C));
    
    char st;

    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cin >> st;
            Labirinto[i].push_back(st);
        }
    }

    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            visitadosPorFogo[i][j].first = false;
            if(Labirinto[i][j] == 'F'){
                visitadosPorFogo[i][j].second = 0;
                dfsFogo(R, C, i, j, visitadosPorFogo, Labirinto);
            }
        }
    }
    
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cout << visitadosPorFogo[i][j].second;
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