#ifndef GRAPHS_H
#define GRAPHS_H
#include<vector>
#include <iostream>

#include "../SingleLinkedLists/SinLiLists.h"

using namespace std;

class Node {
public:
	int n;
	Node *next;

	Node() { n = 0; next = this; } //node pointing on itself, this way creates loop and one element set. 
private:
};

class Edge {
public:
	int startingVertex, endingVertex, weightOfWertex; 
	bool IsAdded; //changed when Kruskal decides to add this edge to MST.
	
	Edge()	{ startingVertex = 0; endingVertex = 0; weightOfWertex = 0; IsAdded = false; }

	void AddToMST() {
		IsAdded = true;
	}
};

class KruskalHelper {
public: 
	Node * node;
	int Vertices;

	KruskalHelper(int Vertices) { this->Vertices = Vertices; node = new Node[Vertices + 1]; for (int i = 0; i <= Vertices; i++) node[i].n = i; } // numbering vertices from 1 to NumberOfVertices.
	int FindSet(int u);
	void Union(int u, int v);
};



	/*struct krawedz {
		krawedz* doJakiego = NULL;
		int waga = 0;
	};
	
	Graphs();
	Graphs(int iloscWierzcholkow);
	void dodajKrawedz(krawedz*, int doKtorejGlowy);
	void pokazGraf();


	std::vector<krawedz*> _glowyKrawedzi;
	

	struct Edge {
		int SourceVertice;
		int DestinationVertice;
		int EdgeWeight;
	};

	struct Graph {
		int Vertices;
		int Edges;
		struct Edge* edge;
	};
*/





//private:
	//void pokazKrawedzi(krawedz*);

	

#endif 
