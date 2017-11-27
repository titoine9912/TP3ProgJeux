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
	};
}