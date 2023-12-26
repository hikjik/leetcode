#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .arr{6, 2, 4},
          .expected = 32,
      },
      {
          .arr{4, 11},
          .expected = 44,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual = dp::Solution::mctFromLeafValues(arr);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Greedy") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual = greedy::Solution::mctFromLeafValues(arr);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[arr, expected] : test_cases) {
      const auto actual = stack::Solution::mctFromLeafValues(arr);
      REQUIRE(expected == actual);
    }
  }
}
