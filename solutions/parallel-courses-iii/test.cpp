#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> relations;
    std::vector<int> time;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .relations{{1, 3}, {2, 3}},
          .time{3, 2, 5},
          .expected = 8,
      },
      {
          .n = 5,
          .relations{{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}},
          .time{1, 2, 3, 4, 5},
          .expected = 12,
      },
  };

  for (const auto &[n, relations, time, expected] : test_cases) {
    const auto actual = Solution::minimumTime(n, relations, time);
    REQUIRE(expected == actual);
  }
}
