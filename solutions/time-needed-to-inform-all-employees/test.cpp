#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int headID;
    std::vector<int> manager;
    std::vector<int> informTime;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .headID = 0,
          .manager{-1},
          .informTime{0},
          .expected = 0,
      },
      {
          .n = 6,
          .headID = 2,
          .manager{2, 2, -1, 2, 2, 2},
          .informTime{0, 0, 1, 0, 0, 0},
          .expected = 1,
      },
  };

  for (const auto &[n, headID, manager, informTime, expected] : test_cases) {
    const auto actual = Solution::numOfMinutes(n, headID, manager, informTime);
    REQUIRE(expected == actual);
  }
}
