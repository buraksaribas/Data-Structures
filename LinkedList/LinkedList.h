#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Node.h"

namespace DS
{

	template <class T>
	class LinkedList
	{
		template <class T>
		friend void DisplayList(const LinkedList<T>& list);
	public:
		LinkedList();
		LinkedList(T value);
		LinkedList(Node<T>* node);
		LinkedList(const LinkedList&) = delete;
		~LinkedList();

		// Returns the number of data elements in list.
		int GetSize() const;
		// Returns true if list is empty
		bool IsEmpty();
		// Returns the value of the nth item, indexed starting at 0
		T ValueAt(int index);
		// Adds an item to the front of the list
		void PushFront(T value);
		// Remove front item, returning its value
		T PopFront();
		// Pushes the item on the end of the list
		void PushBack(T value);
		// Removes end item and returns its value
		T PopBack();
		// Returns value of front item.
		T Front();
		// Returns the value of the end item.
		T Back();
		// Insert value at index, so current item at that index is
		// pointed to by new item at index. Indexes start at 0.
		void Insert(int index, T value);
		// Erase node at the given index. Indexes start at 0.
		void Erase(int index);
		// Returns the value of the node at nth position from the end of the list.
		// Last position would be 1, second to last is 2, etc.
		T ValueNFromEnd(int n);
		// Reverses the items stored in the list
		void Reverse();
		// removes the first item in the list with the given value
		void RemoveValue(T value);

	private:
		Node<T>* _head;
		Node<T>* _tail;
	};

	template <class T>
	LinkedList<T>::LinkedList()
		: _head(nullptr), _tail(nullptr)
	{
	}

	template <class T>
	LinkedList<T>::LinkedList(T value)
		: _head(new Node(value)), _tail(_head)
	{
	}

	template <class T>
	LinkedList<T>::LinkedList(Node<T>* node)
		: _head(node), _tail(_head)
	{

	}

	template <class T>
	LinkedList<T>::~LinkedList()
	{
		Node<T>* curr = _head;
		while(_head)
		{
			_head = _head->GetNext();
			delete curr;
			curr = _head;
		}
		_head = curr = _tail = nullptr;
	}

	template <class T>
	int LinkedList<T>::GetSize() const
	{
		Node<T>* curr = _head;
		int size = 0;
		while(curr)
		{
			curr = curr->GetNext();
			++size;
		}
		return size;
	}

	template <class T>
	bool LinkedList<T>::IsEmpty()
	{
		return _head == nullptr;
	}

	template <class T>
	T LinkedList<T>::ValueAt(int index)
	{
		Node<T>* curr = _head;
		for(int i = 1; i < index; i++)
			curr = curr->GetNext();

		return curr->GetData();
	}

	template <class T>
	void LinkedList<T>::PushFront(T value)
	{
		Node<T>* curr = new Node<T>(value, _head);

		if(_head == nullptr)
		{
			_tail = _head = curr;
			return;
		}

		_head = curr;
	}

	template <class T>
	T LinkedList<T>::PopFront()
	{
		if(IsEmpty())
			throw "List is empty";

		Node<T>* curr = _head;
		_head = _head->GetNext();
		T value = curr->GetData();
		delete curr;

		return value;
	}

	template <class T>
	void LinkedList<T>::PushBack(T value)
	{
		Node<T>* temp = new Node<T>(value);
		if(_head == nullptr)
		{
			_tail = _head = temp;
			return;
		}
		_tail->SetNext(temp);
		_tail = temp;
	}

	template <class T>
	T LinkedList<T>::PopBack()
	{
		if(IsEmpty())
			throw "List is empty";

		T value;
		if(_head == _tail)
		{
			value = _head->GetData();
			delete _head;
			_head = _tail = nullptr;
			return value;
		}

		Node<T>* curr = _head;
		while(curr->GetNext() != _tail)
		{
			curr = curr->GetNext();
		}

		value = _tail->GetData();
		delete _tail;
		_tail = curr;

		return value;
	}

	template <class T>
	T LinkedList<T>::Front()
	{
		if(!_head)
			throw "Empty list";

		return _head->GetData();
	}

	template <class T>
	T LinkedList<T>::Back()
	{
		if(!_head)
			throw "Empty list";

		return _tail->GetData();
	}

	template <class T>
	void LinkedList<T>::Insert(int index, T value)
	{
		if(index == 1)
		{
			PushFront(value);
		}
		else if(index > GetSize())
		{
			PushBack(value);
		}
		else
		{
			Node<T>* curr = _head;
			for(int i = 0; i < index - 2; ++i)
			{
				curr = curr->GetNext();
			}

			Node<T>* temp = new Node<T>(value, curr->GetNext());
			curr->SetNext(temp);
		}
	}

	template <class T>
	void LinkedList<T>::Erase(int index)
	{
		if(!_head)
			throw "Empty list";

		if(index == 1)
		{
			PopFront();
		}
		else if(index > GetSize())
		{
			PopBack();
		}
		else
		{
			Node<T>* curr = _head;
			for(int i = 0; i < index - 2; ++i)
			{
				curr = curr->GetNext();
			}

			Node<T>* temp = curr->GetNext();
			curr->SetNext(temp->GetNext());
			delete temp;
			temp = nullptr;
		}
	}

	template <class T>
	T LinkedList<T>::ValueNFromEnd(int n)
	{
		if(!_head)
			throw "Empty list";

		if(n == 1)
		{
			return _tail->GetData();
		}

		Node<T>* curr = _head;
		for(int i = GetSize(); i > n; --i)
		{
			curr = curr->GetNext();
		}

		return curr->GetData();
	}

	template <class T>
	void LinkedList<T>::Reverse()
	{
		if(!_head)
			throw "Empty list";

		if(_head == _tail)
			return;

		Node<T>* prev = nullptr;
		Node<T>* curr = _head;
		Node<T>* next = nullptr;
		_tail = _head;

		while(curr)
		{
			next = curr->GetNext();
			curr->SetNext(prev);
			prev = curr;
			curr = next;
		}

		_head = prev;
	}

	template <class T>
	void LinkedList<T>::RemoveValue(T value)
	{
		if(!_head)
			throw "Empty list";

		Node<T>* curr = _head;

		if(_head == _tail && _head->GetData() == value)
		{
			delete _head;
			_head = _tail = nullptr;
			return;
		}

		Node<T>* prev = nullptr;
		while(curr)
		{
			if(curr->GetData() == value && _head->GetNext()->GetNext() == nullptr)
			{
				prev = curr->GetNext();
				delete curr;
				curr = nullptr;
				_head = prev;
				return;
			}

			if(curr->GetData() == value && curr == _tail)
			{
				_tail = prev;
				_tail->SetNext(nullptr);
				delete curr;
				curr = nullptr;
				return;
			}

			if(curr->GetData() == value)
			{
				prev->SetNext(curr->GetNext());
				delete curr;
				curr = nullptr;
				return;
			}
			prev = curr;
			curr = curr->GetNext();
		}
	}

	template <class T>
	void DisplayList(const LinkedList<T>& list)
	{
		Node<T>* curr = list._head;
		while(curr)
		{
			std::cout << curr->GetData() << " ";
			curr = curr->GetNext();
		}
		std::cout << std::endl;
	}
}

#endif