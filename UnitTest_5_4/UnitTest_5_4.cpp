#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab54
{
    TEST_CLASS(UnitTestLab54)
    {
    public:

        TEST_METHOD(TestMethod_Term)
        {
            int j = 2;
            int N = 4;
            double expected = 0.5;
            double actual = term(j, N);

            Assert::AreEqual(expected, actual, 0.00001);
        }

        TEST_METHOD(TestMethod_SumMethods)
        {
            const int K = 2;
            int N = 4;
            double expected = 0.8;

            double s0 = S0(K, N);
            double s1 = S1(K, N, N, 0);
            double s2 = S2(K, N, K, 0);
            double s3 = S3(K, N, N);
            double s4 = S4(K, N, K);

            Assert::AreEqual(expected, s0, 0.00001);
            Assert::AreEqual(expected, s1, 0.00001);
            Assert::AreEqual(expected, s2, 0.00001);
            Assert::AreEqual(expected, s3, 0.00001);
            Assert::AreEqual(expected, s4, 0.00001);
        }
    };
}