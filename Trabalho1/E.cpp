#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  // para usar o max()
#include<vector>
using namespace std;  
  

int search(int pos, vector<int> &funcionarios){  
    int y = pos;  
    int nivel = 1;  
    while (funcionarios[y] != -1)  {  
        y = funcionarios[y];  
        nivel++;  
    }  
    return nivel;  
}  
  
int main(){ 

// --- Inicializando variaveis --- //
    int nFuncionarios;
    int nivel = 1;
    cin >> nFuncionarios;  
    vector<int> funcionarios(nFuncionarios);
// --- --- //

// --- Leitura --- /
    for(int i = 1; i <= nFuncionarios; ++i){  
        int pi;  
        cin >> pi;  
        funcionarios[i] = pi;  
    }  
// --- --- //

for (int i = 1; i <= nFuncionarios; ++i){ 
    nivel = max(nivel, search(i, funcionarios));
}

cout << nivel << endl;  

return 0;  
}  