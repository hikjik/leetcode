#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3},
          .expected = 2.00000,
      },
      {
          .arr{6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0},
          .expected = 4.00000,
      },
      {
          .arr{6, 0, 7, 0, 7, 5, 7, 8, 3,  4, 0, 7, 8, 1, 6, 8,  1, 1, 2, 4,
               8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4},
          .expected = 4.77778,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::trimMean(arr);
    REQUIRE(expected == Approx(actual));
  }
}
