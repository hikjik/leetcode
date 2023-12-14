#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    std::vector<int> values;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 5}},
          .values{5, 2, 5, 2, 1, 1},
          .expected = 11,
      },
      {
          .edges{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}},
          .values{20, 10, 9, 7, 4, 3, 5},
          .expected = 40,
      },
  };

  for (const auto &[edges, values, expected] : test_cases) {
    const auto actual = Solution::maximumScoreAfterOperations(edges, values);
    REQUIRE(expected == actual);
  }
}
