#ifndef FRACTION_H
#define FRACTION_H

#include <QString>

class Fraction
{ 
public:
    Fraction(int num = 1, unsigned int deno = 1);
    Fraction(Fraction const& other);
    Fraction(Fraction &other);
    Fraction& operator=(Fraction &other);

    bool setNumerateur(int numerateur);
    bool setDenominateur(int denominateur);
    void simplifie();

    int numerateur() const;
    int denominateur() const;

    double toDouble() const;
    QString toString() const;

    static int getPPCM(Fraction &a, Fraction &b);
    static int getPPCM(int a, int b);

    static int getPGCD(Fraction &a, Fraction &b);
    static int getPGCD(int a, int b);

    // Opérateurs
    Fraction& operator+=(Fraction &a);
    Fraction& operator-=(Fraction &a);
    Fraction& operator*=(Fraction &a);
    Fraction& operator/=(Fraction &a);

    Fraction& operator++();
    Fraction& operator++(int);

    Fraction& operator--();
    Fraction& operator--(int);


private:
    int num;
    int deno;
};

// Opérateurs
Fraction& operator+(Fraction &a, Fraction &b);
Fraction& operator-(Fraction &a, Fraction &b);
Fraction& operator*(Fraction &a, Fraction &b);
Fraction& operator/(Fraction &a, Fraction &b);

bool operator>(Fraction &a, Fraction &b);
bool operator>=(Fraction &a, Fraction &b);

bool operator==(Fraction &a, Fraction &b);
bool operator!=(Fraction &a, Fraction &b);

bool operator<=(Fraction &a, Fraction &b);
bool operator<(Fraction &a, Fraction &b);


#endif // FRACTION_H
