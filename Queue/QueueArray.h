#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

namespace DS
{
	template <class T>
	class Queue
	{
		template <class T>
		friend void DisplayQueue(const Queue<T>& list);

		static const int defaultCap;

	public:
		Queue() : _capacity(defaultCap), _data(new T[_capacity]), _push(-1), _pop(-1){}
		Queue(const int capacity) : _capacity(capacity), _data(new T[_capacity]), _push(-1), _pop(-1){}
		~Queue();
		Queue(const Queue&) = delete;
		Queue& operator=(const Queue&) = delete;
		// Adds value to queue.
		void Enqueue(T value);
		// Removes least recently added item from queue, returning its value.
		const T Dequeue();
		// Returns true if queue is empty.
		bool Empty() const;
		// Returns true if queue cannot accept another enqueue.
		bool Full() const;

	private:
		int _pop;
		int _push;
		const int _capacity;
		T* _data;
	};

	template <class T>
	const int Queue<T>::defaultCap = 6;

	template <class T>
	Queue<T>::~Queue()
	{
		delete[] _data;
		_data = nullptr;
	}

	template <class T>
	void Queue<T>::Enqueue(T value)
	{
		if(Full())
			throw "Queue is full";

		_push++;
		if(_push == _capacity)
			_push = 0;

		_data[_push] = value;
	}

	template <class T>
	const T Queue<T>::Dequeue()
	{
		if(Empty())
			throw "List is empty";
		
		_pop++;
		if(_pop == _capacity)
			_pop = 0;

		return _data[_pop];
	}

	template <class T>
	bool Queue<T>::Empty() const
	{
		return _push == -1 || (_push == _pop && !Full());
	}

	template <class T>
	bool Queue<T>::Full() const
	{
		return (_push + 1 == _capacity && _pop == -1) || (_pop == _push && _pop != -1);
	}

	template <class T>
	void DisplayQueue(const Queue<T>& list)
	{
		for(int i = 0; i < list._capacity; ++i)
		{
			std::cout << list._data[i] << " ";
		}
		std::cout << std::endl;
	}
}

#endif