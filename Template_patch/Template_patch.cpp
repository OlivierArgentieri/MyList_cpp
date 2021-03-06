// Template_patch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "MyList.h"
#include <string>

int main()
{

	// creation of a list of int
	MyList<int> l;
	// creation of an iterator on end (after the last element, outside of the list)
	MyIterator<int> it = l.end();

	// add element at the end of the list
	l.push_back(5);
	// add element at the begin of the list
	l.push_front(2);

	// insert element before the position of it (here at the end of the list)
	l.insert(it, 6);
	// insert element before the position of it (here at the 2nd position in the list)
	l.insert(++(l.begin()), 3);
	// place it at the first position in the list
	it = l.begin();
	// Insert element before it (at the beginning of the list)
	l.insert(it, 1);

	// iterate through the list using it and print each int inside the list
	// affiche "1 2 3 5 6 "
	for (it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it << " ";
	}

	// the next 2 instruction return an iterator on the element after the one erased
	// deplace the iterator returned by end() at the previous position and delete element at this position
	//it = l.erase(--(l.end()));
	// erase element at the position begin
	//it = l.erase(l.begin());

	// remove last element
	l.pop_back();
	// remove first element
	l.pop_front();

	// empty the list (remove all element in it)
	l.clear();

	/*

	MyList<std::string> *l = new MyList<std::string>();

	//sauto it = l->last();

	l->push_front("test");
	l->push_front("test1");
	l->push_front("test2");

	for (MyIterator<std::string> it = l->begin(); it != l->end(); ++it)
		std::cout << *it;

	

	std::cout << "";*/
}