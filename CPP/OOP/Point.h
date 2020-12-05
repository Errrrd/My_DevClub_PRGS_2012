#ifndef POINT_H
#define POINT_H

class Point {
	friend std::ostream& operator<<(std::ostream&, const Point&);

	private:
		double x, y;

	public:
		Point();
		Point(double x, double y);

		double getDistance(const Point&) const;

		double getX() const;
		double getY() const;

		bool operator==(const Point&) const;
		bool operator!=(const Point&) const;
};

std::ostream& operator<<(std::ostream&, const Point&);

#endif
