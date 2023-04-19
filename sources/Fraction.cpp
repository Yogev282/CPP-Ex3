#include "Fraction.hpp"
#include <stdbool.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>

using namespace ariel;
using namespace std;

// ********** Constructors and destructors **********
Fraction :: Fraction(float numerator, float denominator)
{
    if(denominator == 0)
    {
        throw invalid_argument("Denominator can't be zero");
    }
    float num = numerator;
    float denom = denominator;

    while((num != round(num)) || (denom != round(denom)))
    {
        num *= 10;
        denom *= 10;
    }
    reduce(num, denom);
    this -> numerator = num;
    this -> denominator = denom;
};

Fraction :: Fraction(float numerator)
{
    float num = numerator;
    float denom = 1;
    while(num != (int)num && denom < 1000)
    {
        num *= 10;
        denom *= 10;
    }
    reduce(num, denom);
    this -> numerator = num;
    this -> denominator = denom;

};

Fraction :: Fraction(Fraction const& other)
{
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
};

Fraction :: Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
};

Fraction :: Fraction(Fraction&& other) noexcept
{
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
};


// ********** Operators for equlity (=) **********
Fraction& Fraction :: operator=(Fraction&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
    return *this;
};

Fraction& Fraction :: operator=(const Fraction& other)
{
    if(this == &other)
    {
        return *this;
    }
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
    return *this;
};

Fraction& Fraction :: operator=(float other)
{   
   
    Fraction tmp = Fraction(other);
    this -> numerator = tmp.getNumerator();
    this -> denominator = tmp.getDenominator();

    return *this;
};


// ********** Operators for addition (+) **********
Fraction Fraction :: operator+(const Fraction& other) const
{
    Fraction tmp(other);
    float numerator = this->numerator * tmp.getDenominator() + tmp.getNumerator() * this->denominator;
    float denominator = this->denominator * tmp.getDenominator();
    return Fraction(numerator, denominator);
};

Fraction Fraction :: operator+(float other)
{
    return *this + Fraction(other);
};

Fraction& Fraction :: operator++()
{
    this->numerator += this->denominator;
    reduce(this->numerator, this->denominator);
    return *this;
};

const Fraction Fraction :: operator++(int)
{
    Fraction cpy(*this);
    this->numerator += this->denominator;
    reduce(this->numerator, this->denominator);
    return cpy;
};


// ********** Operators for subtraction (-) **********
Fraction Fraction :: operator-(const Fraction& other) const
{
    float numerator = this->numerator * other.getDenominator() - other.getNumerator() * this->denominator;
    float denominator = this->denominator * other.getDenominator();
    return Fraction(numerator, denominator);
};

Fraction Fraction :: operator-(float other)
{
    return *this - Fraction(other);
};

Fraction& Fraction :: operator--()
{
    this->numerator -= this->denominator;
    reduce(this->numerator, this->denominator);
    return *this;
};

const Fraction Fraction :: operator--(int)
{
    Fraction cpy(*this);
    this->numerator -= this->denominator;
    reduce(this->numerator, this->denominator);
    return cpy;
};


// ********** Operators for multiplication (*) **********
Fraction Fraction :: operator*(const Fraction& other) const
{
    return Fraction(this->numerator * other.getNumerator(), this->denominator * other.getDenominator());
};

Fraction Fraction :: operator*(float other)
{
    return *this  * Fraction(other);
};


// ********** Operators for division (/) **********
Fraction Fraction :: operator/(const Fraction& other) const
{
    Fraction tmp = Fraction(other.getDenominator(), other.getNumerator());
    return *this * tmp;
};

Fraction Fraction :: operator/(float other)
{
    return *this / Fraction(other);
};

// ********** Operators for equality-checking (==, !=) **********
bool Fraction :: operator==(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return (val == otherVal);
};

bool Fraction :: operator==(float other)
{
    float val = tofloat();
    return (val == other);
};

bool Fraction :: operator!=(const Fraction& other) const
{
    return !(*this == other);
};

bool Fraction :: operator!=(float other)
{
    return !(*this == other);
};


// ********** Operators for inequality (<, >, <=, >=) **********
bool Fraction :: operator>(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return (val > otherVal);
};

bool Fraction :: operator>(float other)
{
    float val = tofloat();
    return (val > other);
};

bool Fraction :: operator<(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return (val < otherVal);
};

bool Fraction :: operator<(float other)
{
    float val = tofloat();
    return (val < other);
};

bool Fraction :: operator>=(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return (val >= otherVal);
};

bool Fraction :: operator>=(float other)
{
    float val = tofloat();
    return (val >= other);
};

bool Fraction :: operator<=(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return (val <= otherVal);
};

bool Fraction :: operator<=(float other)
{
    float val = tofloat();
    return (val <= other);
};


// ********** toString() **********
Fraction::operator std::string() const {
        return to_string(numerator) + "/" + to_string(denominator);
}

