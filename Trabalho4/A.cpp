//Problema de árvore geradora mínima!!
//Dúvida a respeito de como a saída será calculada
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

class UnionFind 
{
    private:
        vector<double> pai;
    public:
        void createSet ( double tam )
        {
            pai = vector<double>(tam);
            for ( int i = 0 ; i < tam ; i++ ) 
            {
                pai[i] = i;
            }
        }

        int findSet ( double elemento )
        {
            if ( pai[elemento] == elemento )
            {
                return elemento;
            }
            // descobre quem é o representante de elem
            double representanteElem = findSet ( pai[elemento] );
            pai[elemento] = representanteElem;
            return representanteElem;
        }

        void mergeSets ( double i, double j )
        {
            pai [ findSet( i ) ] = findSet( j ); // o pai do elemento que eu quero juntar, recebe o pai do que vai ser juntado
        }

        bool isSameSet ( double i, double j )
        {
            return findSet( i ) == findSet( j );
        }
};

struct Edges {
    Edges ( double ui, double vj, double dist ) : u ( ui ) , v ( vj ) , distXY ( dist ) {}
    double distXY;
    double u, v;

    bool operator < ( const Edges & other )
    {
        return distXY < other.distXY;
    }
};

double calculaDist ( pair<double, double> sarda1, pair<double, double> sarda2 ) {
    double dx = sarda2.first - sarda1.first;
    double dy = sarda2.second - sarda1.second;
    return sqrt ( dx*dx + dy*dy );
}

void solve ()
{
    int numSardas;
    cin >> numSardas;

    vector<pair<double,double>> posicoes ( numSardas );
    
    double x, y;

    for ( int i = 0 ; i < numSardas ; i++ )
    {
        cin >> x >> y;
        posicoes[i].first = x; 
        posicoes[i].second = y;
    }
    // -----  Testa Armazenamento ----- //
        /*for ( int i = 0 ; i < numSardas ; i++ ) {
            cout << fixed << setprecision(1) << posicoes[i].first << ", " << posicoes[i].second << endl;
        }*/
    // ----- ----- //
    vector< Edges > arestas;
    pair<double, double> sarda1;
    pair<double, double> sarda2;
    

    // ----- Colocando as distâncias das arestas ----- //
    for ( double i = 0 ; i < numSardas ; i++ ) {
        for ( double j = i+1 ; j < numSardas ; j++ ) 
        {
            sarda1 = make_pair(posicoes[i].first, posicoes[i].second);
            sarda2 = make_pair(posicoes[j].first, posicoes[j].second);

            Edges e ( i, j, calculaDist(sarda1, sarda2) );
            arestas.push_back( e );
        }
    }
    // ----- ----- //

    sort( arestas.begin(), arestas.end() );

    UnionFind conjuntos;
    conjuntos.createSet( numSardas );

    double resposta = 0;
    for ( const Edges &e:arestas ) 
    {
        if ( !conjuntos.isSameSet( e.u, e.v ) )
        {
            conjuntos.mergeSets( e.u, e.v );
            resposta += e.distXY;
        }
    }
    cout << fixed << setprecision(2) << resposta << "\n";
}

int main() 
{    
    int numCasos;  cin >> numCasos;  // lê número de casos testes
    
    for ( int i = 0 ; i < numCasos ; i++ ) 
    {
        //string barraN;
        //cin >> barraN; // lê linha vazia
        solve();
        if( i != numCasos-1)
            cout << "\n";
    }
    
    return 0;
}

