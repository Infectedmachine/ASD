#include <iostream>
#include <string>
#include "Insieme.h"

using namespace std;

int main() {
	cout << "Test Insieme" << endl;
	Insieme<string> insieme(100);
	insieme.insertElement("asd");
	insieme.insertElement("lol");
	insieme.insertElement("bob");
	cout << insieme << "size:" << insieme.sizeInsieme();
	Insieme<string> insieme2(100);
	insieme2.insertElement("asd");
	insieme2.insertElement("bob");
	insieme2.insertElement("cat");
	cout << endl << insieme2 << "size2: " << insieme2.sizeInsieme();
	cout << endl << insieme.Union(insieme2);
	cout << endl << "TEST DIFFERENCE" << endl;
	cout << insieme.Difference(insieme2);
	cout << endl << insieme2.Difference(insieme);
	cout << endl << "TEST INTERSECTION" << endl;
	cout << insieme.Intersection(insieme2);
	cout << endl << insieme2.Intersection(insieme);
	cout << endl << "FINE";
}

