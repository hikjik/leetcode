#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    int d;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr1{4, 5, 8},
          .arr2{10, 9, 1, 8},
          .d = 2,
          .expected = 2,
      },
      {
          .arr1{1, 4, 2, 3},
          .arr2{-4, -3, 6, 10, 20, 30},
          .d = 3,
          .expected = 2,
      },
      {
          .arr1{2, 1, 100, 3},
          .arr2{-5, -2, 10, -3, 7},
          .d = 6,
          .expected = 1,
      },
  };

  for (const auto &[arr1, arr2, d, expected] : test_cases) {
    const auto actual = Solution::findTheDistanceValue(arr1, arr2, d);
    REQUIRE(expected == actual);
  }
}
