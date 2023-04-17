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
        CHECK(Fraction(-1, -2) != Fraction(1, 2));
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
        CHECK(e++ == Fraction(8, 5));
        CHECK(e-- == Fraction(-2, 5));
    }
}


TEST_CASE("Output not throw"){
    Fraction a (4, 2);
    Fraction b (7, 3);

    CHECK_NOTHROW(cout << a << endl);
    CHECK_NOTHROW(cout << b << endl);
}




