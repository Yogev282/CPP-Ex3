#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdbool.h>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Basic equals") {
    SUBCASE("Positive numbers"){
        CHECK(Fraction(1, 2) == Fraction(2, 4));
        CHECK(Fraction(1, 2) != Fraction(1, 3));
        CHECK(Fraction(1, 2) < Fraction(2, 3));
        CHECK(Fraction(1, 2) <= Fraction(2, 3));
        CHECK(Fraction(1, 2) <= Fraction(1, 2));
        CHECK(Fraction(1, 2) > Fraction(1, 3));
        CHECK(Fraction(1, 2) >= Fraction(1, 3));
        CHECK(Fraction(1, 2) >= Fraction(1, 2));
        CHECK(Fraction(2) == Fraction(2, 1));
        CHECK(Fraction(2) == Fraction(-2, -1));
        CHECK(Fraction() == Fraction(0, 1));
        CHECK(Fraction(0,1) == Fraction(0, 800));
        CHECK(Fraction(0,1) == 0);
        CHECK(Fraction(7,5) == 1.4);
        CHECK(Fraction(81,192) == 0.421875);
    }

    SUBCASE("Negative numbers"){
        CHECK(Fraction(-1, 2) == Fraction(1, -2));
        CHECK(Fraction(1, -2) == Fraction(-1, 2));
        CHECK(Fraction(-1, -2) == Fraction(1, 2));
        CHECK(Fraction(-1, 2) != Fraction(1, 2));
        CHECK(Fraction(1, -2) != Fraction(1, 2));
        CHECK(Fraction(-1, -2) == Fraction(1, 2));
        CHECK(Fraction(-1, 2) < Fraction(1, 2));
        CHECK(Fraction(1, -2) < Fraction(1, 2));
        CHECK(Fraction(-1, 2) <= Fraction(1, 2));
        CHECK(Fraction(1, -2) <= Fraction(1, 2));
        CHECK(Fraction(-1, -2) <= Fraction(1, 2));
        CHECK(Fraction(-2) == Fraction(-2, 1));
        CHECK(Fraction(-2) == Fraction(2, -1));
        CHECK(Fraction() == Fraction(0, -1));
        CHECK(Fraction(0,1) == Fraction(0, -800));
        CHECK(Fraction(0,-1) == 0);
        CHECK(Fraction(-7,5) == -1.4);
        CHECK(Fraction(81,-192) == -0.421875);
    }
};


TEST_CASE("Divide by zero") {
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(0, 0));
    CHECK_THROWS(Fraction(-1, 0));
}


TEST_CASE("Check for reduced form"){
    SUBCASE("Reduce without function"){
        CHECK(Fraction(2, 4) == Fraction(1, 2));
        CHECK(Fraction(3, 9) == Fraction(1, 3));
        CHECK(Fraction(4, 8) == Fraction(1, 2));
        CHECK(Fraction(5, 10) == Fraction(1, 2));
    }

    SUBCASE("Reduce with functions"){
        Fraction a(1, 2);
        Fraction b(4, 1);
        CHECK(a*b == Fraction(2, 1));
        CHECK(b/a == Fraction(8, 1));
        Fraction c(5, 8);
        Fraction d(3, 8);
        CHECK(c+d == Fraction(1, 1));
        CHECK(c-d == Fraction(1, 4));
        Fraction e(6, 10);
        CHECK(++e == Fraction(8, 5));
        CHECK(e-- == Fraction(8, 5));
        CHECK(e == Fraction(3, 5));
    }
}


TEST_CASE("Output not throw"){
    Fraction a (4, 2);
    Fraction b (7, 3);

    CHECK_NOTHROW(cout << a << endl);
    CHECK_NOTHROW(cout << b << endl);
}


TEST_CASE(" check every operator"){
    SUBCASE("(=)"){
        Fraction tmp(3, 7);
        Fraction a;
        a = tmp;
        CHECK(a == tmp);
        a = 2.5;
        Fraction b(5, 2);
        CHECK(b == a);
    };

    SUBCASE("(+)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(5, 6);
        CHECK(a+b == c);
        CHECK(a+2.371 == Fraction(2871, 1000));
        CHECK(2.371+a == Fraction(2871, 1000));
        Fraction d = 2.371;
        CHECK(d+a == Fraction(2871, 1000));
    };

    SUBCASE("(-)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(1, 6);
        CHECK(a-b == c);
        CHECK(a-2.393 == Fraction(-1893, 1000));
        CHECK(2.392-a == Fraction(473, 250));
        Fraction d = 2.393;
        CHECK(d-a == Fraction(1893, 1000));
    };

    SUBCASE("(*)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(1, 6);
        CHECK(a*b == c);
        CHECK(a*7.491 == Fraction(7491, 2000));
        CHECK(7.491*a == Fraction(7491, 2000));
        Fraction d = 7.491;
        CHECK(a*d == Fraction(7491, 2000));
        
    };

    SUBCASE("(/)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(3, 2);
        CHECK(a/b == c);
        CHECK(a/6.661 == Fraction(500, 6661));
        CHECK(6.661/a == Fraction(6661, 500));
        Fraction d = 6.661;
        CHECK(d/a == Fraction(6661, 500));
        
    };

    SUBCASE("(++)"){
        Fraction a(1, 2);
        Fraction b(3, 2);
        Fraction c(3,-2);
        CHECK(++a == b);
        CHECK(a-- == b);
        CHECK(----a == c);
    };

    SUBCASE("(--)"){
        Fraction a(1, 2);
        Fraction b(1, 2);
        Fraction c(-1, 2);
        Fraction d(5, 2);
        CHECK(--a == c);
        CHECK(a++ == c);
        CHECK(++++a == d);
    };

    SUBCASE("(+=)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(5, 6);
        CHECK((a+=b) == c);
        CHECK(a == c);
        CHECK((a+=2.371) == Fraction(9613, 3000));
    };

    SUBCASE("(-=)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(1, 6);
        CHECK((a-=b) == c);
        CHECK(a == c);
        CHECK((a-=2.393) == Fraction(-6679, 3000));
    };

    SUBCASE("(*=)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(1, 6);
        CHECK((a*=b) == c);
        CHECK(a == c);
        CHECK((a*=7.491) == Fraction(2497, 2000));
    };

    SUBCASE("(/=)"){
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(3, 2);
        CHECK((a/=b) == c);
        CHECK(a == c);
        CHECK((a/=6.661) == Fraction(1500, 6661));
    };


}

