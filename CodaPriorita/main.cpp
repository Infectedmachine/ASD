#include <iostream>
#include "PriorityHeap.h"

int main() {
	PriorityHeap<int> queue;
	queue.insert(9);
	queue.insert(6);
	queue.insert(2);
	queue.insert(3);
	queue.insert(0);
	queue.insert(5);
	queue.insert(4);
	queue.insert(1);
	queue.insert(8);
	queue.insert(7);
	queue.print();
	int min = 0;
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.print();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();
	queue.min(min);
	std::cout << min << std::endl;
	queue.eraseMin();

}
