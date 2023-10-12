#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> candies;
    int extraCandies;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .candies{2, 3, 5, 1, 3},
          .extraCandies = 3,
          .expected{true, true, true, false, true},
      },
      {
          .candies{4, 2, 1, 1, 2},
          .extraCandies = 1,
          .expected{true, false, false, false, false},
      },
      {
          .candies{12, 1, 12},
          .extraCandies = 10,
          .expected{true, false, true},
      },
  };

  for (const auto &[candies, extraCandies, expected] : test_cases) {
    const auto actual = Solution::kidsWithCandies(candies, extraCandies);
    REQUIRE(expected == actual);
  }
}
