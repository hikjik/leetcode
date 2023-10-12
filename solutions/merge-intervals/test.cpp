#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
          .expected{{1, 6}, {8, 10}, {15, 18}},
      },
      {
          .intervals{{1, 4}, {4, 5}},
          .expected{{1, 5}},
      },
  };

  for (const auto &[intervals, expected] : test_cases) {
    const auto actual = Solution::merge(intervals);
    REQUIRE(expected == actual);
  }
}
