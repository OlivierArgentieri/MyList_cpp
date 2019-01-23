#pragma once
#include "MyNode.h"
#include "MyIterator.h"

template <typename T>
class MyList
{
private:
	MyNode<T>* m_ptr_head_;
	MyNode<T>* get_last_ptr();


	// return pointer of node for value in parameters
	// return null if not found
	MyNode<T>* find_by_value(T _tVvalue);
public:
	MyList<T>();

	//add element to end of list 
	void push_back(T _type);

	//add element to front of list
	void push_front(T _type);

	// get size of list
	unsigned int get_size();

	// get an iterator on first element
	MyIterator<T> begin();

	// get an iterator on last element
	MyIterator<T> last();

	// remove last element 
	void pop_back();

	// remove first element
	void pop_front();

	// Insert value at position of iterator
	void insert(MyIterator<T>* _ptrCurrentIterator, T _tValue);

	// Erase one value
	void erase(T _tVvalue);

	// Remove all value match with parameters
	void remove(T _tValue);

	// Remove all element in current list
	void clear();

	// Swap 2 items
	void swap(MyIterator<T> _it1, MyIterator<T> _it2);

	//void RemoveAt(int _iIndex);
	// todo : Sort(*method)
};


template <typename T>
MyNode<T>* MyList<T>::get_last_ptr()
{
	if (this->get_size() <= 1)
		return this->m_ptr_head_;

	MyList<T>* temp = new MyList<T>(*this);
	while (temp->m_ptr_head_->m_next_ptr_ != nullptr)
	{
		temp->m_ptr_head_ = temp->m_ptr_head_->m_next_ptr_;
	}
	return temp->m_ptr_head_;
}

template <typename T>
MyNode<T>* MyList<T>::find_by_value(T _tVvalue)
{
	bool finish = false;

	auto temp = this->m_ptr_head_;
	while (!finish && !(temp->m_type_value_ == _tVvalue))
	{
		temp = temp->m_next_ptr_;
		finish = temp == nullptr;
	}
	if (!finish)
		return temp;

	return nullptr;
}

template <typename T>
MyList<T>::MyList()
{
	this->m_ptr_head_ = nullptr;
}


template <typename T>
void MyList<T>::push_back(T _type)
{
	if (this->m_ptr_head_ == nullptr)
	{
		this->m_ptr_head_ = new MyNode<T>(_type);
	}
	else
	{
		auto temp = new MyNode<T>(_type);
		auto temp_prev = this->get_last_ptr();
		temp->m_previous_ptr_ = temp_prev;
		temp_prev->m_next_ptr_ = temp;
	}
}

template <typename T>
void MyList<T>::push_front(T _type)
{
	if(this->m_ptr_head_ == nullptr)
		this->m_ptr_head_ = new MyNode<T>(_type);
	else
	{
		auto temp = new MyNode<T>(_type);
		temp->m_next_ptr_ = this->m_ptr_head_;
		this->m_ptr_head_->m_previous_ptr_ = temp;
		this->m_ptr_head_ = temp;
	}
}

template <typename T>
unsigned MyList<T>::get_size()
{
	if (this->m_ptr_head_ == nullptr)
		return 0;

	unsigned int i = 0;
	MyList<T>* temp = new MyList<T>(*this);
	for (; temp->m_ptr_head_ != nullptr; i++)
	{
		temp->m_ptr_head_ = temp->m_ptr_head_->m_next_ptr_;
	}
	return i;
}

template <typename T>
MyIterator<T> MyList<T>::begin()
{
	return MyIterator<T>(m_ptr_head_);
}

template <typename T>
MyIterator<T> MyList<T>::last()
{
	return MyIterator<T>(this->get_last_ptr());
}

template <typename T>
void MyList<T>::pop_back()
{
	if (this->get_size() < 1)
		return;

	if (this->get_size() == 1)
		this->m_ptr_head_ = nullptr;
	else
	{
		auto temp = this->get_last_ptr();
		temp->m_previous_ptr_->m_next_ptr_ = nullptr;
		delete(temp);
	}
}

template <typename T>
void MyList<T>::pop_front()
{
	if (this->m_ptr_head_ == nullptr)
		return;

	if (this->m_ptr_head_->m_next_ptr_ == nullptr)
	{
		this->m_ptr_head_ = nullptr;
		return;
	}
	auto temp = this->m_ptr_head_;
	this->m_ptr_head_ = temp->m_next_ptr_;
	this->m_ptr_head_->m_previous_ptr_ = nullptr;

	delete(temp);
}

template <typename T>
void MyList<T>::insert(MyIterator<T>* _ptrCurrentIterator, T _tValue)
{
	if (_ptrCurrentIterator == nullptr)
		return;

	MyNode<T>* newChainon = new MyNode<T>(_tValue);
	_ptrCurrentIterator->add_to_previous(_ptrCurrentIterator, newChainon);

}

template <typename T>
void MyList<T>::erase(T _tVvalue)
{
	MyNode<T>* temp = this->find_by_value(_tVvalue);

	if (temp != nullptr)
	{
		if (temp->m_previous_ptr_ == nullptr)
		{
			this->m_ptr_head_ = temp->m_next_ptr_;
		}
		else if(temp->m_previous_ptr_!=nullptr)
		{
			temp->m_previous_ptr_->m_next_ptr_ = temp->m_next_ptr_;
		}
		if (temp->m_next_ptr_ != nullptr)
		{
			temp->m_next_ptr_->m_previous_ptr_ = temp->m_previous_ptr_;
		}
		delete(temp);
	}
}

template <typename T>
void MyList<T>::remove(T _tValue)
{
	auto temp = this->find_by_value(_tValue);
	while (temp != nullptr)
	{
		this->erase(_tValue);
		temp = this->find_by_value(_tValue);
	}
}

template <typename T>
void MyList<T>::clear()
{
	for (int i = this->get_size(); i >= 0; i--)
	{
		this->pop_back();
	}
}

template <typename T>
void MyList<T>::swap(MyIterator<T> _it1, MyIterator<T> _it2)
{
	if (_it1.m_ptr_my_node_ == nullptr || _it2.m_ptr_my_node_ == nullptr)
		return;

	MyNode<T> *temp = (MyNode<T>*) malloc(sizeof(MyNode<T>*));

	memmove(temp, _it1.m_ptr_my_node_, sizeof(MyNode<T>*));
	memmove(_it1.m_ptr_my_node_, _it2.m_ptr_my_node_, sizeof(MyNode<T>*));
	memmove(_it2.m_ptr_my_node_, temp, sizeof(MyNode<T>*)); 
	free(temp);
}