#pragma once
#include<array>

class BezierCurve
{
private:
	std::array<std::array<double, 2>, 4> controlPoints;
	bool isPointEqual(int number, std::array<double, 2> const& point) const noexcept;
	bool isPointEqual(int number1, int number2) const noexcept;
public:
	BezierCurve() noexcept;
	BezierCurve(std::array<double, 2> const& p0, std::array<double, 2> const& p1, std::array<double, 2> const& p2, std::array<double, 2> const& p3) noexcept;
	std::array<double, 2> getPoint(int number) const noexcept;
	void setPoint(int number, std::array<double, 2> const& newPoint) noexcept;
	void movePoint(int number, std::array<double, 2> const& vectorAsArray) noexcept;
	void move(std::array<double, 2> const& vectorAsArray) noexcept;
	bool isClosed();
};

