#include <assert.h>

#ifndef LINKSTACKNODE
#define LINKSTACKNODE

//定义链栈的节点
template <class T> class LinkStackNode
{
public:
	T data;
	LinkStackNode<T> * link;

	LinkStackNode(T& value) :data(value), link(NULL){}
};

//定义链栈
template <class T> class LinkStack
{
private:
	LinkStackNode<T> * tos;
public:
	LinkStack(): tos(NULL){}

	void Push(T& value);
	T& GetTop();
	T Pop();

	bool IsEmpty();
	void MakeEmpty();
};

template <class T> void LinkStack<T>::Push(T& value)
{
	LinkStackNode<T> *add = new LinkStackNode<T>(value);
	add->link = tos;
	tos = add;
}

template <class T> T& LinkStack<T>::GetTop()
{
	return tos->data;
}

template <class T> T LinkStack<T>::Pop()
{
	assert(tos != NULL);

	T value;
	value = tos->data;
	tos = tos->link;

	return value;
}

template <class T> bool LinkStack<T>::IsEmpty()
{
	if (tos == NULL)
		return true;
	else
		return false;
}

template <class T> void LinkStack<T>::MakeEmpty()
{
	while (!this->IsEmpty())
	{
		this->Pop();
	}
}
#endif