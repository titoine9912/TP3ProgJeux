#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TP3ProgJeux/Pile.hpp"
#include "../TP3ProgJeux/file.hpp"
#include "../TP3ProgJeux//liste.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{

	public:
		TEST_METHOD(TestMethodPile1)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			Assert::AreEqual(2, pile.Top());	
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile2)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(3, pile.Top());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile3)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(2, pile.Top());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile4)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::IsFalse(pile.isEmpty());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile5)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Pop();
			Assert::IsTrue(pile.isEmpty());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile6)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(2, (int)pile.Size());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile7)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(1, (int)pile.Size());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodPile8)
		{
			Pile<int> pile;
			Assert::AreEqual(0, (int)pile.Size());
			pile.~Pile();
		}

		TEST_METHOD(TestMethodFile1)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(4);
			Assert::AreEqual(4, file.front());
			Assert::AreEqual(3, file.back());
			file.~File();
		}
		
		TEST_METHOD(TestMethodFile2)
		{
			File<int> file;
			file.PushFront(3);
			file.PushBack(4);
			Assert::AreEqual(3, file.front());
			Assert::AreEqual(4, file.back());
			file.~File();
		}

		TEST_METHOD(TestMethodFile3)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(2);
			file.PushBack(4);
			file.pop_back();
			Assert::AreEqual(3, file.back());
			Assert::AreEqual(2, (int)file.Size());
			file.~File();
		}

		TEST_METHOD(TestMethodFile4)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(2);
			file.PushBack(4);
			file.pop_front();
			file.pop_front();
			Assert::AreEqual(4, file.front());
			Assert::AreEqual(1, (int)file.Size());
			file.~File();
		}

		TEST_METHOD(TestMethodeFile5)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(2);
			file.PushFront(1);
			file.PushFront(0);
			file.PushBack(4);
			file.pop_front();
			file.pop_back();
			Assert::AreEqual(1, file.front());
			Assert::AreEqual(3, file.back());
			Assert::AreEqual(3, (int)file.Size());
			file.~File();
		}

		TEST_METHOD(TestMethodeFile6)
		{
			File<int> file;
			file.PushFront(4);
			file.PushFront(3);
			file.PushBack(5);
			file.PushBack(6);
			Assert::AreEqual(3, file.at(0));
			Assert::AreEqual(4, file.at(1));
			Assert::AreEqual(5, file.at(2));
			Assert::AreEqual(6, file.at(3));
			file.~File();
		}

		TEST_METHOD(TestMethodeFile7)
		{
			File<int> file;
			file.PushFront(2);
			file.PushFront(3);
			file.PushBack(1);
			file.pop_front();
			file.pop_front();
			file.pop_back();
			Assert::IsTrue(file.isEmpty());
			file.~File();
		}

		TEST_METHOD(TestMethodeFile8)
		{
			File<int> file;
			file.PushFront(2);
			file.PushFront(3);
			file.PushBack(1);
			file.pop_front();
			file.pop_front();
			Assert::IsFalse(file.isEmpty());
			file.~File();
		}

		TEST_METHOD(TestMethodeFile9)
		{
			File<int> file;
			file.PushFront(2);
			file.PushFront(3);
			file.PushBack(1);
			file.clear();
			Assert::IsTrue(file.isEmpty());
			file.~File();
		}

		TEST_METHOD(TestMethodeList1)
		{
			Liste<int> list;
			list.push_back(2);
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(2, list.back());
			list.~Liste();
		}

		TEST_METHOD(TestMethodeList2)
		{
			Liste<int> list;
			list.push_back(2);
			list.push_front(3);
			Assert::AreEqual(3, list.front());
			Assert::AreEqual(2, list.back());
			list.~Liste();
		}

		TEST_METHOD(TestMethodeList3)
		{
			Liste<int> list;
			list.push_back(4);
			list.push_front(3);
			list.push_front(2);
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(4, list.back());
			Assert::AreEqual(3, (int)list.size());
			list.~Liste();
		}

		TEST_METHOD(TestMethodeList4)
		{
			Liste<int> list1;
			Liste<int> list2;
			list1.push_front(2);
			list1.push_front(3);
			list2.push_front(5);
			list2.push_front(6);
			list1.swap(list2);
			Assert::AreEqual(6, list1.front());
			Assert::AreEqual(5, list1.back());
			Assert::AreEqual(3, list2.front());
			Assert::AreEqual(2, list2.back());
			list1.~Liste();
			list2.~Liste();
		}


		TEST_METHOD(TestMethodeList5)
		{
			Liste<int> list;
			list.push_back(2);
			list.push_front(3);
			list.pop_back();
			Assert::AreEqual(3, list.front());
			Assert::AreEqual(3, list.back());
			list.~Liste();
		}

		TEST_METHOD(TestMethodeList6)
		{
			Liste<int> list;
			list.push_back(4);
			list.push_front(3);
			list.push_front(2);
			list.push_front(1);
			list.pop_back();
			list.pop_front();
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(3, list.back());
			Assert::AreEqual(2, (int)list.size());
			list.~Liste();
		}

		TEST_METHOD(TestMethodeList7)
		{
			Liste<int> list;
			list.Insert(list.begin(),2);
			Assert::AreEqual(2, list.front());
			Assert::AreEqual(2, list.back());
			list.~Liste();
		}

		/*TEST_METHOD(TestMethodeList9)
		{
			Liste<int> list;
			Liste<int> list2;
			int element[5] = { 1,4,3,2 };
			auto pos = list.begin();
			auto iter = list.begin();
			for (int i = 0; i < 2; ++i)
			{
				pos++;
			}
			for (int i = 0; i < 4; ++i)
			{
				iter++;
			}
			list.push_front(1);
			list.push_back(4);
			list2.push_front(3);
			list2.push_front(2);
			list.splice(pos, list2);
			
			//Assert::IsTrue(iter == list.end());
		}
		*/
	};
}