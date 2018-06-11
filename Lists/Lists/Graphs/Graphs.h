#ifndef GRAPHS_H
#define GRAPHS_H
#include "../SingleLinkedLists/SinLiLists.h"

class Graphs : SingleLinkedList {
	
public:
	struct krawedz {
		krawedz* doJakiego;
		int waga;
	};
	
	Graphs();
	Graphs(int iloscWierzcholkow) {
		
	}

	krawedz* listaGlow[];
};
#endif 
