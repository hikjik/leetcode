#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> edges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{1, 0, 0, 0, 0, 7, 7, 5},
          .expected = 7,
      },
      {
          .edges{2, 0, 0, 2},
          .expected = 0,
      },
  };

  for (const auto &[edges, expected] : test_cases) {
    const auto actual = Solution::edgeScore(edges);
    REQUIRE(expected == actual);
  }
}
