#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{1, 2, 2, 6, 6, 6, 6, 7, 10},
          .expected = 6,
      },
      {
          .arr{1, 1},
          .expected = 1,
      },
      {
          .arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12},
          .expected = 12,
      },
      {
          .arr{1, 1, 1, 1, 1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
          .expected = 1,
      },
      {
          .arr{0, 1, 1, 1, 1, 1, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
          .expected = 1,
      },
  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::findSpecialInteger(arr);
    REQUIRE(expected == actual);
  }
}
