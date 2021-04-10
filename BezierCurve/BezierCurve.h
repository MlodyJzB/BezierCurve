#pragma once
#include<tuple>
using namespace std;

class BezierCurve
{
private:
	tuple <int, int> p0;
	tuple <int, int> p1;
	tuple <int, int> p2;
	tuple <int, int> p3;
public:
	BezierCurve(tuple<int, int> p0, tuple<int, int> p1, tuple<int, int> p2, tuple<int, int> p3) noexcept;
	void setPoint(int number, tuple <int, int> new_point)
};

