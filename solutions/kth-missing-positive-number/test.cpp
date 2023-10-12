#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 3, 4, 7, 11},
          .k = 5,
          .expected = 9,
      },
      {
          .arr{1, 2, 3, 4},
          .k = 2,
          .expected = 6,
      },
  };

  for (const auto &[arr, k, expected] : test_cases) {
    const auto actual = Solution::findKthPositive(arr, k);
    REQUIRE(expected == actual);
  }
}
