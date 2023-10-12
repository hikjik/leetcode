#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{0, 1, 0},
          .expected = 1,
      },
      {
          .arr{0, 2, 1, 0},
          .expected = 1,
      },
      {
          .arr{0, 10, 5, 2},
          .expected = 1,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::peakIndexInMountainArray(arr);
    REQUIRE(expected == actual);
  }
}
