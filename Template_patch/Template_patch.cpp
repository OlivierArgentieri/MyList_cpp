// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"
#include <string>

int main()
{

	auto t = new MyList<std::string>();

	t->push_back("test");
	auto o = t->begin();
	auto p = t->last();
	t->swap(o, p);
	
	std::cout << **t->begin()[2];
}