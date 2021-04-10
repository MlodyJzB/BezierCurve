#include "BezierCurve.h"
using namespace std;

BezierCurve::BezierCurve() {
	p0 = make_tuple(0, 0);
	p1 = make_tuple(0, 0);
	p2 = make_tuple(0, 0);
	p3 = make_tuple(0, 0);
}

BezierCurve::BezierCurve(std::tuple<int, int> p0, std::tuple<int, int> p1, std::tuple<int, int> p2, std::tuple<int, int> p3) {
	this->p0 = p0;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

