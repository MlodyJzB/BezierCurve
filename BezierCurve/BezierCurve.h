#pragma once
#include<array>

class BezierCurve
{
private:
	std::array<std::array<int, 2>, 4> controlPoints;
public:
	BezierCurve();
	BezierCurve(std::array<int, 2> p0, std::array<int, 2> p1, std::array<int, 2> p2, std::array<int, 2> p3) noexcept;
	std::array<int, 2> getPoint(int number);
	void setPoint(int number, std::array<int, 2> new_point);
};

