#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class UnionFind 
{
    private:
        vector<double> pai;
    public:
        void createSet ( double tam )
        {
            pai = vector<double>(tam);
            for ( double i = 0 ; i < tam ; i++ ) 
            {
                pai[i] = i;
            }
        }

        double findSet ( double elemento )
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
struct Estradas
{
    Estradas ( int ui, int vj, double dist ) : u ( ui ), v ( vj ), distancia ( dist ) {}
    double distancia;
    int u, v;

    bool operator < ( const Estradas & other )
    {
        return distancia < other.distancia;
    }
};


double calculaDist ( pair<int, int> sarda1, pair<int, int> sarda2 ) {
    int dx = sarda2.first - sarda1.first;
    int dy = sarda2.second - sarda1.second;
    return sqrt ( dx*dx + dy*dy );
}

void solve ( int casoTeste )
{
    int numCidade, limiteMax, x, y;
    cin >> numCidade >> limiteMax;

    vector<pair<int,int>> posCidades(numCidade);

    for ( int i = 0 ; i < numCidade ; i++ )
    {
        cin >> x >> y;
        posCidades[i].first = x; 
        posCidades[i].second = y;
    }
    
    /*for ( int i = 0 ; i < numCidade ; i++ )
    {
        cout <<  posCidades[i].first << ", " <<  posCidades[i].second << endl;
    }*/

    pair<int, int> cidade1;
    pair<int, int> cidade2;
    vector<Estradas> estradas;

    int contEstados = 1;

    for ( int i = 0 ; i < numCidade ; i++ ) {
        for ( int j = i+1 ; j < numCidade ; j++ ) 
        {
            cidade1 = make_pair(posCidades[i].first, posCidades[i].second);
            cidade2 = make_pair(posCidades[j].first, posCidades[j].second);
            double distUV =  calculaDist ( cidade1, cidade2 );
            //cout << "distancia entre cidades: " << posCidades[i].first << ", " <<  posCidades[i].second << " e " << posCidades[j].first << ", " <<  posCidades[j].second <<  " = " << distUV << endl;  

            Estradas e ( i, j, distUV );
            estradas.push_back( e );

        }
    }
    

    sort(estradas.begin(), estradas.end());
    
    UnionFind conjunto1;
    conjunto1.createSet( numCidade );


    double entreCidades = 0;
    double entreEstados = 0;
    for ( const Estradas &e:estradas ) 
    {
        if ( !conjunto1.isSameSet( e.u, e.v ) )
        {
            conjunto1.mergeSets( e.u, e.v );

            if ( e.distancia > limiteMax ) {
                contEstados++;
                entreEstados += e.distancia;
            } else {
                entreCidades += e.distancia;
            }
        }
    }
    
    if (contEstados == 0){
        contEstados = 1;
    }
    cout << "Case #" << casoTeste << ": " << contEstados << " " << round(entreCidades) << " " << round(entreEstados) << "\n"; 
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