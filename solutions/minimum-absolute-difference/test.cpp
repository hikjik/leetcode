#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{4, 2, 1, 3},
          .expected{{1, 2}, {2, 3}, {3, 4}},
      },
      {
          .arr{1, 3, 6, 10, 15},
          .expected{{1, 3}},
      },
      {
          .arr{3, 8, -10, 23, 19, -4, -14, 27},
          .expected{{-14, -10}, {19, 23}, {23, 27}},
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::minimumAbsDifference(arr);
    REQUIRE(expected == actual);
  }
}
