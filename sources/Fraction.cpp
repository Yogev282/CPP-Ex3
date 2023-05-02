#include "Fraction.hpp"
#include <stdbool.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>

using namespace ariel;
using namespace std;

int max_int = std::numeric_limits<int>::max();
int min_int = std::numeric_limits<int>::min();

// ********** Constructors and destructors **********
Fraction :: Fraction(int numerator, int denominator)
{
    if(denominator == 0)
    {
        throw invalid_argument("Denominator can't be zero");
    }

    reduce(numerator, denominator);
    this -> numerator = numerator;
    this -> denominator = denominator;
};

Fraction :: Fraction(float numerator)
{
    float num = numerator * devider;
    int denom = devider;
    int num1 = num;
    
    reduce(num1, denom);
    
    this -> numerator = num1;
    this -> denominator = denom;

};

Fraction :: Fraction(Fraction const& other)
{
    if(this == &other)
    {
        return;
    }
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
    if(this == &other)
    {
        return;
    }
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
    long long int num = static_cast<long long int>(this->numerator) * static_cast<long long int>(other.denominator) +
                         static_cast<long long int>(other.numerator) * static_cast<long long int>(this->denominator);

    long long int denom = static_cast<long long int>(this->denominator) * static_cast<long long int>(other.denominator);

    if(num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("Overflow error");
    }
    return Fraction(num, denom);
};

Fraction Fraction :: operator+(float other)
{
    float tmp = (*this).tofloat();
    tmp = round(tmp * devider) / devider;
    float tmp2 = round(other * devider) / devider;
    float tmp3 = round((tmp + tmp2) * devider) / devider;
    return Fraction(tmp3);
};

Fraction Fraction :: operator+=(const Fraction& other)
{
    *this = *this + other;
    return *this;
};

Fraction Fraction :: operator+=(float other)
{
    *this = *this + other;
    return *this;
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
    long long int num = static_cast<long long int>(this->numerator) * static_cast<long long int>(other.denominator) -
                         static_cast<long long int>(other.numerator) * static_cast<long long int>(this->denominator);

    long long int denom = static_cast<long long int>(this->denominator) * static_cast<long long int>(other.denominator);

    if(num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("Overflow error");
    }
    return Fraction(num, denom);
};

Fraction Fraction :: operator-(float other)
{
    float tmp = (*this).tofloat();
    tmp = round(tmp * devider) / devider;
    float tmp2 = round(other * devider) / devider;
    float tmp3 = round((tmp - tmp2) * devider) / devider;
    return Fraction(tmp3);
};

Fraction Fraction :: operator-=(const Fraction& other)
{
    *this = *this - other;
    return *this;
};

Fraction Fraction :: operator-=(float other)
{
    *this = *this - other;
    return *this;
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
    long long int num = static_cast<long long int>(this->numerator) * static_cast<long long int>(other.numerator);

    long long int denom = static_cast<long long int>(this->denominator) * static_cast<long long int>(other.denominator);

    if(num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("Overflow error");
    }
    
    int numerator = this->numerator * other.numerator;
    int denominator = this->denominator * other.denominator;
    
    return Fraction(numerator, denominator);
}


Fraction Fraction :: operator*(float other)
{
    return *this * Fraction(other);
};

Fraction Fraction :: operator *=(const Fraction& other){
    *this = *this * other;
    return *this;
}

Fraction Fraction :: operator *=(float other){
    *this = *this * other;
    return *this;
}


// ********** Operators for division (/) **********
Fraction Fraction :: operator/(const Fraction& other) const
{
    if(other.getNumerator() == 0)
    {
        throw std::runtime_error("Can't divide by zero");
    }

    long long int num = static_cast<long long int>(this->numerator) * static_cast<long long int>(other.getDenominator());

    long long int denom = static_cast<long long int>(this->denominator) * static_cast<long long int>(other.getNumerator());

    if(num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("Overflow error");
    }
    return Fraction(num, denom);
};

Fraction Fraction :: operator/(float other)
{
    if(other == 0)
    {
        throw std::runtime_error("Can't divide by zero");
    }
    float tmp = (*this).tofloat();
    float tmp2 = round(other * devider) / devider;
    float tmp3 = round((tmp / tmp2) * devider) / devider;
    return Fraction(tmp3);
};

Fraction Fraction :: operator/=(const Fraction& other)
{
    if(other.getNumerator() == 0)
    {
        throw std::runtime_error("Can't divide by zero");
    }
    *this = *this / other;
    return *this;
};

Fraction Fraction :: operator/=(float other)
{
    if(other == 0)
    {
        throw std::runtime_error("Can't divide by zero");
    }
    *this = *this / other;
    return *this;
};

// ********** Operators for equality-checking (==, !=) **********
bool Fraction :: operator==(const Fraction& other) const
{
    float val = tofloat();
    float otherVal = other.tofloat();
    return round(val * devider) / devider == round(otherVal * devider) / devider;
};

bool Fraction :: operator==(float other)
{
    float val = tofloat();
    return round(val * devider) / devider == round(other * devider) / devider;
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

