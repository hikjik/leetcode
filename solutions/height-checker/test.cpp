#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{1, 1, 4, 2, 1, 3},
          .expected = 3,
      },
      {
          .heights{5, 1, 2, 3, 4},
          .expected = 5,
      },
      {
          .heights{1, 2, 3, 4, 5},
          .expected = 0,
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::heightChecker(heights);
    REQUIRE(expected == actual);
  }
}
