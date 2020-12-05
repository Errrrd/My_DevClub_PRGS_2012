#ifndef ARIPROG_H
#define ARIPROG_H

class AriProg {
	private:
		int first;
		int step;
        int total;
		int current;
        int last;

	public:
		AriProg(int, int, int);

		AriProg(int, int step=1);

		void next();

		void previous();

		void rewind();

		int value();

		int begin();

		int end();

		void operator++(int);
        
        void operator--(int);

		bool operator<(int);
        
        bool operator>(int);

        bool operator<=(int);

        bool operator>=(int);
        
        bool operator==(int);

        bool operator!=(int);

		int operator*();
};

#endif
