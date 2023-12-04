#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int a;
    int b;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 1,
          .b = 2,
          .expected = 3,
      },
      {
          .a = 2,
          .b = 3,
          .expected = 5,
      },
  };

  SECTION("Math") {
    for (const auto &[a, b, expected] : test_cases) {
      const auto actual = math::Solution::getSum(a, b);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Bit manipulations") {
    for (const auto &[a, b, expected] : test_cases) {
      const auto actual = bits::Solution::getSum(a, b);
      REQUIRE(expected == actual);
    }
  }
}
