#include "fraction.h"

// Constructeur qui appelle "setFraction" avec les deux arguments donnés
Fraction::Fraction(int num, unsigned int deno)
{
    setDenominateur(deno);
    setNumerateur(num);
}

// Constructeur de copie avec une Fraction en référence constante
Fraction::Fraction(Fraction const& other)
{
    setDenominateur(other.denominateur());
    setNumerateur(other.numerateur());
}

// Constructeur de copie avec une Fraction en référence
Fraction::Fraction(Fraction &other)
{
    setDenominateur(other.denominateur());
    setNumerateur(other.numerateur());
}

// Operateur d'assignement
Fraction& Fraction::operator=(Fraction &other)
{
    setDenominateur(other.denominateur());
    setNumerateur(other.numerateur());

    return *this;
}

// Attribut au numénateur l'argument
bool Fraction::setNumerateur(int numerateur)
{
    if (numerateur >= 0)
        num = numerateur;

    else
        return false;

    return true;
}

// Attribut au dénominateur l'argument
bool Fraction::setDenominateur(int denominateur)
{
    if (denominateur > 0)
        deno = denominateur;

    else
        return false;

    return true;
}

// Simplifie la fraction
void Fraction::simplifie()
{
    int pgcd = getPGCD(numerateur(), denominateur());

    setNumerateur(numerateur() / pgcd);
    setDenominateur(denominateur() / pgcd);
}

// Retourne le numérateur de la fraction
int Fraction::numerateur() const
{
    return num;
}

// Retourne le dénominateur de la fraction
int Fraction::denominateur() const
{
    return deno;
}

// Retourne un double corespondant à la fraction
double Fraction::toDouble() const
{
    return double(numerateur() / denominateur());
}

// Retourne la fraction dans un QString
QString Fraction::toString() const
{
    return QString::number(numerateur()) + "/" + QString::number(denominateur());
}

// Retourne le PPCM de la fraction
int Fraction::getPPCM(Fraction &a, Fraction &b)
{
    return getPPCM(a.denominateur(), b.denominateur());
}

// Retourne le PPCM des deux nombres
int Fraction::getPPCM(int a, int b)
{
    return (a * b / getPGCD(a, b));
}

// Retourne le PGCD de la fraction
int Fraction::getPGCD(Fraction &a, Fraction &b)
{
    return getPGCD(a.denominateur(), b.denominateur());
}

// Retourne le PGCD des deux nombres
int Fraction::getPGCD(int a, int b)
{
    if (a <= 0 || b <= 0)
        return 0;

    if (a < b)
        std::swap(a, b);

    int r = a % b;

    if (r == 0)
        return b;

    else
        return getPGCD(b, r);
}


/// -*-*- OPÉRATEUR -*-*-
// + + + +
Fraction& Fraction::operator+=(Fraction &a)
{
    int ppcm = getPPCM(denominateur(), a.denominateur());

    setDenominateur(denominateur() * (ppcm / denominateur()));
    setNumerateur((numerateur() * (ppcm / denominateur())) + (a.numerateur() * (ppcm / a.denominateur())));

    return *this;
}

Fraction& operator+(Fraction &a, Fraction &b)
{
    Fraction *copie = new Fraction(a);
    *copie += b;
    return *copie;
}

// - - - -
Fraction& Fraction::operator-=(Fraction &a)
{
    int ppcm = getPPCM(denominateur(), a.denominateur());

    setDenominateur(denominateur() * (ppcm / denominateur()));
    setNumerateur((numerateur() * (ppcm / denominateur())) - (a.numerateur() * (ppcm / a.denominateur())));

    return *this;
}

Fraction& operator-(Fraction &a, Fraction &b)
{
    Fraction *copie = new Fraction(a);
    *copie -= b;
    return *copie;
}

// * * * *
Fraction& Fraction::operator*=(Fraction &a)
{
    setNumerateur(numerateur() * a.numerateur());
    setDenominateur(denominateur() * a.denominateur());

    return *this;
}

Fraction& operator*(Fraction &a, Fraction &b)
{
    Fraction *copie = new Fraction(a);
    *copie *= b;
    return *copie;
}

// / / / /
Fraction& Fraction::operator/=(Fraction &a)
{
    setNumerateur(numerateur() * a.denominateur());
    setDenominateur(denominateur() * a.numerateur());

    return *this;
}

Fraction& operator/(Fraction &a, Fraction &b)
{
    Fraction *copie = new Fraction(a);
    *copie /= b;
    return *copie;
}

// ++ ++ ++ ++
Fraction& Fraction::operator++()
{
    setNumerateur(numerateur() + denominateur());
    simplifie();
    return *this;
}

Fraction& Fraction::operator++(int)
{
    Fraction *copie = new Fraction(*this);
    setNumerateur(numerateur() + denominateur());
    simplifie();
    return *copie;
}

// -- -- -- --
Fraction& Fraction::operator--()
{
    setNumerateur(numerateur() - denominateur());
    simplifie();
    return *this;
}

Fraction& Fraction::operator--(int)
{
    Fraction *copie = new Fraction(*this);
    setNumerateur(numerateur() - denominateur());
    simplifie();
    return *copie;
}


/// -*-*- OPÉRATEURS DE TEST SUR LES FRACTIONS -*-*-
// > > > >
bool operator>(Fraction &a, Fraction &b)
{
    return a.toDouble() > b.toDouble();
}

bool operator>=(Fraction &a, Fraction &b)
{
    return a.toDouble() >= b.toDouble();
}

// == == == ==
bool operator==(Fraction &a, Fraction &b)
{
    return a.toDouble() == b.toDouble();
}

bool operator!=(Fraction &a, Fraction &b)
{
    return a.toDouble() != b.toDouble();
}

// < < < <
bool operator<=(Fraction &a, Fraction &b)
{
    return a.toDouble() <= b.toDouble();
}

bool operator<(Fraction &a, Fraction &b)
{
    return a.toDouble() < b.toDouble();
}


