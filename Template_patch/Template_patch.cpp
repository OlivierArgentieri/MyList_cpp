// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"
#include <string>

int main()
{
	MyList<std::string> *l = new MyList<std::string>();

	//sauto it = l->last();

	l->push_front("test");
	l->push_front("test1");
	l->push_front("test2");

	for (MyIterator<std::string> it = l->begin(); it != l->end(); ++it)
		std::cout << *it;

	

	std::cout << "";
}