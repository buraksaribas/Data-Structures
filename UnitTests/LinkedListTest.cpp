#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DS;

namespace UnitTests
{
	TEST_CLASS(LinkedListTest)
	{
	public:

		TEST_METHOD(TestSize)
		{
			LinkedList<int> list{};
			Assert::AreEqual(0, list.GetSize());

			list.PushFront(4);
			Assert::AreEqual(1, list.GetSize());

			list.PushFront(9);
			Assert::AreEqual(2, list.GetSize());
		}

		TEST_METHOD(TestEmpty)
		{
			LinkedList<std::string> list{};
			Assert::IsTrue(list.IsEmpty());

			list.PushFront("word");
			Assert::IsFalse(list.IsEmpty());
		}

		TEST_METHOD(TestValueAt)
		{
			LinkedList<int> list{};

			list.PushFront(99);
			Assert::AreEqual(99, list.ValueAt(1));

			list.PushFront(3);
			list.PushFront(122);
			Assert::AreEqual(122, list.ValueAt(1));
			Assert::AreEqual(3, list.ValueAt(2));
			Assert::AreEqual(99, list.ValueAt(3));
		}

		TEST_METHOD(TestPopFront)
		{
			LinkedList<int> list{};

			list.PushFront(66);
			Assert::AreEqual(66, list.PopFront());

			list.PushFront(12);
			list.PushFront(11);

			Assert::AreEqual(11, list.PopFront());
			Assert::AreEqual(12, list.PopFront());
		}

		TEST_METHOD(TestPushBack)
		{
			LinkedList<int> list{};

			list.PushBack(4);
			Assert::AreEqual(1, list.GetSize());

			list.PushBack(123);
			list.PushBack(456);

			Assert::AreEqual(3, list.GetSize());
			Assert::AreEqual(123, list.ValueAt(2));
			Assert::AreEqual(456, list.ValueAt(3));
		}

		TEST_METHOD(TestPopBack)
		{
			LinkedList<int> list{};

			list.PushBack(4);
			int val = list.PopBack();

			Assert::AreEqual(0, list.GetSize());
			Assert::AreEqual(4, val);

			list.PushBack(33);
			list.PushBack(36);
			Assert::AreEqual(36, list.PopBack());
			Assert::AreEqual(33, list.PopBack());
			Assert::AreEqual(0, list.GetSize());
		}

		TEST_METHOD(TestFront)
		{
			LinkedList<int> list{};

			list.PushFront(123);
			Assert::AreEqual(123, list.Front());

			list.PushFront(456);
			Assert::AreEqual(456, list.Front());
			Assert::AreEqual(123, list.Back());
		}

		TEST_METHOD(TestBack)
		{
			LinkedList<int> list{};

			list.PushBack(3);
			Assert::AreEqual(3, list.Back());

			list.PushBack(123);
			list.PushBack(456);
			Assert::AreEqual(list.Back(), 456);
		}

		TEST_METHOD(TestInsert)
		{
			LinkedList<int> list{};

			list.Insert(1, 3);

			Assert::AreEqual(3, list.Front());

			list.PushFront(123);
			list.Insert(1, 6);

			Assert::AreEqual(6, list.Front());
			Assert::AreEqual(3, list.Back());


			list.PushBack(423);
			list.Insert(2, 33);

			Assert::AreEqual(423, list.Back());

			list.PushBack(123);
			list.PushBack(456);
			list.PushBack(999);
			list.Insert(7, 777);

			Assert::AreEqual(777, list.ValueAt(7));
			Assert::AreEqual(456, list.ValueAt(8));
			Assert::AreEqual(999, list.Back());
		}

		TEST_METHOD(TestErase)
		{
			LinkedList<int> list{};

			list.PushBack(44);
			list.Erase(1);

			Assert::AreEqual(0, list.GetSize());

			list.PushBack(44);
			list.PushBack(55);
			list.Erase(1);

			Assert::AreEqual(1, list.GetSize());
			Assert::AreEqual(55, list.Front());

			list.PushBack(66);
			list.PushBack(77);
			list.Erase(2);

			Assert::AreEqual(2, list.GetSize());
			Assert::AreEqual(55, list.Front());

			list.PushBack(144);
			list.PushBack(155);
			list.PushBack(166);
			list.Erase(2);

			Assert::AreEqual(4, list.GetSize());
			Assert::AreEqual(55, list.Front());
			Assert::AreEqual(166, list.Back());
		}

		TEST_METHOD(TestValueNFromEnd)
		{
			LinkedList<int> list{};

			list.PushBack(33);
			Assert::AreEqual(33, list.ValueNFromEnd(1));

			list.PushBack(44);
			list.PushBack(55);
			list.PushBack(66);
			Assert::AreEqual(66, list.ValueNFromEnd(1));
			Assert::AreEqual(55, list.ValueNFromEnd(2));
			Assert::AreEqual(44, list.ValueNFromEnd(3));
		}

		TEST_METHOD(TestReverse)
		{
			LinkedList<int> list{};

			list.PushBack(44);

			list.Reverse();

			Assert::AreEqual(44, list.Front());

			list.PushBack(55);
			list.PushBack(66);

			list.Reverse();

			Assert::AreEqual(66, list.Front());
			Assert::AreEqual(44, list.Back());


			list.PushBack(144);
			list.PushBack(155);
			list.PushBack(166);

			list.Reverse();

			Assert::AreEqual(166, list.ValueAt(1));
			Assert::AreEqual(155, list.ValueAt(2));
		}

		TEST_METHOD(TestRemoveValue)
		{
			LinkedList<int> list{};

			Assert::AreEqual(0, list.GetSize());

			list.PushBack(5);
			list.RemoveValue(5);

			Assert::AreEqual(0, list.GetSize());

			list.PushBack(5);
			list.PushBack(22);
			list.RemoveValue(5);

			Assert::AreEqual(1, list.GetSize());
			Assert::AreEqual(22, list.Front());

			list.PushBack(10);
			list.PushBack(20);
			list.RemoveValue(20);

			Assert::AreEqual(2, list.GetSize());
			Assert::AreEqual(10, list.Back());

			list.PushBack(10);
			list.PushBack(25);
			list.PushBack(45);

			list.RemoveValue(25);

			Assert::AreEqual(4, list.GetSize());
			Assert::AreEqual(22, list.Front());
			Assert::AreEqual(45, list.Back());
		}
	};
}
