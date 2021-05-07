#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 /* 
cout << casoTeste << endl;
cout << intersecoes << " " << estradas << endl;
for ( int i = 0 ; i < estradas ; i++ ) {
    cout << roads[i].u << " " << roads[i].v << " " <<  roads[i].capMax << endl;
}
*/

class UnionFind 
{
    private:
        vector<int> pai;
    public:
        void createSet ( int tam )
        {
            pai = vector<int>(tam);
            for ( int i = 0 ; i < tam ; i++ ) 
            {
                pai[i] = i;
            }
        }

        int findSet ( int elemento )
        {
            if ( pai[elemento] == elemento )
            {
                return elemento;
            }
            // descobre quem é o representante de elem
            int representanteElem = findSet ( pai[elemento] );
            pai[elemento] = representanteElem;
            return representanteElem;
        }

        void mergeSets ( int i, int j )
        {
            pai [ findSet( i ) ] = findSet( j ); // o pai do elemento que eu quero juntar, recebe o pai do que vai ser juntado
        }

        bool isSameSet ( int i, int j )
        {
            return findSet( i ) == findSet( j );
        }
};

struct Estradas
{
    Estradas ( int ui, int vj, int capacidade ) : u ( ui ), v ( vj ), capMax ( capacidade ) {}
    int u, v, capMax;

    bool operator < ( const Estradas & other )
    {
        return capMax < other.capMax;
    }
};


void solve ( int casoTeste )
{
    int estradas, intersecoes;
    cin >> intersecoes >> estradas;

    vector<Estradas> roads;
    int a, b, cap;
    for ( int i = 0 ; i < estradas ; i++ )
    {
        cin >> a >> b >> cap;
        Estradas e ( a, b, cap );
        roads.push_back(e);
    }

    sort( roads.begin(), roads.end() );
    vector<Estradas> roadsAux;

    for ( int i = roads.size()-1 ; i >= 0 ; i-- )
    {   
        Estradas aux ( roads[i].u, roads[i].v, roads[i].capMax );
        roadsAux.push_back ( aux );
    }

    UnionFind conjuntos;
    conjuntos.createSet( intersecoes );

    vector<int> resposta;
    for ( const Estradas &e:roadsAux ) 
    {
        if ( !conjuntos.isSameSet( e.u, e.v ) )
        {
            conjuntos.mergeSets( e.u, e.v );
            resposta.push_back( e.capMax );
        }
    }
    
    cout << "Case #" << casoTeste << ": " << resposta[resposta.size()-1] << "\n"; 
}

int main ()
{
    int numCasos;  cin >> numCasos;  // lê número de casos testes
    
    for ( int i = 1 ; i <= numCasos ; i++ ) 
    {
        solve(i);
    }
    return 0;
}