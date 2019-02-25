#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main() {
	cout << "Test dizionario" << endl;
	HashMap<int, string> map(0);
	map.put(1, "val1");
	map.put(2, "val2");
	map.put(3, "val3");
	map.put(2, "val4");
	map.put(5, "val5");
	string value;
	map.get(5, value);
	cout << value << endl;
	value = "";
	map.get(6, value);
	cout << value << endl;
	map.remove(2);
	map.get(2, value);
	cout << value << endl;
	map.get(3, value);
	cout << value << endl;
	cout << "END" << endl;


	 cout << endl << "Test dizionario string" << endl;
	 HashMap<string, string> map2(10);
	 map2.put("abc", "val1");
	 map2.put("def", "val2");
	 map2.put("lol", "val3");
	 map2.put("asd", "val4");
	 map2.put("rofl", "val5");
	 string value2;
	 map2.get("rofl", value2);
	 cout << value2 << endl;
	 cout << "END2";

	 string word = "ciao";
	 cout << endl << (int)word.at(2);


}

