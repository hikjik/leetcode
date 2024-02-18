#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> meetings;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .meetings{{0, 10}, {1, 5}, {2, 7}, {3, 4}},
          .expected = 0,
      },
      {
          .n = 3,
          .meetings{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}},
          .expected = 1,
      },
  };

  for (const auto &[n, meetings, expected] : test_cases) {
    const auto actual = Solution::mostBooked(n, meetings);
    REQUIRE(expected == actual);
  }
}
