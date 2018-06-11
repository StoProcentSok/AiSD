#include <cstdlib>
#include <iostream>
#include <vector>
#include "Graphs.h"

using namespace std;
Graphs::Graphs(int iloscWierzcholkow) {
	int userValue;
	for (int i = 0; i < iloscWierzcholkow; i++) {
		cout << "Podaj wierzcholek grafu" << endl;
		cin >> userValue;

		krawedz* krawedzTestowa = new krawedz();
		krawedzTestowa->doJakiego = NULL;
		krawedzTestowa->waga = userValue;
		_glowyKrawedzi.push_back(krawedzTestowa);
		delete krawedzTestowa;
	};
}
void Graphs::dodajKrawedz(krawedz* nowaKrawedz, int doKtorejGlowy) {
	if (_glowyKrawedzi[doKtorejGlowy]) {
		//dodaj do glowy na koniec listy
		if (_glowyKrawedzi[doKtorejGlowy]->doJakiego == NULL) {
			_glowyKrawedzi[doKtorejGlowy]->doJakiego = nowaKrawedz;
		}
		else //glowa posiada juz jakies podpiete elementy
		{
			krawedz* temp = _glowyKrawedzi[doKtorejGlowy];
			while (temp->doJakiego != NULL) {
				temp = temp->doJakiego;
			} //po dojechaniu na koniec listy:
			nowaKrawedz->doJakiego = NULL;
			temp->doJakiego = nowaKrawedz;
		}
	}
	else
		cout << "Graph does not consist of such head!" << endl;
}

void Graphs::pokazGraf() {

}

void Graphs::pokazKrawedzi(krawedz* krawedzDyWypisania) {
	if (krawedzDyWypisania == NULL) {
		cout << "NULL" << endl;
	}
	else {
		krawedz* temp = krawedzDyWypisania;
		while (temp->doJakiego != NULL) {
			cout << temp->waga << "-->";
			temp = temp->doJakiego;
		}
		cout << endl;
	}
}

Graphs::Graphs() {
	vector<Graphs::krawedz*> glowyKrawedzi;
}




