#include <iostream>
#include "../Arrays/DynamicArray.h"
#include "../LinkedList/LinkedList.h"

using namespace std;
int main()
{

	DS::LinkedList<int> list{};
	

	cout << 0 << " " << list.GetSize() << endl;

	list.PushBack(5);
	list.RemoveValue(5);
	cout << 0 << " " << list.GetSize() << endl;

	list.PushBack(5);
	list.PushBack(22);
	list.RemoveValue(5);

	cout << 1 << " " << list.GetSize() << endl;
	cout << 22 << " " << list.Front() << endl;

	list.PushBack(10);
	list.PushBack(20);
	list.RemoveValue(20);

	cout << 2 << " " << list.GetSize() << endl;
	cout << 10 << " " << list.Back() << endl;

	list.PushBack(10);
	list.PushBack(25);
	list.PushBack(45);

	list.RemoveValue(25);
	cout << 4 << " " << list.GetSize() << endl;
	cout << 45 << " " << list.Back() << endl;
	cout << 22 << " " << list.Front() << endl;

	std::cin.get();
	return 0;
}