#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}},
          .expected = 20,
      },
      {
          .points{{3, 12}, {-2, 5}, {-4, 1}},
          .expected = 18,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::minCostConnectPoints(points);
    REQUIRE(expected == actual);
  }
}
