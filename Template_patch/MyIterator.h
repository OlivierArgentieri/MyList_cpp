#pragma once

template <typename T>
class MyIterator
{
	template <typename T>
	friend class MyList;

private:
	MyNode<T>* m_ptr_my_node_;
	MyIterator<T>(MyNode<T>* _ptrMyNode);
	void add_to_previous(MyIterator<T> _CurrentIterator, MyNode<T>* _ptrNewNode);

public:
	MyIterator<T>& operator++();
	MyIterator<T>& operator--();
	T& operator*();
	bool operator!=(MyIterator<T> _ptrIterator);
	MyIterator<T>& element_at(int _iIndex);
	void reset();
};

template <typename T>
MyIterator<T>::MyIterator(MyNode<T>* _ptrMyNode)
{
	this->m_ptr_my_node_ = _ptrMyNode;
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator++()
{
	if (this->m_ptr_my_node_ != nullptr)
	{
		this->m_ptr_my_node_ = this->m_ptr_my_node_->m_next_ptr_;
		return *this;
	}
	throw new std::out_of_range("index out of range");
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator--()
{
	if (this->m_ptr_my_node_ != nullptr && this->m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		this->m_ptr_my_node_ = this->m_ptr_my_node_->m_previous_ptr_;
		return *this;
	}
	this->m_ptr_my_node_ = nullptr;
	return MyIterator<T>(nullptr);
}

template <typename T>
T& MyIterator<T>::operator*()
{
	if (this->m_ptr_my_node_ == nullptr)
	{
		throw new std::out_of_range("List empty or null");
	}
		return this->m_ptr_my_node_->m_type_value_;
}

template <typename T>
bool MyIterator<T>::operator!=(MyIterator<T> _ptrIterator)
{
	return _ptrIterator.m_ptr_my_node_ != this->m_ptr_my_node_;
}

template <typename T>
MyIterator<T>& MyIterator<T>::element_at(int _iIndex)
{
	if (this->m_ptr_my_node_ == nullptr)
		throw std::exception("List empty or null");


	auto temp = this->m_ptr_my_node_;

	if (_iIndex < 0)
		return *this;
	this->reset();
	int i = 0;
	for (; i < _iIndex && this->m_ptr_my_node_ != nullptr; i++)
	{
		++*this;
	}

	if (this->m_ptr_my_node_ == nullptr)
		this->m_ptr_my_node_ = temp;

	return *this;
}

template <typename T>
void MyIterator<T>::reset()
{
	if (this->m_ptr_my_node_ == nullptr)
		return;

	while (this->m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		--*this;
	}
}

template <typename T>
void MyIterator<T>::add_to_previous(MyIterator<T> _CurrentIterator, MyNode<T>* _ptrNewNode)
{
	if (_CurrentIterator.m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		_ptrNewNode->m_previous_ptr_ = _CurrentIterator.m_ptr_my_node_->m_previous_ptr_;
		_ptrNewNode->m_previous_ptr_->m_next_ptr_ = _ptrNewNode;
		_CurrentIterator.m_ptr_my_node_->m_previous_ptr_ = _ptrNewNode;
		_ptrNewNode->m_next_ptr_ = _CurrentIterator.m_ptr_my_node_;
	}
	else
	{
		_ptrNewNode->m_previous_ptr_ = nullptr;
		_CurrentIterator.m_ptr_my_node_->m_previous_ptr_ = _ptrNewNode;
		_ptrNewNode->m_next_ptr_ = _CurrentIterator.m_ptr_my_node_;
	}
}