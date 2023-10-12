#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 4, 2, 5, 3},
          .expected = 58,
      },
      {
          .arr{1, 2},
          .expected = 3,
      },
      {
          .arr{10, 11, 12},
          .expected = 66,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::sumOddLengthSubarrays(arr);
    REQUIRE(expected == actual);
  }
}
