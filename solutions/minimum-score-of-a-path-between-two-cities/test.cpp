#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> roads;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .roads{{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}},
          .expected = 5,
      },
      {
          .n = 4,
          .roads{{1, 2, 2}, {1, 3, 4}, {3, 4, 7}},
          .expected = 2,
      },
  };

  for (const auto &[n, roads, expected] : test_cases) {
    const auto actual = Solution::minScore(n, roads);
    REQUIRE(expected == actual);
  }
}
