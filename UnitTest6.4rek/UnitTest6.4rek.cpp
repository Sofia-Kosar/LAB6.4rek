#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6.4pek/LAB6.4pek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rek
{
	TEST_CLASS(UnitTest64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 2, 109, -88, 4, 5, 34 };
			int n = 6;

			double z = MinR(a, n);
			Assert::AreEqual(z, 4.0);
		}
	};
}
