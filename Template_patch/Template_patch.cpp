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
	auto o = t->begin();

	o->operator++();


	t->insert(o, 50);

	
	t->get_size();
	t->push_back(11);
	t->get_size();

	t->push_back(12);
	t->push_back(13);
	t->get_size();

	t->push_back(14);

	t->push_back(15);

	t->erase(12);
	t;
	t->get_size();
	std::cout << "Hello World!\n";
}