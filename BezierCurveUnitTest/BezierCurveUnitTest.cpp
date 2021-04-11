#include "..\BezierCurve\BezierCurve.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::array<double, 2>>(const std::array<double, 2>& t)
{
	std::wstring result;
	result += L"{";
	for (auto& v : t)
	{
		result += ToString(v);
		result += L",";
	}
	result += L"}";
	return result;
}


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
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1,p2,p1,p2);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(1));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(0));

			double xp1 = curve.getPoint(1).at(0);
			Assert::AreEqual(xp1, double(7.5));
			double yp1 = curve.getPoint(1).at(1);
			Assert::AreEqual(yp1, double(22.08));

			double xp2 = curve.getPoint(2).at(0);
			Assert::AreEqual(xp2, double(1));
			double yp2 = curve.getPoint(2).at(1);
			Assert::AreEqual(yp2, double(0));

			double xp3 = curve.getPoint(3).at(0);
			Assert::AreEqual(xp3, double(7.5));
			double yp3 = curve.getPoint(3).at(1);
			Assert::AreEqual(yp3, double(22.08));
		}

		TEST_METHOD(TestEmptyBezierSetPointInt)
		{
			BezierCurve curve;
			
			std::array<double, 2> new_p0 = { {0,1} };
			curve.setPoint(0, new_p0);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(0));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(1));
		}

		TEST_METHOD(TestEmptyBezierSetPointDouble)
		{
			BezierCurve curve;

			std::array<double, 2> new_p0 = { {22.1,15.552} };
			curve.setPoint(0, new_p0);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(22.1));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(15.552));
		}

		TEST_METHOD(TestBezierAllSetPointDouble)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p1, p2);

			std::array<double, 2> new_p0 = { {22.1,15.552} };
			curve.setPoint(0, new_p0);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(22.1));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(15.552));

			std::array<double, 2> new_p1 = { {2.1,1.552} };
			curve.setPoint(1, new_p1);
			double xp1 = curve.getPoint(1).at(0);
			Assert::AreEqual(xp1, double(2.1));
			double yp1 = curve.getPoint(1).at(1);
			Assert::AreEqual(yp1, double(1.552));

			std::array<double, 2> new_p2 = { {12.1,11.552} };
			curve.setPoint(2, new_p2);
			double xp2 = curve.getPoint(2).at(0);
			Assert::AreEqual(xp2, double(12.1));
			double yp2 = curve.getPoint(2).at(1);
			Assert::AreEqual(yp2, double(11.552));

			std::array<double, 2> new_p3 = { {112.1,111.552} };
			curve.setPoint(3, new_p3);
			double xp3 = curve.getPoint(3).at(0);
			Assert::AreEqual(xp3, double(112.1));
			double yp3 = curve.getPoint(3).at(1);
			Assert::AreEqual(yp3, double(111.552));
		}

		TEST_METHOD(TestEmptyBezierMovePointInt)
		{
			BezierCurve curve;

			std::array<double, 2> vector = { {0,1} };
			curve.movePoint(0, vector);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(0));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(1));
		}

		TEST_METHOD(TestBezierMovePointInt)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p1, p2);

			std::array<double, 2> vector = { {0,1} };
			curve.movePoint(0, vector);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(1));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(1));
		}

		TEST_METHOD(TestBezierMovePointDouble)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p1, p2);

			std::array<double, 2> vector = { {2.75,1.21} };
			curve.movePoint(0, vector);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(3.75));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(1.21));
		}

		TEST_METHOD(TestBezierAllMovePointDouble)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p2, p1);

			std::array<double, 2> vector1 = { {2.75,1.21} };
			curve.movePoint(0, vector1);
			double xp0 = curve.getPoint(0).at(0);
			Assert::AreEqual(xp0, double(3.75));
			double yp0 = curve.getPoint(0).at(1);
			Assert::AreEqual(yp0, double(1.21));

			std::array<double, 2> vector2 = { {0.75,2.21} };
			curve.movePoint(1, vector2);
			double xp1 = curve.getPoint(1).at(0);
			Assert::AreEqual(xp1, double(8.25));
			double yp1 = curve.getPoint(1).at(1);
			Assert::AreEqual(yp1, double(24.29));

			std::array<double, 2> vector3 = { {0.651,2.212222} };
			curve.movePoint(2, vector3);
			double xp2 = curve.getPoint(2).at(0);
			Assert::AreEqual(xp2, double(8.151));
			double yp2 = curve.getPoint(2).at(1);
			Assert::AreEqual(yp2, double(24.292222));

			std::array<double, 2> vector4 = { {2.05,111.21567} };
			curve.movePoint(3, vector4);
			double xp3 = curve.getPoint(3).at(0);
			Assert::AreEqual(xp3, double(3.05));
			double yp3 = curve.getPoint(3).at(1);
			Assert::AreEqual(yp3, double(111.21567));
		}

		TEST_METHOD(TestEmptyBezierMove)
		{
			BezierCurve curve;

			std::array<double, 2> vector = { {2.22,1} };

			curve.move(vector);

			std::array<double, 2> expected_p0 = { {2.22,1} };
			std::array<double, 2> expected_p1 = { {2.22,1} };
			std::array<double, 2> expected_p2 = { {2.22,1} };
			std::array<double, 2> expected_p3 = { {2.22,1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}

		TEST_METHOD(TestBezierMove)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p2, p1);

			std::array<double, 2> vector = { {2.22,1} };

			curve.move(vector);

			std::array<double, 2> expected_p0 = { {3.22,1} };
			std::array<double, 2> expected_p1 = { {9.72,23.08} };
			std::array<double, 2> expected_p2 = { {9.72,23.08} };
			std::array<double, 2> expected_p3 = { {3.22,1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}
		TEST_METHOD(TestBezierIsClosedTrue)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p2, p1);
			
			Assert::IsTrue(curve.isClosed());
		}

		TEST_METHOD(TestBezierIsClosedFalse)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p1, p2);

			Assert::IsFalse(curve.isClosed());
		}

		TEST_METHOD(TestBezierIsEqualTrue)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p1, p2);

			Assert::IsTrue(curve1.isEqual(curve2));
			Assert::IsTrue(curve2.isEqual(curve1));
		}

		TEST_METHOD(TestBezierIsEqualFalse)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p2, p1);

			Assert::IsFalse(curve1.isEqual(curve2));
			Assert::IsFalse(curve2.isEqual(curve1));
		}

		TEST_METHOD(TestEmptyBezierOperatorPlus)
		{
			BezierCurve curve;

			std::array<double, 2> vector = { {2.22,1} };

			curve += vector;

			std::array<double, 2> expected_p0 = { {2.22,1} };
			std::array<double, 2> expected_p1 = { {2.22,1} };
			std::array<double, 2> expected_p2 = { {2.22,1} };
			std::array<double, 2> expected_p3 = { {2.22,1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}

		TEST_METHOD(TestBezierOperatorPlus)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p2, p1);

			std::array<double, 2> vector = { {2.22,1} };

			curve += vector;

			std::array<double, 2> expected_p0 = { {3.22,1} };
			std::array<double, 2> expected_p1 = { {9.72,23.08} };
			std::array<double, 2> expected_p2 = { {9.72,23.08} };
			std::array<double, 2> expected_p3 = { {3.22,1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}

		TEST_METHOD(TestEmptyBezierOperatorMinus)
		{
			BezierCurve curve;

			std::array<double, 2> vector = { {2.22,1} };

			curve -= vector;

			std::array<double, 2> expected_p0 = { {-2.22,-1} };
			std::array<double, 2> expected_p1 = { {-2.22,-1} };
			std::array<double, 2> expected_p2 = { {-2.22,-1} };
			std::array<double, 2> expected_p3 = { {-2.22,-1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}

		TEST_METHOD(TestBezierOperatorMinus)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve(p1, p2, p2, p1);

			std::array<double, 2> vector = { {2.22,1} };

			curve -= vector;

			std::array<double, 2> expected_p0 = { {-1.22,-1} };
			std::array<double, 2> expected_p1 = { {5.28,21.08} };
			std::array<double, 2> expected_p2 = { {5.28,21.08} };
			std::array<double, 2> expected_p3 = { {-1.22,-1} };

			Assert::AreEqual(curve.getPoint(0), expected_p0);
			Assert::AreEqual(curve.getPoint(1), expected_p1);
			Assert::AreEqual(curve.getPoint(2), expected_p2);
			Assert::AreEqual(curve.getPoint(3), expected_p3);
		}

		TEST_METHOD(TestBezierOperatorEqualTrue)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p1, p2);

			Assert::IsTrue(curve1 == curve2);
			Assert::IsTrue(curve2 == curve1);
		}

		TEST_METHOD(TestBezierOperatorEqualFalse)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p2, p1);

			Assert::IsFalse(curve1 == curve2);
			Assert::IsFalse(curve2 == curve1);
		}

		TEST_METHOD(TestBezierOperatorNotEqualTrue)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p2, p1);

			Assert::IsTrue(curve1 != curve2);
			Assert::IsTrue(curve2 != curve1);
		}

		TEST_METHOD(TestBezierOperatorNotEqualFalse)
		{
			std::array<double, 2> p1 = { {1,0} };
			std::array<double, 2> p2 = { {7.5, 22.08} };
			BezierCurve curve1(p1, p2, p1, p2);
			BezierCurve curve2(p1, p2, p1, p2);

			Assert::IsFalse(curve1 != curve2);
			Assert::IsFalse(curve2 != curve1);
		}


	};
}
