#pragma once

template <typename T>
class MyIterator
{
	template<typename T> friend class MyList;

private:
	MyNode<T>* m_ptr_my_node_;
	MyIterator<T>(MyNode<T>* _ptrMyNode);
	void add_to_previous(MyIterator<T>* _ptrCurrentIterator, MyNode<T>* _ptrNewNode);

public:
	MyIterator<T>& operator++();
	MyIterator<T>& operator--();
	MyIterator<T>& operator[](unsigned int _iIndex);
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
	if (this->m_ptr_my_node_ != nullptr && this->m_ptr_my_node_->m_next_ptr_ != nullptr)
	{
		this->m_ptr_my_node_ = this->m_ptr_my_node_->m_next_ptr_;
		return *this;
	}
	this->m_ptr_my_node_ = nullptr;
	return *this;
	
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator--()
{
	if (this->m_ptr_my_node_ != nullptr && this->m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		this->m_ptr_my_node_ = this->m_ptr_my_node_->m_previous_ptr_;
		return *this;
	}
	return *this;
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator[](unsigned int _iIndex)
{
	this->reset();
	int i = 0;
	for (; i< _iIndex && this->m_ptr_my_node_ !=nullptr; i++)
	{
		this->operator++();
	}

	if (this->m_ptr_my_node_ == nullptr)
		this->reset();

	return *this;
}

template <typename T>
void MyIterator<T>::reset()
{
	if (this->m_ptr_my_node_ == nullptr)
		return;

	while (this->m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		this->operator--();
	}
}

template <typename T>
void MyIterator<T>::add_to_previous(MyIterator<T> *_ptrCurrentIterator, MyNode<T> *_ptrNewNode)
{
	if (_ptrCurrentIterator != nullptr && _ptrCurrentIterator->m_ptr_my_node_->m_previous_ptr_ != nullptr)
	{
		_ptrNewNode->m_previous_ptr_ = _ptrCurrentIterator->m_ptr_my_node_->m_previous_ptr_;
		_ptrNewNode->m_previous_ptr_->m_next_ptr_ = _ptrNewNode;
		_ptrCurrentIterator->m_ptr_my_node_->m_previous_ptr_ = _ptrNewNode;
		_ptrNewNode->m_next_ptr_ = _ptrCurrentIterator->m_ptr_my_node_;
	}
	else
	{
		_ptrNewNode->m_previous_ptr_ = nullptr;
		_ptrCurrentIterator->m_ptr_my_node_->m_previous_ptr_ = _ptrNewNode;
		_ptrNewNode->m_next_ptr_ = _ptrCurrentIterator->m_ptr_my_node_;
	}
}