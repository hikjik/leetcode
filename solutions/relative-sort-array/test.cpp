#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19},
          .arr2{2, 1, 4, 3, 9, 6},
          .expected{2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19},
      },
      {
          .arr1{28, 6, 22, 8, 44, 17},
          .arr2{22, 28, 8, 6},
          .expected{22, 28, 8, 6, 17, 44},
      },
  };

  for (const auto &[arr1, arr2, expected] : test_cases) {
    const auto actual = Solution::relativeSortArray(arr1, arr2);
    REQUIRE(expected == actual);
  }
}
