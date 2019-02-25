#include <iostream>
#include "node.h"
#include "linkedList.h"

using namespace std;

int main() {

	LinkedList<int> list;
	list.insertEnd(1);
	list.insertEnd(2);
	list.insertEnd(3);
	list.insertEnd(4);
	list.insertEnd(5);
	LinkedList<int> list2(list);
	cout << list;
	cout << "Lunghezza lista: " << list.listLenght() << endl;
	cout << list2;
	cout << "Lunghezza lista2: " << list2.listLenght();
	cout << endl << endl << "TEST OVERLOAD == : (devono essere uguali)" << endl;
	if (list == list2)
		cout << "LISTA 1 E 2 SONO UGUALI" << endl;
	else
		cout << "NON SONO UGUALI" << endl;
	list2.insertEnd(6);
	cout << endl << "TEST OVERLOAD n2 == : (non devono essere uguali)" << endl;
	if (list == list2)
		cout << "LISTA 1 E 2 SONO UGUALI" << endl;
	else
		cout << "NON SONO UGUALI" << endl;
	cout << endl << list;
	cout << "Lunghezza lista: " << list.listLenght();
	cout << endl << list2;
	cout << "Lunghezza lista2: " << list2.listLenght();
	list.insertEnd(4);
	cout << endl << list;
	cout << "Lunghezza lista: " << list.listLenght();
	list.insertInPosition(8, 0);
	cout << endl << list;
	cout << "Lunghezza lista: " << list.listLenght();
	cout << endl << "Leggo primo: " << list.readFirst();
	cout << endl << "Leggo ultimo: " << list.readLast();
	int pos = list.getDatasPosition(0);
	cout << endl << pos;
	if (pos) {
		cout << endl << "trovato";
	} else {
		cout << endl << "non trovato";
	}
	list.eraseInPosition(1);
	cout << endl << list;
	cout << "Lunghezza lista: " << list.listLenght();
	list.eraseData(4);
	cout << endl << list;
	cout << "Lunghezza lista: " << list.listLenght();
	cout << endl << endl << "l1: " << list.listLenght() << " list2: " << list2.listLenght() << endl;
	cout << endl << endl << "TEST SWAP METHOD: " << endl;
	cout << "Lista prima: " << list.listLenght() << endl << list;
	cout << endl << "Lista2 prima: " << list2.listLenght() << endl << list2;
	list.swap(list2);
	cout << "Lista dopo: " << list.listLenght() << endl << list;
	cout << endl << "Lista2 dopo: " << list2.listLenght() << endl << list2;
	list.insertEnd(7);
	list2.insertEnd(8);
	cout << "Lista: " << endl << list;
	cout << endl << "Lista2: " << endl << list2;
	cout << endl << "test append" << endl;
	list.appendList(list2);
	cout << list << "lunghezza lista: " << list.listLenght();
	cout << endl << "Test operatore = overload" << endl;
	LinkedList<int> list3;
	list3 = list;
	list3.insertEnd(10);
	cout << endl << "LISTA 1: " << list.listLenght() << endl << list;
	cout << endl << list3 << endl << "l lista3: " << list3.listLenght();
	cout << endl << "Test operatore += overload" << endl;
	list3 += list2;
	cout << list3;
	LinkedList<int> list4 = list + list2;
	cout << endl << "list4: " << list4.listLenght() << endl << list4;
	cout << endl << "readpos: " << list4.readPosition(50);
	cout << endl << list;
	cout << endl << list2;
	cout << endl << list3;
	cout << endl << "fine";
}

