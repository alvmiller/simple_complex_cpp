#include <cassert>
#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    constexpr Complex(double r = 0.0, double i = 0.0) noexcept :
        real(r), imaginary(i) { }

    constexpr double get_real() const noexcept {
        return real;
    }

    constexpr double get_imaginary() const noexcept {
        return imaginary;
    }

    constexpr Complex& operator+= (Complex rhs) noexcept { 
        real += rhs.real;
        imaginary += rhs.imaginary;
        return *this;
    }
};

constexpr Complex operator+ (Complex lhs, Complex rhs) noexcept 
{
    lhs += rhs;
    return lhs;
}

constexpr Complex operator""_i (long double imaginary) noexcept 
{
    return Complex(0.0, imaginary);
}

int main()
{
    constexpr Complex a = 0.0 + 1.0_i;
    constexpr Complex b = 1.0 + 2.0_i;
    constexpr Complex c = a + b;
    assert(c.get_real() == 1.0);
    assert(c.get_imaginary() == 3.0);

    return 0;
}
