#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rational/rational.h>
#include <random>
#include <sstream>


TEST_CASE("comparation") {
  Rational first(5, 6);
  Rational second(65, 66);
  Rational forth(5, 6);
  Rational third(-5, 6);

  CHECK(first == forth);
  CHECK(first <= forth);
  CHECK(first >= forth);

  CHECK(first <= second);
  CHECK(second >= first);
  CHECK(first < second);
  CHECK(second > first);

  CHECK(first != second);

  CHECK_FALSE(first > second);
  CHECK_FALSE(second < first);
  CHECK_FALSE(first >= second);
  CHECK_FALSE(second <= first);

  CHECK(first != second);
}


TEST_CASE("arithmetics") {
  for (int i; i < 10; ++i) {
    int a = rand() % 1000;
    int b = rand() % 1000 + 1;
    int c = rand() % 1000;
    int d = rand() % 1000 + 1;
    Rational first(a, b);
    Rational second(c, d);
    CHECK(first + second == Rational(a * d + b * c, b * d));
    CHECK(first * second == Rational(a * c, b * d));
    CHECK(first - second == Rational(a * d - b * c, b * d));
    CHECK(first / second == Rational(a * d, b * c));
  }
}


TEST_CASE("exeptions") {
  CHECK_THROWS(Rational(0, 0));
  CHECK_THROWS(Rational(0, 1) / Rational(0, 1));
}


TEST_CASE("irreducible test") {
  for (int i; i < 10; ++i) {
    int a = rand() % 1000;
    int b = rand() % 1000 + 1;
    int c = rand() % 1000 + 1;
    Rational first(a, b);
    Rational second(-a, -b);
    Rational third(a * c, b * c);
    Rational forth(-a * c, -b * c);
    Rational fifth(0, c);
    Rational sixth(0, b);
    Rational seventh(-a, b);
    Rational eighth(a, -b);
    CHECK(first == second);
    CHECK(second == third);
    CHECK(third == forth);
    CHECK(fifth == sixth);
    CHECK(seventh == eighth);
  }
}


TEST_CASE("correct input and output") {
  std::stringstream istream;
  istream << "5/6";
  Rational first;
  istream >> first;
  CHECK(first == Rational(5, 6));

  std::stringstream ostream;
  ostream << first;
  std::string string;
  ostream >> string;
  CHECK(string == "5/6");
}


TEST_CASE("correct input work") {
  SUBCASE("uncorrect format") {
    std::stringstream input_stream;
    input_stream << "5 /6";
    Rational number;
    input_stream >> number;
    CHECK(input_stream.fail());
  }

  SUBCASE("good") {
    std::stringstream input_stream;
    input_stream << "5/6 ";
    Rational number;
    input_stream >> number;
    CHECK(input_stream.good());
  }

  SUBCASE("eof") {
    std::stringstream input_stream;
    input_stream << "5/6";
    Rational number;
    input_stream >> number;
    CHECK(input_stream.eof());
  }
}