#include <string>

class Rational {
public:
  Rational();
  Rational(const Rational&);
  Rational(Rational&&);
  Rational(const int num);
  Rational(const int num, const int denum);
  Rational& operator=(const Rational&);
  Rational& operator=(Rational&&);
  int num() const;
  int denum() const;

  Rational operator-() const;
  Rational& operator+=(const Rational& rhs);
  Rational& operator-=(const Rational& rhs);
  Rational& operator*=(const Rational& rhs);
  Rational& operator/=(const Rational& rhs);

  bool operator==(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;
  bool operator<(const Rational& rhs) const;
  bool operator<=(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;

  std::istream& read_from(std::istream& istrm);
  std::ostream& write_to(std::ostream& ostrm) const;
private:
  int numerator = 0;
  int denominator = 1;

  int GCD(int a, int b);

  void to_irreducible();
};

std::istream& operator>>(std::istream& istrm, Rational& r);
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

inline Rational operator+(const Rational& lhs, const Rational& rhs);
inline Rational operator-(const Rational& lhs, const Rational& rhs);
inline Rational operator*(const Rational& lhs, const Rational& rhs);
inline Rational operator/(const Rational& lhs, const Rational& rhs);