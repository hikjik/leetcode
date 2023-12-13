#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int threshold;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 2, 2, 2, 5, 5, 5, 8},
          .k = 3,
          .threshold = 4,
          .expected = 3,
      },
      {
          .arr{11, 13, 17, 23, 29, 31, 7, 5, 2, 3},
          .k = 3,
          .threshold = 5,
          .expected = 6,
      },
  };

  for (const auto &[arr, k, threshold, expected] : test_cases) {
    const auto actual = Solution::numOfSubarrays(arr, k, threshold);
    REQUIRE(expected == actual);
  }
}
