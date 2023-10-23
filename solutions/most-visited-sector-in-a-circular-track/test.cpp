#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> rounds;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .rounds{3, 2, 1, 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 1},
          .expected{1, 3},
      },
      {
          .n = 4,
          .rounds{1, 3, 1, 2},
          .expected{1, 2},
      },
      {
          .n = 2,
          .rounds{2, 1, 2, 1, 2, 1, 2, 1, 2},
          .expected{2},
      },
      {
          .n = 7,
          .rounds{1, 3, 5, 7},
          .expected{1, 2, 3, 4, 5, 6, 7},
      },
  };

  for (const auto &[n, rounds, expected] : test_cases) {
    const auto actual = Solution::mostVisited(n, rounds);
    REQUIRE(expected == actual);
  }
}
