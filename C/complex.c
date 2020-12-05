#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} Complex;

void complexIncrement(Complex *this, Complex other) {
    this->re += other.re;
    this->im += other.im;
}

void complexDecrement(Complex *this, Complex other) {
    this->re -= other.re;
    this->im -= other.im;
}

// void complexMultiply(Complex *this, Complex other) {
    // Complex temp;
    
    // temp = *this;
    // this->re = temp.re * other.re - temp.im * other.im;
    // this->im = temp.re * other.im + temp.im * other.re;
// }

Complex complexSum(Complex a, Complex b) {
    Complex sum;
    
    sum.re = a.re + b.re;
    sum.im = a.im + b.im;
    return sum;
}

Complex complexDiff(Complex a, Complex b) {
    Complex diff;
    
    diff.re = a.re - b.re;
    diff.im = a.im - b.im;
    return diff;
}

Complex complexProduct(Complex a, Complex b) {
    Complex product;
    
    product.re = a.re * b.re - a.im * b.im;
    product.im = a.im * b.re + b.im * a.re;
    return product;
}

void complexMultiply(Complex *this, Complex other) {
    *this = complexProduct(*this, other);
}

int complexEqual(Complex a, Complex b) {
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this) {
    return hypot(this.re, this.im);
}

void complexPrint(Complex this) {
    if ( this.im < 0 ) {
        printf("%g%gi", this.re, this.im);
    } else {
        printf("%g+%gi", this.re, this.im);
    }
}

int main() {
    Complex a = {10, 3};
    Complex b = {3, -7};
    Complex this = {3, 4};
    Complex other = {2, 3};
    
    printf("\nComplex a = ");
    complexPrint(a);
    printf("\nComplex b = ");
    complexPrint(b);
    printf("\nComplex this = ");
    complexPrint(this);
    printf("\nComplex other = ");
    complexPrint(other);
    printf("\nSum: ");
    complexPrint(complexSum(a, b));
    printf("\nIncrement this na other:");
    complexIncrement(&this, other);
    complexPrint(this);
    printf("\nDecrement this na other: ");
    complexDecrement(&this, other);
    complexPrint(this);
    printf("\na*b =");
    complexPrint(complexProduct(a, b));
    printf("\nEqual a&b: %d\n", complexEqual(a, b));
    printf("Abs complex this: %g\n", complexAbs(this));
    complexMultiply(&this, other);
    printf("\nthis*other =");
    complexPrint(this);
    
    return 0;
}
