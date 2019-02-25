#include <iostream>
#include "pile.h"

using namespace std;

int main() {
	cout << "Test Pile" << endl;
	Pile<int> pile(4);
	pile.push(1);
	pile.push(2);
	pile.push(3);
	pile.push(4);
	pile.push(5);
	cout << pile.readTop() << endl;
	cout << pile;

	//PROMEMORIA: AGGIUNGERE CONFRONTO PILE E LISTE E COSTRUTTORE COPIA.
}



