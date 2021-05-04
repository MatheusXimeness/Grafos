#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool eh_primo(int n){
	if(n==1)
		return true;
	int cont=0;
	for( int i = 1 ; i <= n ; i++ ){
		if(n%i==0) 
			cont++;
	}
	if(cont>2 && n!=1)
		return false;
	if(cont==2)
		return true;
}

void calculaFatoresPrimos( int s, vector<vector<int>> &fatoresPrimos, vector<int> &visitados, int multi )
{
    for( int i = 2 ; i < s ; i++ ){
        if( eh_primo(i)  && s%i == 0) {
            if ( multi*i <= s){
                multi = multi * i;
                fatoresPrimos[s].push_back(i);
            }
        }
    }
    return;
}

int calculaNumeroTransformacoes( vector<vector<int>> &fatoresPrimos, vector<int> &visitadosFila, int s, int t )
{
    //if (visitadosFila[s] != 0) return visitadosFila[s];
    visitadosFila[s] = 1;
    queue<int> fila;
    fila.push(s);
    int auxFila;
    int auxFatoracao = s;
    while( !fila.empty() ) {
        int aux = fila.front();
        fila.pop();
        for( int i = 0 ; i < fatoresPrimos[aux].size() ; i++ ){
            if( visitadosFila[aux + fatoresPrimos[aux][i]] == 0 && aux + fatoresPrimos[aux][i] <= t){
                visitadosFila[aux + fatoresPrimos[aux][i]] = visitadosFila[aux]+1;
                if( aux + fatoresPrimos[aux][i]  == t ) return visitadosFila[aux + fatoresPrimos[aux][i] ] -1;
                fila.push(aux + fatoresPrimos[aux][i]);      
            }
        }
    }
    return -1;
}

void solve(int casoTeste, vector<vector<int>> &fatoresPrimos) {

    int s, t; cin >> s >> t;

    if ( s == t ) {
        cout << "Case " << casoTeste << ": " << 0 << "\n";
        return;
    } else if ( eh_primo ( s ) ) {
        cout << "Case " << casoTeste << ": " << -1 << "\n";
    } else if ( s > t ) {
        cout << "Case " << casoTeste << ": " << -1 << "\n";
    } else {
        
        vector<int> visitadosFila(1001,0);        

        cout << "Case " << casoTeste << ": " << calculaNumeroTransformacoes(fatoresPrimos, visitadosFila, s, t) <<  "\n";
    }    

}

int main() {
    int T; // número de casos teste
    cin >> T;

    vector<vector<int>> fatoresPrimos(1001);
    vector<int> visitados(1001,0);
    for(int i = 1 ; i <= 1000 ; i++ ){
        calculaFatoresPrimos( i, fatoresPrimos, visitados, 1 );
    }
    for( int i = 1 ; i <= T ; i++ ){
        solve(i, fatoresPrimos);
    }
    return 0;
}