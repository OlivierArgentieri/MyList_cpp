// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"
#include <string>

int main()
{
	auto t = new MyList<std::string>();

	t->push_back("A");
	t->push_back("B");
	t->push_back("C");
	t->push_back("C");
	t->push_back("C");
	t->push_back("C");

	auto s = t->element_at(12);

	std::cout << "";
}