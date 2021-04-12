#include<iostream>
#include<string>
#include<set>
using namespace std;

void descobreTamFloresta(){
	string leAresta;  // auxilia na leitura da quantidade de arestas
	string arestas;   // auxilia na leitura da quantidade de bolotas
	string verts;     // auxilia na leitura da quantidade de vértices
	int nArestas = 0; // guarda o número de arestas
	int nCC;          // guarda o número de componentes conexos
	// ----- LEITURA ----- //
		while(true){
			cin >> leAresta;
			arestas += leAresta;
			if(leAresta[0] == '*') break;
			nArestas++;
		}
		cin >> verts;
	// -----  ----- //
	set<char> vertices(verts.begin(), verts.end());
	vertices.erase(','); // apaga a vírgula que separa as letras maiusculas

	nCC = vertices.size() - nArestas; // pela teoria, temos que Número de componentes conexos é |V| - |E|

	set<char> verticesEmArestas(arestas.begin(), arestas.end());
	int numIsolados = 0;
	for(char vert:vertices){
		if(verticesEmArestas.count(vert) == 0) numIsolados++;
	}
	cout << "There are " << nCC-numIsolados  << " tree(s) and " << numIsolados << " acorn(s)." <<  "\n";
}


int main(int argc, char **argv){
    int nTestes; // número de casos teste
	cin >> nTestes;
	for(int i = 0 ; i < nTestes ; i++){
		descobreTamFloresta();
	}
    return 0;
}