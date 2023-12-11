#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int d;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{9, 8, 7, 6, 6, 5, 4},
          .d = 1,
          .expected = 4,
      },
      {
          .arr{9, 7, 7, 5, 5, 3, 1},
          .d = 2,
          .expected = 5,
      },
      {
          .arr{9, 7, 7, 5, 5, 5, 3, 1},
          .d = 2,
          .expected = 3,
      },
      {
          .arr{6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12},
          .d = 2,
          .expected = 4,
      },
      {
          .arr{3, 3, 3, 3, 3},
          .d = 3,
          .expected = 1,
      },
      {
          .arr{7, 6, 5, 4, 3, 2, 1},
          .d = 1,
          .expected = 7,
      },
  };

  SECTION("Memoization") {
    for (const auto &[arr, d, expected] : test_cases) {
      const auto actual = memo::Solution::maxJumps(arr, d);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[arr, d, expected] : test_cases) {
      const auto actual = stack::Solution::maxJumps(arr, d);
      REQUIRE(expected == actual);
    }
  }
}
