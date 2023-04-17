#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <stdbool.h>
#include <iostream>
#include <string>

using namespace std;
namespace ariel
{

    class Fraction
    {
        private:
            int numerator;
            int denominator;

        public:
            Fraction(double numerator, double denominator);
            Fraction(double numerator);
            Fraction(Fraction const& other);
            Fraction();
            Fraction(Fraction&& other) noexcept; // move constructor
            ~Fraction() = default;
            Fraction& operator=(Fraction&& other) noexcept; // move assignment operator
            Fraction& operator=(const Fraction& other);
            Fraction& operator=(double other);
            Fraction operator+(const Fraction& other) const;
            Fraction operator+(double other);
            Fraction operator-(const Fraction& other) const;
            Fraction operator-(double other);
            Fraction operator*(const Fraction& other) const;
            Fraction operator*(double other);
            Fraction operator/(const Fraction& other) const;
            Fraction operator/(double other);
            bool operator==(const Fraction& other) const;
            bool operator==(double other);
            bool operator!=(const Fraction& other) const;
            bool operator!=(double other);
            bool operator>(const Fraction& other) const;
            bool operator>(double other);
            bool operator<(const Fraction& other) const;
            bool operator<(double other);
            bool operator>=(const Fraction& other) const;
            bool operator>=(double other);
            bool operator<=(const Fraction& other) const;
            bool operator<=(double other);
            Fraction& operator++(); 
            Fraction& operator--();
            Fraction operator++(int); 
            Fraction operator--(int);
            operator std::string() const;

            // the friend variable lets the function access the private variables of the class
            friend std::ostream& operator<<(std::ostream& ostrm, const Fraction& fraction) {
                return ostrm;
            }

            friend istream& operator>>(istream& istrm, Fraction& fraction){
                return istrm;
            }

            friend Fraction operator+(double other, const Fraction& fraction){
                return Fraction(1,1);
            }

            friend Fraction operator-(double other, const Fraction& fraction){
                return Fraction(1,1);
            }

            friend ariel::Fraction operator*(double value, const ariel::Fraction& fraction) {
                return Fraction{1,1};
            }   

            friend Fraction operator/(double other, const Fraction& fraction){
                return Fraction(1,1);
            }

            friend bool operator==(double other, const Fraction& fraction){
                return true;
            }

            friend bool operator!=(double other, const Fraction& fraction){
                return true;
            }

            friend bool operator>(double other, const Fraction& fraction){
                return true;
            }

            friend bool operator<(double other, const Fraction& fraction){
                return true;
            }

            friend bool operator>=(double other, const Fraction& fraction){
                return true;
            }

            friend bool operator<=(double other, const Fraction& fraction){
                return true;
            }


            // getters

            int getNumerator() const {
                return numerator;
            }

            int getDenominator() const {
                return denominator;
            }

    };

}

#endif 