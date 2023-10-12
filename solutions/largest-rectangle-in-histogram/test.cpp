#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{2, 1, 5, 6, 2, 3},
          .expected = 10,
      },
      {
          .heights{2, 4},
          .expected = 4,
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::largestRectangleArea(heights);
    REQUIRE(expected == actual);
  }
}
