#ifndef FIBONACCI_H
#define FIBONACCI_H

typedef struct {
    int it;
    long long fib;
} It;

class Fibonacci {
	private:
		int firstN;
        int lastN;
        int first;
        int last;
        
    protected:
        long long fibonacci(int n);

	public:
        It it;
    
		Fibonacci(int lastN=1);
        
        Fibonacci(int firstN, int lastN);

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

		long long operator*();
};

#endif
