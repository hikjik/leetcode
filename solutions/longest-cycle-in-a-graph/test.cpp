#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> edges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{3, 3, 4, 2, 3},
          .expected = 3,
      },
      {
          .edges{2, -1, 3, 1},
          .expected = -1,
      },
  };

  for (const auto &[edges, expected] : test_cases) {
    const auto actual = Solution::longestCycle(edges);
    REQUIRE(expected == actual);
  }
}
