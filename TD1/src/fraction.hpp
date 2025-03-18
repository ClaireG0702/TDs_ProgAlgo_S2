#pragma once
#include <iostream> 

struct Fraction {
    int numerator { 0 };
    int denominator { 1 };

    // Exercice 2
    std::ostream& operator<<(std::ostream& os) const;

    // Exercice 5
    void operator+=(Fraction const& f);
    void operator-=(Fraction const& f);
    void operator*=(Fraction const& f);
    void operator/=(Fraction const& f);

    // Exercice 6
    float to_float() const;
    operator float() const;
};

// Exercice 1 et Exercice 5 seconde partie
// Fraction operator+(Fraction const& f1, Fraction const& f2);
// Fraction operator-(Fraction const& f1, Fraction const& f2);
// Fraction operator*(Fraction const& f1, Fraction const& f2);
// Fraction operator/(Fraction const& f1, Fraction const& f2);
Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);

// Exercice 3
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

// Exercice 4
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);


// Aller plus loin
Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);

