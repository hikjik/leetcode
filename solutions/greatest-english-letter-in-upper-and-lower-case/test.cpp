#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "lEeTcOdE",
          .expected = "E",
      },
      {
          .s = "arRAzFif",
          .expected = "R",
      },
      {
          .s = "AbCdEfGhIjK",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::greatestLetter(s);
    REQUIRE(expected == actual);
  }
}
