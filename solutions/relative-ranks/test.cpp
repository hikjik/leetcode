#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> score;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .score{5, 4, 3, 2, 1},
          .expected{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"},
      },
      {
          .score{10, 3, 8, 9, 4},
          .expected{"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"},
      },
  };

  for (const auto &[score, expected] : test_cases) {
    const auto actual = Solution::findRelativeRanks(score);
    REQUIRE(expected == actual);
  }
}
