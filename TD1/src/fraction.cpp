#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

// Exercice 2
std::ostream& Fraction::operator<<(std::ostream& os) const {
    return os << numerator << "/" << denominator;
}


// Exercice 1 (en commentaire) et Exercice 5 seconde partie
// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator+(Fraction f1, Fraction const& f2) {
    f1 += f2;
    return f1;
}

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return f1;
}

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return f1;
}

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }
Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return f1;
}


// Exercice 3
bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}


// Exercice 4
bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1 < f2 || f1 == f2;
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 <= f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}


// Exercice 5
void Fraction::operator+=(Fraction const& f) {
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;

    *this = simplify(*this);
}

void Fraction::operator-=(Fraction const& f) {
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;

    *this = simplify(*this);
}

void Fraction::operator*=(Fraction const& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;

    *this = simplify(*this);
}

void Fraction::operator/=(Fraction const& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;

    *this = simplify(*this);
}


// Exercice 6
float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}


// Aller plus loin
Fraction operator+(Fraction const& f, int const i) {
    return simplify({
        f.numerator + i * f.denominator,
        f.denominator
    });
}
Fraction operator+(int const i, Fraction const& f) {
    return f + i;
}

Fraction operator-(Fraction const& f, int const i) {
    return simplify({
        f.numerator - i * f.denominator,
        f.denominator
    });
}
Fraction operator-(int const i, Fraction const& f) {
    return simplify({
        i * f.denominator - f.numerator,
        f.denominator
    });
}

Fraction operator*(Fraction const& f, int const i) {
    return simplify({
        f.numerator * i,
        f.denominator
    });
}
Fraction operator*(int const i, Fraction const& f) {
    return f * i;
}

Fraction operator/(Fraction const& f, int const i) {
    return simplify({
        f.numerator,
        f.denominator * i
    });
}
Fraction operator/(int const i, Fraction const& f) {
    return simplify({
        i * f.denominator,
        f.numerator
    });
}

