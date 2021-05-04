#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

calculaProxJogo (){
    /*
        salva estado inicial - salva aux
        h1 h2 h3 v1 v2 v3 -> cada aux vai ser diferente (permuta)
        condição (!se ja esta no map nao coloca mais)
        coloca na pilha e coloca no map
        salvar o numero do mov e mov 
        passos+h1...
    */
}

void bfs(map<string, string> &map) {
    map["123456789"] = "";
    queue<string> fila;
    fila.push("123456789");
    while ( !fila.empty() ) {
        string aux = fila.front();
        fila.pop();
        calculaProxJogo(map, fila, aux)
    }
}

void solve (map<string, string> &map, string jogo){
    if ( map.find(jogo) != map.end() )
        cout << map[jogo].length() / 2 << map[jogo] << endl;
    else  
        cout << "Not solvable" << endl;
}

int main() {
    map<string, string> map;
    queue<pair<string, string>> fila;
    string entrada, jogo;
    //chama bfs
    while(true) {
        getline(cin,entrada);
        if(entrada[0] == 0) break;
        jogo += entrada[0] + entrada[2] + entrada[4];
        if ( jogo.length() == 9 ) {
            solve(map, jogo);
            entrada =  "";
        }
    }
    return 0;
}