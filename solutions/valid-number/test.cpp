#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("VALID NUMBERS") {
  std::vector<std::string> numbers{
      "0",    "2",     "0089", "-0.1",  "+3.14",   "4.",          "-.9",
      "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
  SECTION("RE") {
    for (const auto &number : numbers) {
      REQUIRE(re::Solution::isNumber(number));
    }
  }

  SECTION("Iterative") {
    for (const auto &number : numbers) {
      REQUIRE(iterative::Solution::isNumber(number));
    }
  }
}

TEST_CASE("NOT VALID NUMBERS") {
  std::vector<std::string> not_numbers{"abc", "1a",  "1e",       "e3", "99e2.5",
                                       "--6", "-+3", "95a54e53", ".",  "e"};
  SECTION("RE") {
    for (const auto &not_number : not_numbers) {
      REQUIRE_FALSE(re::Solution::isNumber(not_number));
    }
  }

  SECTION("Iterative") {
    for (const auto &not_number : not_numbers) {
      REQUIRE_FALSE(iterative::Solution::isNumber(not_number));
    }
  }
}
