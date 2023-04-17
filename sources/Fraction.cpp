#include "Fraction.hpp"
#include <stdbool.h>
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

Fraction :: Fraction(double numerator, double denominator)
{
    
};

Fraction :: Fraction(double numerator)
{
    
};

Fraction :: Fraction(Fraction const& other)
{
    
};

Fraction :: Fraction()
{
    
};

Fraction :: Fraction(Fraction&& other) noexcept
{
    
};

Fraction& Fraction :: operator=(Fraction&& other) noexcept
{
    return *this;
};

Fraction& Fraction :: operator=(const Fraction& other)
{
    return *this;
};

Fraction& Fraction :: operator=(double other)
{
    return *this;
};

Fraction Fraction :: operator+(const Fraction& other) const
{
    return Fraction(1,1);
};

Fraction Fraction :: operator+(double other)
{
    return Fraction(1,1);
};

Fraction Fraction :: operator-(const Fraction& other) const
{
    return Fraction(1,1);
};

Fraction Fraction :: operator-(double other)
{
    return Fraction(1,1);
};

Fraction Fraction :: operator*(const Fraction& other) const
{
    return Fraction(1,1);
};

Fraction Fraction :: operator*(double other)
{
    return Fraction(1,1);
};

Fraction Fraction :: operator/(const Fraction& other) const
{
    return Fraction(1,1);
};

Fraction Fraction :: operator/(double other)
{
    return Fraction(1,1);
};

bool Fraction :: operator==(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator==(double other)
{
    return true;
};

bool Fraction :: operator!=(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator!=(double other)
{
    return true;
};

bool Fraction :: operator>(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator>(double other)
{
    return true;
};

bool Fraction :: operator<(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator<(double other)
{
    return true;
};

bool Fraction :: operator>=(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator>=(double other)
{
    return true;
};

bool Fraction :: operator<=(const Fraction& other) const
{
    return true;
};

bool Fraction :: operator<=(double other)
{
    return true;
};

Fraction& Fraction :: operator++()
{
     return *this;
};

Fraction& Fraction :: operator--()
{
     return *this;
};

Fraction Fraction :: operator++(int)
{
     return Fraction(1,1);
};

Fraction Fraction :: operator--(int)
{
     return Fraction(1,1);
};

// istream& operator>>(istream& is, Fraction& fraction)
// {
//     return is;
// };

// Fraction operator+(double other, const Fraction& fraction)
// {
//     return Fraction(1,1);
// };

// Fraction operator-(double other, const Fraction& fraction)
// {
//     return Fraction(1,1);
// };



// Fraction operator/(double other, const Fraction& fraction)
// {
//     return Fraction(1,1);
// };

// bool operator==(double other, const Fraction& fraction)
// {
//     return true;
// };

// bool operator!=(double other, const Fraction& fraction)
// {
//     return true;
// };

// bool operator>(double other, const Fraction& fraction)
// {
//     return true;
// };

// bool operator<(double other, const Fraction& fraction)
// {
//     return true;
// };

// bool operator>=(double other, const Fraction& fraction)
// {
//     return true;
// };

// bool operator<=(double other, const Fraction& fraction)
// {
//     return true;
// };

Fraction::operator std::string() const {
        return to_string(numerator) + "/" + to_string(denominator);
}

