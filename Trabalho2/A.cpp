#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int MDC(int numerador, int denominador)
{
    if(numerador%denominador == 0)
        return denominador;
    else
        return MDC(denominador, numerador%denominador);
}

void dfsCalculaTaxa( vector<vector<int>> &lista, int i, int j, int numVertices ){
	int  a, b, c, d;
    int  mdc, simplificado1, simplificado2;

    //Para todos os vizinhos
	for(int k = 0; k < numVertices; k++){
		if(i != k && lista[j][k] && !lista[i][k]){
			a = lista[i][j];
            b = lista[j][i];

			c = lista[j][k];
            d = lista[k][j];

			mdc = MDC(b, c);

			simplificado1 = c / mdc;
			simplificado2 = b / mdc;

			mdc = MDC(a * simplificado1, d * simplificado2);
			lista[i][k] = a * simplificado1 / mdc;
			lista[k][i] = d * simplificado2 / mdc;
			dfsCalculaTaxa(lista, i, k, numVertices);
		}
	}
}

int main () {

    char ponto, igual;
    string A, B;
    int numerador, denominador, mdc;

    map<string, int> taxa;
    vector<vector<int>> lista(61, vector<int>(61,0)); // lista de adj com máximo valor que o programa pode dar
    int posListaFirst, posListaSecond, numVertices = 0;

    while(true){
        cin >> ponto;
        if ( ponto == '.' ) break;
        else if ( ponto == '!' ) {
            cin >> numerador >> A >> igual >> denominador >> B;
            // --- Alocação --- //
                if(taxa.find(A) == taxa.end()) // se não estiver
				    taxa[A] = numVertices++; //add
			    if(taxa.find(B) == taxa.end())
				    taxa[B] = numVertices++;

			    posListaFirst = taxa[A]; 
                posListaSecond = taxa[B];

			    mdc = MDC(numerador, denominador);

                // coloca na lista de adj os valores simplificados
			    lista[posListaFirst][posListaSecond] = numerador / mdc;
			    lista[posListaSecond][posListaFirst] = denominador / mdc;
            // --- --- //
        }
        else if ( ponto == '?' ) {

            cin >> A >> igual >> B;
            if(taxa.find(A) == taxa.end()) // se não estiver
				taxa[A] = numVertices++; // add
			if(taxa.find(B) == taxa.end())
				taxa[B] = numVertices++;

			posListaFirst = taxa[A];
            posListaSecond = taxa[B];

            // para todos os vizinhos da string em questão
			for(int k = 0; k < numVertices; k++){ 
				if( lista[posListaFirst][k] != 0 ) {
					dfsCalculaTaxa( lista, posListaFirst, k, numVertices );
                }
            }
			if( lista[posListaFirst][posListaSecond] != 0 )
				cout << lista[posListaFirst][posListaSecond] << " " << A << " = " << lista[posListaSecond][posListaFirst] << " " << B << endl;
			else
				cout << "? " << A << " = ? " << B << endl;
        }

    }

    return 0;
}