#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{2, 3, 1, 6, 7},
          .expected = 4,
      },
      {
          .arr{1, 1, 1, 1, 1},
          .expected = 10,
      },
  };

  SECTION("Prefix Sum") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual = prefix_sum::Solution::countTriplets(arr);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual = hash_table::Solution::countTriplets(arr);
      REQUIRE(expected == actual);
    }
  }
}
