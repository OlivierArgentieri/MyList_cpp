#pragma once
#include "MyNode.h"
#include "MyIterator.h"

template <typename T>
class MyList
{
private:
	MyNode<T>* m_ptr_head_;
	MyNode<T>* get_last_ptr();
	MyNode<T>* find_by_value(T _tVvalue);
public:
	MyList<T>();
	void push_back(T _type);
	unsigned int get_size();
	MyIterator<T>* begin();
	MyIterator<T>* last();

	void insert(MyIterator<T>* _ptrCurrentIterator, T _tValue);
	void erase(T _tVvalue);
	//void RemoveAt(int _iIndex);
	// todo : InsertAt, Swap, Sort(*method)
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
MyIterator<T>* MyList<T>::begin()
{
	return new MyIterator<T>(m_ptr_head_);
}

template <typename T>
MyIterator<T>* MyList<T>::last()
{
	return new MyIterator<T>(this->get_last_ptr());
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
	MyNode<T> *temp = this->find_by_value(_tVvalue);

	if (temp != nullptr)
	{
		temp->m_next_ptr_->m_previous_ptr_ = temp->m_previous_ptr_;
		temp->m_previous_ptr_->m_next_ptr_ = temp->m_next_ptr_;
		delete(temp);
	}
}
