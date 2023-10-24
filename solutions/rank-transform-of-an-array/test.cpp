#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{37, 12, 28, 9, 100, 56, 80, 5, 12},
          .expected{5, 3, 4, 2, 8, 6, 7, 1, 3},
      },
      {
          .arr{40, 10, 20, 30},
          .expected{4, 1, 2, 3},
      },
      {
          .arr{100, 100, 100},
          .expected{1, 1, 1},
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::arrayRankTransform(arr);
    REQUIRE(expected == actual);
  }
}
