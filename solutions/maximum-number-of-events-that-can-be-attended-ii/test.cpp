#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> events;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}},
          .k = 2,
          .expected = 7,
      },
      {
          .events{{1, 2, 4}, {3, 4, 3}, {2, 3, 10}},
          .k = 2,
          .expected = 10,
      },
      {
          .events{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}},
          .k = 3,
          .expected = 9,
      },
  };

  for (const auto &[events, k, expected] : test_cases) {
    const auto actual = Solution::maxValue(events, k);
    REQUIRE(expected == actual);
  }
}
