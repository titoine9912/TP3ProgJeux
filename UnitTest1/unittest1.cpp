#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TP3ProgJeux/Pile.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			Assert::AreEqual(2, pile.Top());			
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(3, pile.Top());
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(2, pile.Top());
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::IsFalse(pile.isEmpty());
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Pop();
			Assert::IsTrue(pile.isEmpty());
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			Assert::AreEqual(2, (int)pile.Size());
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: Ici, votre code de test
			Pile<int> pile;
			pile.Push(2);
			pile.Push(3);
			pile.Pop();
			Assert::AreEqual(1, (int)pile.Size());
		}

		TEST_METHOD(TestMethod8)
		{
			Pile<int> pile;
			Assert::AreEqual(0, (int)pile.Size());
		}
	};
}