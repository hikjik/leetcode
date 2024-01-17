#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{-10, -5, 0, 3, 7},
          .expected = 3,
      },
      {
          .arr{0, 2, 5, 8, 17},
          .expected = 0,
      },
      {
          .arr{-10, -5, 3, 4, 7, 9},
          .expected = -1,
      },
      {
          .arr{-10, -5, -2, 0, 4, 5, 6, 7, 8, 9, 10},
          .expected = 4,
      },

  };

  for (const auto &[arr, expected] : test_cases) {
    const auto actual = Solution::fixedPoint(arr);
    REQUIRE(expected == actual);
  }
}
