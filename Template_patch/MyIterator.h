#pragma once

template <typename T>
class MyIterator
{
	template<typename T> friend class MyList;

private:
	MyNode<T>* m_ptr_my_node_;
	MyIterator<T>(MyNode<T>* _ptrMyNode);
	void add_to_previous(MyIterator<T> _CurrentIterator, MyNode<T>* _ptrNewNode);

public:
	MyIterator<T>& operator++();
	MyIterator<T>& operator--();
	T *operator*();
	MyIterator<T>& operator[](int _iIndex);
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
	this->m_ptr_my_node_ = nullptr;
	return *this;
}

template <typename T>
T* MyIterator<T>::operator*()
{
	try
	{
		if (this->m_ptr_my_node_ == nullptr)
			throw std::exception("List empty or null");

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occured: " << e.what() << std::endl;
	}
	
	return &this->m_ptr_my_node_->m_type_value_;
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator[](int _iIndex)
{
	// todo error car peut retourner un objet avec pointeur null
	try
	{
		if (this->m_ptr_my_node_ == nullptr)
			throw std::exception("Iterator created with a null or empty list !");

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occured: " << e.what() << std::endl;
	}
	
	auto temp = this->m_ptr_my_node_;
	
	if (_iIndex < 0)
		return *this;
	this->reset();
	int i = 0;
	for (; i< _iIndex && this->m_ptr_my_node_ !=nullptr; i++)
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
void MyIterator<T>::add_to_previous(MyIterator<T> _CurrentIterator, MyNode<T> *_ptrNewNode)
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