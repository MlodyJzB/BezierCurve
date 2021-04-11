#include "..\BezierCurve\BezierCurve.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BezierCurveUnitTest
{
	TEST_CLASS(BezierCurveUnitTest)
	{
	public:
		
		TEST_METHOD(TestBezierEmptyInit)
		{
			std::array<double, 2> p = { {0,0} };
			BezierCurve curve;
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(0));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(0));

			double xp1 = curve.getPoint(1).at(0);
			Assert::AreEqual(xp1, double(0));
			double yp1 = curve.getPoint(1).at(1);
			Assert::AreEqual(yp1, double(0));

			double xp2 = curve.getPoint(2).at(0);
			Assert::AreEqual(xp2, double(0));
			double yp2 = curve.getPoint(2).at(1);
			Assert::AreEqual(yp2, double(0));

			double xp3 = curve.getPoint(3).at(0);
			Assert::AreEqual(xp3, double(0));
			double yp3 = curve.getPoint(3).at(1);
			Assert::AreEqual(yp3, double(0));
		}

		TEST_METHOD(TestBezierPointsInit)
		{
			std::array<double, 2> p = { {1,0} };
			std::array<double, 2> p = { {7.5, 22.08} };
			BezierCurve curve;
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(0));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(0));

			double xp1 = curve.getPoint(1).at(0);
			Assert::AreEqual(xp1, double(0));
			double yp1 = curve.getPoint(1).at(1);
			Assert::AreEqual(yp1, double(0));

			double xp2 = curve.getPoint(2).at(0);
			Assert::AreEqual(xp2, double(0));
			double yp2 = curve.getPoint(2).at(1);
			Assert::AreEqual(yp2, double(0));

			double xp3 = curve.getPoint(3).at(0);
			Assert::AreEqual(xp3, double(0));
			double yp3 = curve.getPoint(3).at(1);
			Assert::AreEqual(yp3, double(0));
		}

	};
}
