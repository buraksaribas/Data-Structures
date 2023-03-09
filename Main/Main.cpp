#include <iostream>
#include "../Arrays/DynamicArray.h"

int main()
{

	DS::DynamicArray<int> da(4);

	da.Push(3);
	std::cout << da.Pop();

	std::cin.get();
	return 0;
}