#ifndef GEOPROG_H
#define GEOPROG_H

typedef struct {
    int it;
    double current;
} It;

class GeoProg {
	private:
		double first;
		double step;
        int total;
        double last;

	public:
        It it;
    
		GeoProg(double, int, double);

		GeoProg(int, double step=1);

		void next();

		void previous();

		It value();

		It begin();

		It end();

		void operator++(int);
        
        void operator--(int);

		bool operator<(It);
        
        bool operator>(It);

        bool operator<=(It);

        bool operator>=(It);
        
        bool operator==(It);

        bool operator!=(It);

		double operator*();
};

#endif
