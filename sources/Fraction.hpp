#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <stdbool.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
namespace ariel
{

    class Fraction
    {
        private:

            float numerator;
            float denominator;

        public:

            // Constructors and destructors
            Fraction(float numerator, float denominator);
            Fraction(float numerator);
            Fraction(Fraction const& other);
            Fraction();
            Fraction(Fraction&& other) noexcept; // move constructor
            ~Fraction() = default;

            // Operators for equlity (=)
            Fraction& operator=(Fraction&& other) noexcept; // move assignment operator
            Fraction& operator=(const Fraction& other);
            Fraction& operator=(float other);

            // Operators for addition (+)
            Fraction operator+(const Fraction& other) const;
            Fraction operator+(float other);
            Fraction& operator++(); 
            const Fraction operator++(int); 
            friend Fraction operator+(float other, const Fraction& fraction){
                float numerator = other * fraction.getDenominator() + fraction.getNumerator();
                float denominator = fraction.getDenominator();
                return Fraction(numerator, denominator);
            }

            // Operators for subtraction (-)
            Fraction operator-(const Fraction& other) const;
            Fraction operator-(float other);
            Fraction& operator--();
            const Fraction operator--(int);
            friend Fraction operator-(float other, const Fraction& fraction){
                float numerator = other * fraction.getDenominator() - fraction.getNumerator();
                float denominator = fraction.getDenominator();
                return Fraction(numerator, denominator);
            }

            // Operators for multiplication (*)
            Fraction operator*(const Fraction& other) const;
            Fraction operator*(float other);
            friend ariel::Fraction operator*(float other, const ariel::Fraction& fraction) {
                return Fraction(other * fraction.getNumerator(), fraction.getDenominator());
            }   

            // Operators for division (/)
            Fraction operator/(const Fraction& other) const;
            Fraction operator/(float other);
            friend Fraction operator/(float other, const Fraction& fraction){
                return Fraction(other * fraction.getDenominator(), fraction.getNumerator());
            }

            // Operators for equality-checking (==, !=)
            bool operator==(const Fraction& other) const;
            bool operator==(float other);
            friend bool operator==(float other, const Fraction& fraction){
                float val = fraction.tofloat();
                return other == val;
            }

            bool operator!=(const Fraction& other) const;
            bool operator!=(float other);
            friend bool operator!=(float other, const Fraction& fraction){
                float val = fraction.tofloat();
                return other != val;
            }

            // Operators for inequality (>, <, >=, <=)
            bool operator>(const Fraction& other) const;
            bool operator>(float other);
            friend bool operator>(float other, const Fraction& fraction){
                float val = fraction.tofloat();
                return other > val;
            }
            bool operator<(const Fraction& other) const;
            bool operator<(float other);
            friend bool operator<(float other, const Fraction& fraction){
                float val = fraction.tofloat();
                return other < val;
            }
            bool operator>=(const Fraction& other) const;
            bool operator>=(float other);
             friend bool operator>=(float other, const Fraction& fraction){
                 float val = fraction.tofloat();
                return other >= val;
            }
            bool operator<=(const Fraction& other) const;
            bool operator<=(float other);
            friend bool operator<=(float other, const Fraction& fraction){
                 float val = fraction.tofloat();
                return other <= val;
            }

            // To string
            operator std::string() const;


           // Stream operators
            friend std::ostream& operator<<(std::ostream& ostrm, const Fraction& fraction) {
                ostrm << fraction.numerator << "/" << fraction.denominator;
                return ostrm;
            }
            friend istream& operator>>(istream& istrm, Fraction& fraction){
                int num, denom;
                char slash;
                istrm >> num >> slash >> denom;

                if (istrm.good()) {
                    if (slash != '/') {
                        throw invalid_argument("Invalid input");
                    } else {
                        fraction = Fraction(num, denom);
                    }
                }
                return istrm;
            }

            // getters

            int getNumerator() const {
                return numerator;
            }

            int getDenominator() const {
                return denominator;
            }


            // Other methods

            static int gcd(int a, int b){
                if (a == 0) return b;
                return gcd(b % a, a);
                
            }

            static void reduce(float& numerator, float& denominator){
                int min = numerator < denominator ? numerator : denominator;
                int gcd = Fraction::gcd(numerator, denominator);
                numerator /= gcd;
                denominator /= gcd;
            }

            // Fraction floatToFraction(float value);
            
            float tofloat() const{
                return numerator / denominator;
            }

            // operator double () const{
            //     return tofloat();
            // }

            // operator float () const{
            //     return tofloat();
            // }
    };

}

#endif 