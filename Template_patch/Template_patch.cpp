// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"

int main()
{
	MyList<int> *t = new MyList<int>();
	t->get_size();
	t->push_back(10);
	t->push_back(10);
	t->push_back(10);
	t->push_back(10);
	t->push_back(10);
	t->push_back(10);
	
	t->get_size();
	t->push_back(11);
	t->get_size();

	t->push_back(12);
	t->push_back(13);
	t->get_size();

	t->push_back(14);

	t->push_back(15);

	t->erase(12);
	

	t->push_back(10);
	auto o = t->begin();

	**o[2] = 100;


	t->remove(10);

	t->push_front(150);

	t->pop_front();
	o = t->begin();

	**o = 1000;

	++o;;
	std::cout << "Hello World!\n";
}
