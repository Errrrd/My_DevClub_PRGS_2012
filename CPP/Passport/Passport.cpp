#include "passport.h"

int Passport::changeNumber(int num) {
    if ( num > 999999 ) {
        num = 0;
        if ( series[1] < 90 ) {
            series[1] += 1;
        } else if ( series[0] < 90 ) {
            series[0] += 1;
        } else {
            cout << "Series is overflow!!! Series set up is AA!" << endl;
            series = "AA";
        }
    }
    return num;
}

int Passport::strLen(const string& str) {
    int len = 0;

    for ( ; str[len] != 0; len++ );
    return len;
}

bool Passport::correctSeries(const string& strSeries) {
    string str = strSeries;
    
    if ( strLen(str) != 2 ) {
        cout << "Series is incorrect!!! Series is unchanged!" << endl;
        
        return 0;
    } else {
        bool isCorrect = 1;
        
        for( int i = 0; i < 2; i++ ) {
            if ( str[i] > 96 && str[i] < 123 ) {
                str[i] -= 32;
            }
            if ( str[i] < 65 || str[i] > 90 ) {
                cout << "Series is incorrect!!! Series is unchanged!" << endl;
                isCorrect = 0;
                
                return 0;
            }
        }
        if ( isCorrect ) {
            series = str;
            number = -1;
            
            return 1;
        }
    }
}

Passport::Passport() {
    number += 1;
    number = changeNumber(number);
    this->thisNumber = number;
    this->strSeries = series;
    this->firstName = "Ivanov";
    this->lastName = "Ivan";
    this->day = 1;
    this->month = 1;
    this->year = 1900;
}

Passport::Passport(const string& otherFirstName, const string& otherLastName, unsigned int otherDay, unsigned int otherMonth, unsigned int otherYear) {
    number += 1;
    number = changeNumber(number);
    this->thisNumber = number;
    this->strSeries = series;
    this->firstName = otherFirstName;
    this->lastName = otherLastName;
    this->day = otherDay;
    this->month = otherMonth;
    this->year = otherYear;
}

Passport::Passport(const Passport& other) {
    number += 1;
    number = changeNumber(number);
    this->thisNumber = number;
    this->strSeries = series;
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

void Passport::setSeries(const string& strSeries) {
    if( correctSeries(strSeries) ) {
        char yes;
        
        cout << "Set up is new number? (yes - press 'y')" << endl;
        cin >> yes;
            
        if ( yes == 89 || yes == 121 ) {
            int newNumber;
            
            cout << "Set new number (format: XXXXXX (positive integer: 1-6 figures )" << endl;
            cin >> newNumber;
            
            if( newNumber > 999999 || newNumber < -1 ) {
                cout << "Number is incorrect!!! Number set up is automatic!" << endl;
                number = -1;
            } else {
                number = newNumber - 1;
            }
        }
    }
}

string Passport::getSeries() const { return this->strSeries; }

int Passport::getNumber() const { return this->thisNumber; }

string Passport::getFirstName() const { return this->firstName; }

string Passport::getLastName() const { return this->lastName; }

unsigned int Passport::getDay() const { return this->day; }

unsigned int Passport::getMonth() const { return this->month; }

unsigned int Passport::getYear() const { return this->year; }


string Passport::series = "AA";
int Passport::number = -1;

ostream& operator << (ostream& out, const Passport& Passport) {
    int number = Passport.getNumber();
    
    out << "Passport N           " << Passport.getSeries() << " " << number / 100000 << number % 100000 / 10000 
        << number % 10000 / 1000 << number % 1000 / 100 << number % 100 / 10 << number % 10
        << "\nFirst name:          " << Passport.getFirstName()
        << "\nLast name:           " << Passport.getLastName()
        << "\nBirthday (dd.mm.yy): " << Passport.getDay() << '.' << Passport.getMonth() << '.' << Passport.getYear()
        << endl;
    
    return out;
}
