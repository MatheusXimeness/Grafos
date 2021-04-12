#include<iostream>
#include<vector>
using namespace std;

// ----- Exemplo de Entrda ----- //
    /*
        10(nos) 9(arestas)
        2 1 root
        3 1
        4 3
        5 2
        6 1
        7 2
        8 6
        9 8
        10 8

        Saida:
        2
    */
// ----- ----- //


int contaVertices(int vertice1, vector<bool> &visitados, int grauVertice1, vector<pair<int,int>> const &edges, vector<vector<int>> &nGraus){
    if(visitados[vertice1] == true) return 0;
    visitados[vertice1] = true;
    int tamCC=0;
    tamCC++;

    for(int i = 1 ; i < edges.size() ; i++){
        if (edges[i].first == vertice1 || edges[i].second == vertice1) {
            if(vertice1 == edges[i].first){

               tamCC += contaVertices (edges[i].second, visitados, nGraus[edges[i].second].size(), edges, nGraus);

            }else if (vertice1 == edges[i].second){
            
                tamCC += contaVertices (edges[i].first, visitados, nGraus[edges[i].first].size(), edges, nGraus);

            }
        }
    }
    return tamCC; 
}

int solve2 (int vertice1, int vertice2, vector<pair<int,int>> const &edges, int grauVertice1, int grauVertice2, vector<vector<int>> &nGraus){
    if(grauVertice1 == 1 || grauVertice2 == 1) return 0; // se um dos dois for folha
    else{
        // conta os vertices ligados ao vértice 1 sem ser o 2
            int V1 = 0;
            vector<bool> visitados(nGraus.size(),false);
            visitados[vertice2] = true;
            V1 = contaVertices(vertice1, visitados, grauVertice1, edges, nGraus);
        if(V1%2 == 0)
            return 1;
        else return 0;
    }
}

int solve (int nNodes, int nEdges, vector<pair<int,int>> const &edges, vector<vector<int>> &nGraus){
    int arestasRemovidas = 0;
    for(int i = 1 ; i <= nEdges ; i++){
        arestasRemovidas += solve2(edges[i].first, edges[i].second, edges, nGraus[edges[i].first].size(), 
        nGraus[edges[i].second].size(), nGraus);
    }
    return arestasRemovidas;
}

// deve retorar um inteiro que de o numero maximo de arestas que se pode remover da arvore para obter
// uma floresta de forma que cada CC da floresta contenha um número par de nos
int EvenForest(int nNodes, int nEdges, vector<pair<int,int>> const &edges){
    
    // --- DESCOBRE GRAU DOS VÉRTICES --- //
        vector<vector<int>> nGraus(nNodes+1);
        for(int i = 1 ; i <= nEdges  ; i++){
            nGraus[edges[i].first].push_back(1);
            nGraus[edges[i].second].push_back(1);
        }
    // --- --- //
    /*for(int i = 1 ; i <= nEdges  ; i++){
       cout << "Graus do vertice: " << edges[i].first << " = " <<  nGraus[edges[i].first].size() << ", Grau do vertice: " <<  edges[i].second << " = "<< nGraus[edges[i].second].size() << "\n";  
    }*/
    int x;
    x = solve(nNodes, nEdges, edges, nGraus);
    return x;
}





int main(){
    int nNodes, nEdges;
    cin >> nNodes >> nEdges;

    int a, b; // auxilia na leitura das arestas
    vector<pair<int,int>> edges(nEdges+1, pair<int,int>(0,0)); 
    for(int i = 1 ; i <= nEdges ; i++){
        cin >> a >> b;
        edges[i].first = a;
        edges[i].second = b;
    }

    cout << EvenForest(nNodes, nEdges, edges) << endl;

    return 0;
}