#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <stdbool.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>
#include <unistd.h>

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
            Fraction operator+=(const Fraction& other);
            Fraction operator+=(float other);
            Fraction& operator++(); 
            const Fraction operator++(int); 
            friend Fraction operator+(float other, const Fraction& fraction){
                float numerator = other * (float)fraction.getDenominator() + (float)fraction.getNumerator();
                float denominator = (float)fraction.getDenominator();
                return Fraction(numerator, denominator);
            }

            // Operators for subtraction (-)
            Fraction operator-(const Fraction& other) const;
            Fraction operator-(float other);
            Fraction operator-=(const Fraction& other);
            Fraction operator-=(float other);
            Fraction& operator--();
            const Fraction operator--(int);
            friend Fraction operator-(float other, const Fraction& fraction){
                
                return Fraction(other * fraction.getDenominator() - fraction.getNumerator(), fraction.getDenominator());
            }

            // Operators for multiplication (*)
            Fraction operator*(const Fraction& other) const;
            Fraction operator*(float other);
            Fraction operator*=(const Fraction& other);
            Fraction operator*=(float other);
            friend ariel::Fraction operator*(float other, const ariel::Fraction& fraction) {
                return Fraction(other * fraction.getNumerator(), fraction.getDenominator());
            }   

            // Operators for division (/)
            Fraction operator/(const Fraction& other) const;
            Fraction operator/(float other);
            Fraction operator/=(const Fraction& other);
            Fraction operator/=(float other);
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
                float num = 0;
                float denom = 0;
                char slash = 0;
                istrm >> num >> slash >> denom;

                if (istrm.good()) {
                    if (slash != '/') {
                        throw invalid_argument("Invalid input");
                    } 

                    fraction = Fraction(num, denom);
                    
                }
                return istrm;
            }

            // getters

            float getNumerator() const {
                return numerator;
            }

            float getDenominator() const {
                return denominator;
            }


            // Other methods

            
            static void reduce(float& numerator, float& denominator){
                float min = numerator < denominator ? numerator : denominator;
                // cout << "numerator: " << numerator << " denominator: " << denominator << " min: " << min << endl;
                float gcd = 1;
                for(int i = 2; (float)i <= min; i++){
                    if((int)round(numerator) % i == 0 && (int)round(denominator) % i == 0){
                        gcd = (float)i;
                    }
                }
   
                gcd = round(gcd);
                numerator /= gcd;
                denominator /= gcd;
            }
            
            float tofloat() const{
                return numerator / denominator;
            }

    };

}

#endif 