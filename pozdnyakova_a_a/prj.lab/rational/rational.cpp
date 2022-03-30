#include <rational/rational.h>
#include <string>
#include <iostream>


Rational& Rational::operator=(const Rational& rational) noexcept {
    if (this == &rational) {
        return *this;
    }
    numerator = rational.num();
    denominator = rational.denum();
    return *this;
}

int Rational::num() const noexcept {
    return numerator;
}

int Rational::denum() const noexcept {
    return denominator;
}


Rational Rational::operator-() const noexcept {
    return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    numerator = rhs.num() * denominator + numerator * rhs.denum();
    denominator = rhs.denum() * denominator;
    to_irreducible();
    return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    numerator = - rhs.num() * denominator + numerator * rhs.denum();
    denominator = rhs.denum() * denominator;
    to_irreducible();
    return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
    numerator = rhs.num() * numerator;
    denominator = rhs.denum() * denominator;
    to_irreducible();
    return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num() == 0) {
          throw std::invalid_argument("Division by zero");
    }
    numerator = rhs.denum() * numerator;
    denominator = rhs.num() * denominator;
    to_irreducible();
    return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    return (*this >= rhs) && (*this <= rhs);
}
bool Rational::operator!=(const Rational& rhs) const noexcept {
    return (*this > rhs) || (*this < rhs);
}
bool Rational::operator<(const Rational& rhs) const noexcept {
    return -*this > -rhs;
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
    return !(*this > rhs);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
    return numerator * rhs.denum() > denominator * rhs.num();
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
    return !(*this < rhs);
}

std::istream& Rational::read_from(std::istream& istrm) noexcept {
    char slash;
    int num;
    int denom;
    istrm >> num >> std::noskipws >> slash >> denom >> std::skipws;
    if (slash != '/') {
      istrm.setstate(std::ios_base::failbit);
    }
    if (istrm.rdstate() != std::ios_base::failbit) {
      *this = Rational(num, denom);
    }
    return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
    ostrm << std::to_string(numerator) + "/" + std::to_string(denominator);
}

int Rational::GCD(int a, int b) noexcept {
  while (b) {
      a %= b;
      std::swap(a, b);
  }
  return a;
}

void Rational::to_irreducible() noexcept {
  if (numerator == 0) {
      denominator = 1;
  }
  if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
  }
  int gcd = GCD(abs(numerator), abs(denominator));
  numerator /= gcd;
  denominator /= gcd;
}
