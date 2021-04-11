#include "..\BezierCurve\BezierCurve.h"
#include<array>

BezierCurve::BezierCurve() noexcept {
	controlPoints = {{ {0, 0}, {0, 0}, {0, 0}, {0, 0} }};
}

BezierCurve::BezierCurve(std::array<double, 2> p0, std::array<double, 2> p1, std::array<double, 2> p2, std::array<double, 2> p3) noexcept {
	controlPoints = { { p0, p1, p2, p3 } };
}

std::array<double, 2> BezierCurve::getPoint(int number) noexcept {
	return controlPoints[number];
}

void BezierCurve::setPoint(int number, std::array<double, 2> new_point) {
	controlPoints.at(number) = new_point;
}