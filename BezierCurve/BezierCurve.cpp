#include "BezierCurve.h"
using namespace std;

BezierCurve::BezierCurve() {
	controlPoints = {{ {0, 0}, {0, 0}, {0, 0}, {0, 0} }};
}

BezierCurve::BezierCurve(std::array<int, 2> p0, std::array<int, 2> p1, std::array<int, 2> p2, std::array<int, 2> p3) {
	controlPoints = { { p0, p1, p2, p3 } };
}

array<int, 2> BezierCurve::getPoint(int number) {
	return controlPoints[number];

}