#include <iostream>
#include "../Arrays/DynamicArray.h"
#include "../LinkedList/LinkedList.h"
#include "../Queue/QueueArray.h"

using namespace std;
using namespace DS;

int main()
{
	Queue<double> q;

	q.Enqueue(12.3);
	q.Enqueue(4.235);
	q.Enqueue(5.4);
	q.Enqueue(7.0);
	q.Enqueue(7.9);
	q.Enqueue(885314.32214);
	DisplayQueue(q);

	q.Dequeue();
	q.Enqueue(7.9);

	DisplayQueue(q);
	cout << !q.Empty() << endl;


	std::cin.get();
	return 0;
}