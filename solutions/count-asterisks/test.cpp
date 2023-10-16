#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "l|*e*et|c**o|*de|",
          .expected = 2,
      },
      {
          .s = "iamprogrammer",
          .expected = 0,
      },
      {
          .s = "yo|uar|e**|b|e***au|tifu|l",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countAsterisks(s);
    REQUIRE(expected == actual);
  }
}
