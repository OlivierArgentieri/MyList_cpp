// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"

int main()
{

	MyList<int> *t2 = new MyList<int>();
	t2->push_front(20);
	t2->push_front(30);


	t2->swap(t2->begin(), ++t2->begin());

	std::cout << "Hello World!\n";
}
