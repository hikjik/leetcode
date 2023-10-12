#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> bombs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .bombs{{2, 1, 3}, {6, 1, 4}},
          .expected = 2,
      },
      {
          .bombs{{1, 1, 5}, {10, 10, 5}},
          .expected = 1,
      },
      {
          .bombs{{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}},
          .expected = 5,
      },
  };

  for (const auto &[bombs, expected] : test_cases) {
    const auto actual = Solution::maximumDetonation(bombs);
    REQUIRE(expected == actual);
  }
}
