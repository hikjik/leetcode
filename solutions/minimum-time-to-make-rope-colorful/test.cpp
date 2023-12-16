#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string colors;
    std::vector<int> neededTime;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .colors = "abaac",
          .neededTime{1, 2, 3, 4, 5},
          .expected = 3,
      },
      {
          .colors = "abc",
          .neededTime{1, 2, 3},
          .expected = 0,
      },
      {
          .colors = "aabaa",
          .neededTime{1, 2, 3, 4, 1},
          .expected = 2,
      },
  };

  for (const auto &[colors, neededTime, expected] : test_cases) {
    const auto actual = Solution::minCost(colors, neededTime);
    REQUIRE(expected == actual);
  }
}
