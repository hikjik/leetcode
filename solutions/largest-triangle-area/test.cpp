#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}},
          .expected = 2.00000,
      },
      {
          .points{{1, 0}, {0, 0}, {0, 1}},
          .expected = 0.50000,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::largestTriangleArea(points);
    REQUIRE(expected == Approx(actual));
  }
}
