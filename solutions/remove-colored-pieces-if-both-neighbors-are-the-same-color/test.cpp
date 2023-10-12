#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string colors;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .colors = "AAABABB",
          .expected = true,
      },
      {
          .colors = "AA",
          .expected = false,
      },
      {
          .colors = "ABBBBBBBAAA",
          .expected = false,
      },
  };

  for (const auto &[colors, expected] : test_cases) {
    const auto actual = Solution::winnerOfGame(colors);
    REQUIRE(expected == actual);
  }
}
