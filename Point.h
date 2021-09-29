#ifndef POINT_H
#define POINT_H
enum ORIENT
{
	LEFT, RIGHT, AHEAD, BEHIND, BETWEEN
};
class Triangle;
class Point
{
public:
	// Конструктор
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	// Другие методы
	void Show() const;
	void operator +=(Point&);
	Point operator +(Point&);
	Point operator -(Point&);
	double Length() const; // определяет длину вектора точки в полярной системе координат
	ORIENT Classify(Point, Point) const; // определяет положение точки относительно вектора, заданного двумя точками
	bool InTriangle(Triangle&) const; // определяет, находится ли точка внутри треугольника
public:
	double x, y;
};
#endif /* POINT_H */