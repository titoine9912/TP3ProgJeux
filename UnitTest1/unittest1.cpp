#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TP3ProgJeux/Pile.hpp"
#include "../TP3ProgJeux/file.hpp"
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
		}

		TEST_METHOD(TestMethodPile2)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(3, pile.Top());
		}

		TEST_METHOD(TestMethodPile3)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(2, pile.Top());
		}

		TEST_METHOD(TestMethodPile4)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::IsFalse(pile.isEmpty());
		}

		TEST_METHOD(TestMethodPile5)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Pop();
			Assert::IsTrue(pile.isEmpty());
		}

		TEST_METHOD(TestMethodPile6)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(2, (int)pile.Size());
		}

		TEST_METHOD(TestMethodPile7)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(1, (int)pile.Size());
		}

		TEST_METHOD(TestMethodPile8)
		{
			Pile<int> pile;
			Assert::AreEqual(0, (int)pile.Size());
		}

		TEST_METHOD(TestMethodFile1)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(4);
			Assert::AreEqual(4, file.front());
			Assert::AreEqual(3, file.back());
		}
		
		TEST_METHOD(TestMethodFile2)
		{
			File<int> file;
			file.PushFront(3);
			file.PushBack(4);
			Assert::AreEqual(3, file.front());
			Assert::AreEqual(4, file.back());
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
		}

		TEST_METHOD(TestMethodFile4)
		{
			File<int> file;
			file.PushFront(3);
			file.PushFront(2);
			file.PushBack(4);
			file.pop_front();
			file.pop_front();
			Assert::AreEqual(3, file.front());
			Assert::AreEqual(1, (int)file.Size());
		}

		TEST_METHOD(TestMethodeFile5)
		{

		}

	};
}