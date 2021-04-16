#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <cstdlib>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

struct Aresta { 
    int v, w;
    Aresta(int v = -1, int w = -1) : v(v), w(w) { }
};

class Graph { 
  int Vcnt, Ecnt; bool digraph;
  vector <list <int> > adj;
public:
  Graph(int V, bool digraph); //construtor
  Graph(const string &file);
  int V() const;
  int E() const;
  bool directed() const;
  void insert(Aresta e);
  void remove(Aresta e);
  bool aresta(int v, int w) const; 
  void save(const string &file) const;

  class adjIterator;
  friend class adjIterator;  
};

class Graph::adjIterator
{ 
  const Graph &G;
  list<int>::const_iterator it;
  int v;
public:
  adjIterator(const Graph &G, int v) ;
  int beg();
  int nxt();
  bool end();
};


#endif