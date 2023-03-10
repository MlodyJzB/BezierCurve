#include "..\BezierCurve\BezierCurve.h"
#include<array>

BezierCurve::BezierCurve() noexcept {
	controlPoints = {{ {0, 0}, {0, 0}, {0, 0}, {0, 0} }};
}

BezierCurve::BezierCurve(std::array<double, 2> const& p0, std::array<double, 2> const& p1, std::array<double, 2> const& p2, std::array<double, 2> const& p3) noexcept {
	controlPoints = { { p0, p1, p2, p3 } };
}

std::array<double, 2> BezierCurve::getPoint(int number) const noexcept {
	return controlPoints[number];
}

void BezierCurve::setPoint(int number, std::array<double, 2> const& newPoint) noexcept{
	controlPoints.at(number) = newPoint;
}

void BezierCurve::movePoint(int number, std::array<double, 2> const& vectorAsArray) noexcept {
	controlPoints.at(number).at(0) += vectorAsArray.at(0);
	controlPoints.at(number).at(1) += vectorAsArray.at(1);
}

void BezierCurve::move(std::array<double, 2> const& vectorAsArray) noexcept {
	movePoint(0, vectorAsArray);
	movePoint(1, vectorAsArray);
	movePoint(2, vectorAsArray);
	movePoint(3, vectorAsArray);
}

bool BezierCurve::isPointEqual(int number, std::array<double, 2> const& point) const noexcept {
	return ((controlPoints.at(number).at(0) == point.at(0)) && (controlPoints.at(number).at(1) == point.at(1)));
}

bool BezierCurve::isPointEqual(int number1, int number2) const noexcept {
	return ((controlPoints.at(number1).at(0) == controlPoints.at(number2).at(0))) && (controlPoints.at(number1).at(1) == controlPoints.at(number2).at(1));
}

bool BezierCurve::isClosed() const noexcept {
	return isPointEqual(0, 3);
}

bool BezierCurve::isEqual(BezierCurve const& curve2) const noexcept {
	return (isPointEqual(0, curve2.getPoint(0)) && isPointEqual(1, curve2.getPoint(1)) && isPointEqual(2, curve2.getPoint(2)) && isPointEqual(3, curve2.getPoint(3)));
}

std::array<double, 2> BezierCurve::curvePos(double t) const noexcept {
	double x;
	double y;
	x = (1 - t) * (1 - t) * (1 - t) * getPoint(0).at(0) + 3 * (1 - t) * (1 - t) * t * getPoint(1).at(0) + 3 * (1 - t) * t * t * getPoint(2).at(0) + t * t * t * getPoint(3).at(0);
	y = (1 - t) * (1 - t) * (1 - t) * getPoint(0).at(1) + 3 * (1 - t) * (1 - t) * t * getPoint(1).at(1) + 3 * (1 - t) * t * t * getPoint(2).at(1) + t * t * t * getPoint(3).at(1);
	std::array<double, 2> pointPos = { {x,y} };
}

void BezierCurve::operator+=(std::array<double, 2> const& vectorAsArray) noexcept {
	move(vectorAsArray);
}

void BezierCurve::operator-=(std::array<double, 2> const& vectorAsArray) noexcept {
	std::array<double, 2> reverseVector;
	reverseVector.at(0) = -1 * (vectorAsArray.at(0));
	reverseVector.at(1) = -1 * (vectorAsArray.at(1));
	move(reverseVector);
}

bool BezierCurve::operator==(BezierCurve const& curve2) const noexcept {
	return isEqual(curve2);
}

bool BezierCurve::operator!=(BezierCurve const& curve2) const noexcept {
	return !isEqual(curve2);
}

