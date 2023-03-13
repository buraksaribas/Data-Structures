#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	Node() {}
	Node(T data)
		: _data(data), _next(nullptr)
	{
	}
	Node(T data, Node<T>* next) : _data(data), _next(next)
	{
	}
	Node(const Node&) = delete;
	Node& operator=(const Node&) = default;
	~Node()
	{
	}
	const T& GetData() const { return _data; }
	Node<T>* GetNext() const { return _next; }
	void SetData(const T& data) { _data = data; }
	void SetNext(Node<T>* next) { _next = next; }

private:
	T _data;
	Node<T>* _next;
};

#endif