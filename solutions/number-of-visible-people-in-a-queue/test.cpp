#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{10, 6, 8, 5, 11, 9},
          .expected{3, 1, 2, 1, 1, 0},
      },
      {
          .heights{5, 1, 2, 3, 10},
          .expected{4, 1, 1, 1, 0},
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::canSeePersonsCount(heights);
    REQUIRE(expected == actual);
  }
}
