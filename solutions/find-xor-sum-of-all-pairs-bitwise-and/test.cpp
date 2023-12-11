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
          .arr1{1, 2, 3},
          .arr2{6, 5},
          .expected = 0,
      },
      {
          .arr1{12},
          .arr2{4},
          .expected = 4,
      },
  };

  for (const auto &[arr1, arr2, expected] : test_cases) {
    const auto actual = Solution::getXORSum(arr1, arr2);
    REQUIRE(expected == actual);
  }
}
