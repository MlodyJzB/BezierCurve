#pragma once
#include<tuple>

class BezierCurve
{
private:
	std::tuple <int, int> p0;
	std::tuple <int, int> p1;
	std::tuple <int, int> p2;
	std::tuple <int, int> p3;
public:
	BezierCurve();
	BezierCurve(std::tuple<int, int> p0, std::tuple<int, int> p1, std::tuple<int, int> p2, std::tuple<int, int> p3) noexcept;
	std::tuple<int, int> getPoint(int number);
	void setPoint(int number, tuple <int, int> new_point);
};

