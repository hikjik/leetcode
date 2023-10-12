#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int difference;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 3, 4},
          .difference = 1,
          .expected = 4,
      },
      {
          .arr{1, 3, 5, 7},
          .difference = 1,
          .expected = 1,
      },
      {
          .arr{1, 5, 7, 8, 5, 3, 4, 2, 1},
          .difference = -2,
          .expected = 4,
      },
  };

  for (const auto &[arr, difference, expected] : test_cases) {
    const auto actual = Solution::longestSubsequence(arr, difference);
    REQUIRE(expected == actual);
  }
}
