#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{1, 1}, {2, 2}, {3, 3}},
          .expected = 3,
      },
      {
          .points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}},
          .expected = 4,
      },
  };

  SECTION("Naive") {
    for (const auto &[points, expected] : test_cases) {
      const auto actual = naive::Solution::maxPoints(points);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Efficient") {
    for (const auto &[points, expected] : test_cases) {
      const auto actual = efficient::Solution::maxPoints(points);
      REQUIRE(expected == actual);
    }
  }
}
