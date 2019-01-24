#pragma once
template <typename T>
class MyNode
{
	template<typename T> friend class MyList;
	template<typename T> friend class MyIterator;

private:
	T m_type_value_;
	MyNode<T> *m_next_ptr_;
	MyNode<T> *m_previous_ptr_;
	MyNode();
public:
	MyNode(T _tValue);
};

template <typename T>
MyNode<T>::MyNode(T _tValue)
{
	this->m_type_value_ = _tValue;
	this->m_next_ptr_ = nullptr;
	this->m_previous_ptr_ = nullptr;
}

template <typename T>
MyNode<T>::MyNode()
{
	//this->m_type_value_ = nullptr;
	this->m_next_ptr_ = nullptr;
	this->m_previous_ptr_ = nullptr;
}