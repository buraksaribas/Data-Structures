#include "pch.h"
#include "CppUnitTest.h"
#include "../Queue/QueueList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DS;

namespace UnitTests
{
	TEST_CLASS(QueueListTest)
	{
	public:

		TEST_METHOD(TestEmpty)
		{
			Queue<int> q;

			Assert::IsTrue(q.Empty());

			q.Enqueue(3);

			Assert::IsTrue(!q.Empty());
		}

		TEST_METHOD(TestEnqueue)
		{
			Queue<double> q;

			q.Enqueue(12.3);
			q.Enqueue(4.235);
			q.Enqueue(5.4);
			q.Enqueue(7.0);
			q.Enqueue(885314.32214);

			Assert::IsTrue(!q.Empty());
		}

		TEST_METHOD(TestDequeue)
		{
			Queue<int> q;

			q.Enqueue(100);
			q.Enqueue(200);
			Assert::AreEqual(100, q.Dequeue());

			q.Enqueue(300);
			Assert::AreEqual(200, q.Dequeue());

			q.Enqueue(400);
			q.Enqueue(500);
			q.Enqueue(600);
			q.Enqueue(700);
			Assert::AreEqual(300, q.Dequeue());
			Assert::AreEqual(400, q.Dequeue());
			Assert::AreEqual(500, q.Dequeue());
			Assert::AreEqual(600, q.Dequeue());
			Assert::AreEqual(700, q.Dequeue());

			Assert::IsTrue(q.Empty());
		}
	};
}
