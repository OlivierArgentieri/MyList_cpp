#pragma once

#include "MyIterator.h"
#include "MyNode.h"

template<typename T>
class IEnumerator
{
	template<typename T> friend class MyList;

private :
	MyNode<T> *m_ptr_my_node;

public:
	virtual  MyIterator<T>* begin() =0;

};
