#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 3, 10, 4, 2, 3, 5},
          .expected = 3,
      },
      {
          .arr{5, 4, 3, 2, 1},
          .expected = 4,
      },
      {
          .arr{1, 2, 3},
          .expected = 0,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::findLengthOfShortestSubarray(arr);
    REQUIRE(expected == actual);
  }
}
