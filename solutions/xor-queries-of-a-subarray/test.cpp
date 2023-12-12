#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<std::vector<int>> queries;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 3, 4, 8},
          .queries{{0, 1}, {1, 2}, {0, 3}, {3, 3}},
          .expected{2, 7, 14, 8},
      },
      {
          .arr{4, 8, 2, 10},
          .queries{{2, 3}, {1, 3}, {0, 0}, {0, 3}},
          .expected{8, 0, 4, 4},
      },
  };

  for (const auto &[arr, queries, expected] : test_cases) {
    const auto actual = Solution::xorQueries(arr, queries);
    REQUIRE(expected == actual);
  }
}
