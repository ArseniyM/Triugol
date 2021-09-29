#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include <math.h>
using namespace std;
void Point::Show() const
{
	cout << " (" << x << "," << y << ")";
}
void Point::operator +=(Point& p)
{
	x += p.x; y += p.y;
}
Point Point::operator +(Point& p)
{
	return Point(x + p.x, y + p.y);
}
Point Point::operator -(Point& p)
{
	return Point(x - p.x, y - p.y);
}
double Point::Length() const
{
	return sqrt(x * x + y * y);
}
ORIENT Point::Classify(Point beg_p, Point end_p) const
{
	Point p0 = *this; Point a = end_p - beg_p; Point b = p0 - beg_p; double sa = a.x * b.y - b.x * a.y;
	if (sa > 0.0) return LEFT;
	if (sa < 0.0) return RIGHT;
	if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND;
	if (a.Length() < b.Length()) return AHEAD;
	return BETWEEN;
}
bool Point::InTriangle(Triangle& tria) const
{
	ORIENT or1 = Classify(tria.Get_v1(), tria.Get_v2());
	ORIENT or2 = Classify(tria.Get_v2(), tria.Get_v3());
	ORIENT îr3 = Classify(tria.Get_v3(), tria.Get_v1());
	if ((or1 == RIGHT || or1 == BETWEEN)
		&& (or2 == RIGHT || or2 == BETWEEN)
		&& (îr3 == RIGHT || îr3 == BETWEEN)) return true;
	else return false;
}
