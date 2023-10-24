#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "011101",
          .expected = 5,
      },
      {
          .s = "00111",
          .expected = 5,
      },
      {
          .s = "1111",
          .expected = 3,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maxScore(s);
    REQUIRE(expected == actual);
  }
}
