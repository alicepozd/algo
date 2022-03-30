#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <string>
#include <stdexcept>

class Rational {
public:
  Rational() = default;
  Rational(const Rational& rational) = default;
  Rational(Rational&& rational) = default;
  Rational(const int num) : numerator(num) {}
  Rational(const int num, const int denum) : numerator(num) , denominator(denum) {
      if (denum == 0) {
          throw std::invalid_argument("Denominator can't be zero");
      }
      to_irreducible();
  }
  Rational& operator=(const Rational& rational) noexcept;

  Rational& operator=(Rational&& rational) noexcept = default;

  int num() const noexcept;

  int denum() const noexcept;


  Rational operator-() const noexcept;

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  bool operator==(const Rational& rhs) const noexcept;
  bool operator!=(const Rational& rhs) const noexcept;
  bool operator<(const Rational& rhs) const noexcept;
  bool operator<=(const Rational& rhs) const noexcept;
  bool operator>(const Rational& rhs) const noexcept;
  bool operator>=(const Rational& rhs) const noexcept;

  std::istream& read_from(std::istream& istrm) noexcept;

  std::ostream& write_to(std::ostream& ostrm) const noexcept;
private:
  int numerator = 0;
  int denominator = 1;

  int GCD(int a, int b) noexcept;

  void to_irreducible() noexcept;
};

inline std::istream& operator>>(std::istream& istrm, Rational& r) {
    return r.read_from(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
    return r.write_to(ostrm);
}

inline Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) += rhs;
}
inline Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) -= rhs;
}
inline Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) *= rhs;
}
inline Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) /= rhs;
}

#endif
