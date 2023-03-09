#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

const int DEFAULT_CAPACITY = 16;

namespace DS
{
	template <class T>
	class DynamicArray
	{
	public:
		DynamicArray();
		DynamicArray(int cap);
		~DynamicArray();

		int GetSize();
		int GetCapacity();
		bool IsEmpty();
		T GetValueAt(int index);
		void Push(T item);
		void Insert(int index, T item);
		void Prepend(T item);
		int Pop();
		void Delete(int index);
		void Remove(T item);
		int Find(T item);

	private:
		void Resize(int size);
		void Move(int capacity);

	private:
		int* _data;
		int _size;
		int _capacity;
	};

	template <class T>
	DynamicArray<T>::DynamicArray()
		: _size(0), _capacity(DEFAULT_CAPACITY)
	{
		_data = new int[_capacity];
	}

	template <class T>
	DynamicArray<T>::DynamicArray(int capacity)
		: _size(0)
	{
		int cap = DEFAULT_CAPACITY;

		while(capacity > cap / 2)
			cap *= 2;

		while(capacity * 4 <= cap)
			cap /= 2;

		_capacity = cap;

		_data = new int[_capacity];
	}

	template <class T>
	DynamicArray<T>::~DynamicArray()
	{
		delete _data;
		_data = nullptr;
	}

	template <class T>
	int DynamicArray<T>::GetSize()
	{
		return _size;
	}

	template <class T>
	int DynamicArray<T>::GetCapacity()
	{
		return _capacity;
	}


	template <class T>
	bool DynamicArray<T>::IsEmpty()
	{
		return !_size;
	}

	template <class T>
	T DynamicArray<T>::GetValueAt(int index)
	{
		if(index < 0 || index > _size)
			throw "Out of index";


		return _data[index];
	}

	template <class T>
	void DynamicArray<T>::Push(T item)
	{
		Resize(_size + 1);

		_data[_size++] = item;
	}

	template <class T>
	void DynamicArray<T>::Insert(int index, T item)
	{
		Resize(_size + 1);
		int i;
		for(i = _size; i > index; --i)
		{
			_data[i] = _data[i - 1];
		}
		_data[i] = item;
		++_size;
	}

	template <class T>
	void DynamicArray<T>::Prepend(T item)
	{
		Resize(_size + 1);
		int i;
		for(i = _size; i > 0; --i)
		{
			_data[i] = _data[i - 1];
		}
		_data[i] = item;
		++_size;
	}

	template <class T>
	int DynamicArray<T>::Pop()
	{
		Resize(_size - 1);

		return _data[--_size];
	}

	template <class T>
	void DynamicArray<T>::Delete(int index)
	{
		Resize(_size - 1);

		for(int i = index; i < _size - 1; ++i)
		{
			_data[i] = _data[i + 1];
		}

		--_size;
	}

	template <class T>
	void DynamicArray<T>::Remove(T item)
	{
		for(int i = 0; i < _size; i++)
		{
			if(_data[i] == item)
			{
				Delete(i);
				--i;
			}
		}
	}

	template <class T>
	int DynamicArray<T>::Find(T item)
	{
		for(int i = 0; i < _size; i++)
		{
			if(_data[i] == item)
				return item;
		}

		return -1;
	}

	template <class T>
	void DynamicArray<T>::Resize(int size)
	{
		if(size >= _capacity)
		{
			Move(_capacity * 2);
		}
		else if(size * 4 < _capacity)
		{
			Move(_capacity / 2);
		}
	}

	template <class T>
	void DynamicArray<T>::Move(int capacity)
	{
		int* newArr = new int[capacity];
		for(int i = 0; i < _size; ++i)
		{
			newArr[i] = _data[i];
		}
		_capacity = capacity;
		delete _data;
		_data = newArr;
	}
}

#endif