#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 0, 2, 3, 0, 4, 5, 0},
          .expected = {1, 0, 0, 2, 3, 0, 0, 4},
      },
      {
          .arr{1, 2, 3},
          .expected = {1, 2, 3},
      },
  };

  for (auto &[arr, expected] : test_cases) {
    Solution::duplicateZeros(arr);
    REQUIRE(expected == arr);
  }
}
