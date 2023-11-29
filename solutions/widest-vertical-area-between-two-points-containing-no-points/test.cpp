#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{8, 7}, {9, 9}, {7, 4}, {9, 7}},
          .expected = 1,
      },
      {
          .points{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}},
          .expected = 3,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::maxWidthOfVerticalArea(points);
    REQUIRE(expected == actual);
  }
}
