#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> logs;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .logs{{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}},
          .k = 5,
          .expected{0, 2, 0, 0, 0},
      },
      {
          .logs{{1, 1}, {2, 2}, {2, 3}},
          .k = 4,
          .expected{1, 1, 0, 0},
      },
  };

  for (const auto &[logs, k, expected] : test_cases) {
    const auto actual = Solution::findingUsersActiveMinutes(logs, k);
    REQUIRE(expected == actual);
  }
}
