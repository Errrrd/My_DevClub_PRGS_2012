#ifndef FACTORIAL_H
#define FACTORIAL_H

typedef struct {
    int it;
    unsigned long long fact;
} It;

class Factorial {
	private:
		int firstN;
        int lastN;
        int first;
        int last;
        
    protected:
        unsigned long long factorial(unsigned int);

	public:
        It it;
        
		Factorial(unsigned int lN=1);
        
        Factorial(unsigned int, unsigned int);

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

		unsigned long long operator*();
};

#endif
