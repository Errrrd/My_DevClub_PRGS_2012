#ifndef GEOPROG_H
#define GEOPROG_H

class GeoProg {
	private:
		double first;
		double step;
        int total;
		double current;
        double last;

	public:
		GeoProg(double, int, double);

		GeoProg(int, double step=1);

		void next();

		void previous();

		void rewind();

		int value();

		int begin();

		int end();

		void operator++(int);

		bool operator<(int);

		int operator*();
};

#endif
