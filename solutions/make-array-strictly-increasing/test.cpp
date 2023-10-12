#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr1{1, 5, 3, 6, 7},
          .arr2{1, 3, 2, 4},
          .expected = 1,
      },
      {
          .arr1{1, 5, 3, 6, 7},
          .arr2{4, 3, 1},
          .expected = 2,
      },
      {
          .arr1{1, 5, 3, 6, 7},
          .arr2{1, 6, 3, 3},
          .expected = -1,
      },
  };

  for (const auto &[arr1, arr2, expected] : test_cases) {
    const auto actual = Solution::makeArrayIncreasing(arr1, arr2);
    REQUIRE(expected == actual);
  }
}
