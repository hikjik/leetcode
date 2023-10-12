#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string colors;
    std::vector<std::vector<int>> edges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .colors = "abaca",
          .edges{{0, 1}, {0, 2}, {2, 3}, {3, 4}},
          .expected = 3,
      },
      {
          .colors = "a",
          .edges{{0, 0}},
          .expected = -1,
      },
  };

  for (const auto &[colors, edges, expected] : test_cases) {
    const auto actual = Solution::largestPathValue(colors, edges);
    REQUIRE(expected == actual);
  }
}
