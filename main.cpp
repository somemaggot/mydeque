#include <iostream>
#include "mydeque.h"


int main()
{
	myDeque<int>* deq = new myDeque<int>();
	int a = 4;


	deq->push_front(a);
	deq->push_back(5);
	deq->push_front(3);
	deq->push_back(a);
	
	deq->pop_front(&a);
	std::cout << a << std::endl;

	deq->print();

	delete deq;

	return 0;
}