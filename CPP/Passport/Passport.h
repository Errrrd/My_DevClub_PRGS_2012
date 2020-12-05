#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>

using namespace std;

class Passport {
    friend ostream& operator << (ostream&, const Passport&);

    private:
        static string series;
        static int number;
        int thisNumber;
        string strSeries;
        string firstName;
        string lastName;
        unsigned int day;
        unsigned int month;
        unsigned int year;
        
    protected:
        int changeNumber(int);
        
        static int strLen(const string&);
        
        static bool correctSeries(const string&);
        
    public:
        Passport();
        
        Passport(const string&, const string&, unsigned int, unsigned int, unsigned int);
        
        Passport(const Passport&);
        
        static void setSeries(const string&);
        
        string getSeries() const;
        
        int getNumber() const;
        
        string getFirstName() const;
        
        string getLastName() const;
        
        unsigned int getDay() const;
        
        unsigned int getMonth() const;
        
        unsigned int getYear() const;
};

ostream& operator << (ostream&, const Passport&);

#endif
