#include "pch.h"
#include "CppUnitTest.h"
#include "../Arrays/DynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DS;

namespace UnitTests
{
	TEST_CLASS(DynamicArrayTest)
	{
	public:

		TEST_METHOD(TestSize)
		{
			DynamicArray<int> tester(3);
			Assert::AreEqual(0, tester.GetSize());

			int ItemsToAdd = 5;
			for(int i = 0; i < ItemsToAdd; ++i)
			{
				tester.Push(i + 1);
			}

			Assert::AreEqual(ItemsToAdd, tester.GetSize());
		}

		TEST_METHOD(TestIsEmpty)
		{
			DynamicArray<int> tester(3);
			Assert::IsTrue(tester.IsEmpty());
		}

		TEST_METHOD(TestCapacity)
		{
			DynamicArray<int> tester(4);

			Assert::AreEqual(DEFAULT_CAPACITY / 2, tester.GetCapacity());

			for(int i = 0; i < 17; ++i)
			{
				tester.Push(i + 1);
			}
			Assert::AreEqual(DEFAULT_CAPACITY * 2, tester.GetCapacity());

			for(int j = 0; j < 20; ++j)
			{
				tester.Push(j + 1);
			}

			Assert::AreEqual(DEFAULT_CAPACITY * 4, tester.GetCapacity());

			for(int k = 0; k < 30; ++k)
			{
				tester.Pop();
			}

			Assert::AreEqual(DEFAULT_CAPACITY, tester.GetCapacity());


			for(int k = 0; k < 7; ++k)
			{
				tester.Pop();
			}

			Assert::AreEqual(DEFAULT_CAPACITY / 8, tester.GetCapacity());
		}

		TEST_METHOD(TestGetValueAt)
		{
			DynamicArray<int> tester(3);
			tester.Push(4);
			tester.Push(9);
			tester.Push(12);

			Assert::AreEqual(4, tester.GetValueAt(0));
			Assert::AreEqual(9, tester.GetValueAt(1));
			Assert::AreEqual(12, tester.GetValueAt(2));
		}

		TEST_METHOD(TestPop)
		{
			DynamicArray<int> tester(1);
			tester.Push(3);

			int popped = tester.Pop();
			Assert::AreEqual(3, popped);

			tester.Push(9);
			tester.Push(8);

			Assert::AreEqual(2, tester.GetSize());

			int popped2 = tester.Pop();
			Assert::AreEqual(8, popped2);
			Assert::AreEqual(1, tester.GetSize());
		}

		TEST_METHOD(TestInsert)
		{
			DynamicArray<int> tester(3);
			tester.Push(5);
			tester.Push(7);
			tester.Push(9);
			tester.Insert(0, 4);

			Assert::AreEqual(4, tester.GetValueAt(0));
			Assert::AreEqual(5, tester.GetValueAt(1));
			Assert::AreEqual(7, tester.GetValueAt(2));
			Assert::AreEqual(9, tester.GetValueAt(3));

			tester.Insert(3, 8);
			Assert::AreEqual(8, tester.GetValueAt(3));
			Assert::AreEqual(9, tester.GetValueAt(4));
		}

		TEST_METHOD(TestPrepend)
		{
			DynamicArray<int> tester(3);
			tester.Push(9);
			tester.Push(8);
			tester.Push(7);
			tester.Prepend(6);

			Assert::AreEqual(4, tester.GetSize());
			Assert::AreEqual(6, tester.GetValueAt(0));
			Assert::AreEqual(9, tester.GetValueAt(1));
			Assert::AreEqual(7, tester.GetValueAt(3));
		}

		TEST_METHOD(TestDelete)
		{
			DynamicArray<int> tester(1);
			tester.Push(5);
			tester.Delete(0);

			Assert::AreEqual(0, tester.GetSize());

			tester.Push(9);
			tester.Push(10);
			tester.Push(11);
			tester.Delete(1);

			Assert::AreEqual(2, tester.GetSize());
			Assert::AreEqual(9, tester.GetValueAt(0));
			Assert::AreEqual(11, tester.GetValueAt(1));
		}

		TEST_METHOD(TestRemove)
		{
			DynamicArray<int> tester(5);
			tester.Push(50);
			tester.Push(2);
			tester.Push(50);
			tester.Push(4);
			tester.Push(50);
			tester.Remove(50);

			Assert::AreEqual(2, tester.GetSize());
			Assert::AreEqual(2, tester.GetValueAt(0));
			Assert::AreEqual(4, tester.GetValueAt(1));
		}

		TEST_METHOD(TestFind)
		{
			DynamicArray<int> tester(3);
			tester.Push(4);
			tester.Push(7);
			tester.Push(11);
			Assert::AreEqual(-1, tester.Find(5));
			Assert::AreEqual(4, tester.Find(4));
			Assert::AreEqual(7, tester.Find(7));
			Assert::AreEqual(11, tester.Find(11));
		}
	};
}
