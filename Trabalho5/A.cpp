#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, string> achaPosicaoAdj;

string find(string pos)
{
    if(achaPosicaoAdj[pos] == "")
    {
        return pos;
    }
    return achaPosicaoAdj[pos] = find(achaPosicaoAdj[pos]);
}

struct Caminho
{
    Caminho ( int toneladas, string cA, string cB ) : peso ( toneladas ), cidadeA ( cA ), cidadeB ( cB ) {}
    int peso;
    string cidadeA, cidadeB;

    bool operator < ( const Caminho & other )
    {
        return peso > other.peso;
    }
};

int solve ( int casoTeste )
{
    int numCidades, numSegmentos;
    string cidadeA, cidadeB;
    int peso;
    cin >> numCidades >> numSegmentos;

    if ( numCidades == 0 && numSegmentos == 0 ) return -1;

    achaPosicaoAdj.clear();

    vector<Caminho> estradas;
    string origem, destino;
    
    for ( int i = 0 ; i < numSegmentos ; i++ )
    {
        cin >> cidadeA >> cidadeB >> peso;
        Caminho c ( peso, cidadeA, cidadeB );
        estradas.push_back( c );
    }

    cin >> origem >> destino;

    sort(estradas.begin(), estradas.end());

    int caminhoMinimo = 1000000;

    for ( int i = 0 ; i < numSegmentos ; i++ )
    {
        string u = find(estradas[i].cidadeA);
        string v = find(estradas[i].cidadeB);
        if(u != v)
        {
            achaPosicaoAdj[u] = v;

            if( caminhoMinimo > estradas[i].peso )
            {
                caminhoMinimo = estradas[i].peso;
            }
        }

        if(find(origem) == find(destino))
        {
            break;
        }
    }

    cout << "Scenario #" << casoTeste << "\n";
    cout << caminhoMinimo << " tons" << "\n"; 
   
    return 0;
}


int main () {

    int casosTeste = 1000000;

    for ( int i = 1 ; i < casosTeste ; i++ ) 
    {
        if ( solve ( i ) == -1 )
            break;
        cout << "\n";
    }
    return 0;
}