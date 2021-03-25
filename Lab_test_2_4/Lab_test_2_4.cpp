#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2_4/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest24
{
	TEST_CLASS(Labtest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix A(3);
			Assert::AreEqual(A.GetN(), 3);
		}
	};
}
