#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaabbb",
          .expected = 2,
      },
      {
          .s = "aba",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::strangePrinter(s);
    REQUIRE(expected == actual);
  }
}
