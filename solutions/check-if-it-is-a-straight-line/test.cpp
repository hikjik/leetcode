#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> coordinates;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .coordinates{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}},
          .expected = true,
      },
      {
          .coordinates{{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}},
          .expected = false,
      },
  };

  for (const auto &[coordinates, expected] : test_cases) {
    const auto actual = Solution::checkStraightLine(coordinates);
    REQUIRE(expected == actual);
  }
}
