#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> bottomLeft;
    std::vector<std::vector<int>> topRight;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bottomLeft{{1, 1}, {2, 2}, {3, 1}},
          .topRight{{3, 3}, {4, 4}, {6, 6}},
          .expected = 1,
      },
      {
          .bottomLeft{{1, 1}, {2, 2}, {1, 2}},
          .topRight{{3, 3}, {4, 4}, {3, 4}},
          .expected = 1,
      },
      {
          .bottomLeft{{1, 1}, {3, 3}, {3, 1}},
          .topRight{{2, 2}, {4, 4}, {4, 2}},
          .expected = 0,
      },
  };

  for (const auto &[bottomLeft, topRight, expected] : test_cases) {
    const auto actual = Solution::largestSquareArea(bottomLeft, topRight);
    REQUIRE(expected == actual);
  }
}
