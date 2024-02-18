#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{5, 5, 4},
          .k = 1,
          .expected = 1,
      },
      {
          .arr{4, 3, 1, 1, 3, 3, 2},
          .k = 3,
          .expected = 2,
      },
  };

  SECTION("Sorting") {
    for (const auto &[arr, k, expected] : test_cases) {
      const auto actual = sorting::Solution::findLeastNumOfUniqueInts(arr, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[arr, k, expected] : test_cases) {
      const auto actual = counting::Solution::findLeastNumOfUniqueInts(arr, k);
      REQUIRE(expected == actual);
    }
  }
}
