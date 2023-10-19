#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{1, 2}, {2, 3}, {4, 2}},
          .expected = 2,
      },
      {
          .edges{{1, 2}, {5, 1}, {1, 3}, {1, 4}},
          .expected = 1,
      },
  };

  for (const auto &[edges, expected] : test_cases) {
    const auto actual = Solution::findCenter(edges);
    REQUIRE(expected == actual);
  }
}
