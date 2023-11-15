#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 2, 1, 2, 1},
          .expected = 2,
      },
      {
          .arr{100, 1, 1000},
          .expected = 3,
      },
      {
          .arr{1, 2, 3, 4, 5},
          .expected = 5,
      },
  };

  SECTION("Sorting") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual =
          sorting::Solution::maximumElementAfterDecrementingAndRearranging(arr);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual =
          counting::Solution::maximumElementAfterDecrementingAndRearranging(
              arr);
      REQUIRE(expected == actual);
    }
  }
}
