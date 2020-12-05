#ifndef PRIME_H
#define PRIME_H

typedef struct {
    int it;
    int pr;
} It;

class Prime {
	private:
		int firstN;
        int lastN;
        int first;
        int last;
        
    protected:
        bool isPrime(int);
        
        int prime(int);

	public:
        It it;
        
		Prime(int);
        
        Prime(int, int);
        
        int getLast() const;
        
        int getFirst() const;

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

		int operator*();
};

#endif
