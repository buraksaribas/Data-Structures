#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "../LinkedList/Node.h"

namespace DS
{
	template <class T>
	class Queue
	{
		template <class T>
		friend void DisplayQueue(const Queue<T>& list);

	public:
		Queue() : _head(nullptr), _tail(nullptr) {}
		~Queue();
		Queue(const Queue&) = delete;
		Queue& operator=(const Queue&) = delete;

		// Adds value to Queue.
		void Enqueue(T value);
		// Removes least recently added item from Queue, returning its value.
		T Dequeue();
		// Returns true if Queue is empty.
		bool Empty() const;

	private:
		Node<T>* _head;
		Node<T>* _tail;
	};

	template <class T>
	Queue<T>::~Queue()
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
	void Queue<T>::Enqueue(T value)
	{
		if(_head == nullptr)
		{
			_head = new Node<T>(value);
			_tail = _head;
			return;
		}

		Node<T>* temp = new Node<T>(value);
		_tail->SetNext(temp);
		_tail = temp;
	}

	template <class T>
	T Queue<T>::Dequeue()
	{
		if(Empty())
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
		_head = _head->GetNext();
		value = curr->GetData();
		delete curr;

		return value;
	}

	template <class T>
	bool Queue<T>::Empty() const
	{
		return !_head;
	}

	template <class T>
	void DisplayQueue(const Queue<T>& list)
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