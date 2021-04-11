#pragma once
#include<array>

class BezierCurve
{
private:
	std::array<std::array<double, 2>, 4> controlPoints;
public:
	BezierCurve() noexcept;
	BezierCurve(std::array<double, 2> p0, std::array<double, 2> p1, std::array<double, 2> p2, std::array<double, 2> p3) noexcept;
	std::array<double, 2> getPoint(int number) noexcept;
	void setPoint(int number, std::array<double, 2> new_point);
};

