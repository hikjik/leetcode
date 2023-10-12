#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int x;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 3, 4, 5},
          .k = 4,
          .x = 3,
          .expected{1, 2, 3, 4},
      },
      {
          .arr{1, 2, 3, 4, 5},
          .k = 4,
          .x = -1,
          .expected{1, 2, 3, 4},
      },
  };

  for (const auto &[arr, k, x, expected] : test_cases) {
    const auto actual = Solution::findClosestElements(arr, k, x);
    REQUIRE(expected == actual);
  }
}
