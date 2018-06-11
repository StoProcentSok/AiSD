#ifndef GRAPHS_H
#define GRAPHS_H
#include<vector>
#include "../SingleLinkedLists/SinLiLists.h"

class Graphs {
	
public:
	struct krawedz {
		krawedz* doJakiego = NULL;
		int waga = 0;
	};
	
	Graphs();
	Graphs(int iloscWierzcholkow);
	void dodajKrawedz(krawedz*, int doKtorejGlowy);
	void pokazGraf();


	std::vector<krawedz*> _glowyKrawedzi;

private:
	void pokazKrawedzi(krawedz*);

	
};
#endif 
