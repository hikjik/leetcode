#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{1, 1}, {2, 3}, {3, 2}},
          .expected = true,
      },
      {
          .points{{1, 1}, {2, 2}, {3, 3}},
          .expected = false,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::isBoomerang(points);
    REQUIRE(expected == actual);
  }
}
