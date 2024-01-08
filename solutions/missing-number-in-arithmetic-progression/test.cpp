#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{5, 7, 11, 13},
          .expected = 9,
      },
      {
          .arr{15, 13, 12},
          .expected = 14,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::missingNumber(arr);
    REQUIRE(expected == actual);
  }
}
