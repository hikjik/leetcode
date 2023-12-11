#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> values;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .values{{8, 5, 2}, {6, 4, 1}, {9, 7, 3}},
          .expected = 285,
      },
      {
          .values{{10, 8, 6, 4, 2}, {9, 7, 5, 3, 2}},
          .expected = 386,
      },
  };

  SECTION("Sort") {
    for (const auto &[values, expected] : test_cases) {
      const auto actual = sort::Solution::maxSpending(values);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Heap") {
    for (const auto &[values, expected] : test_cases) {
      const auto actual = heap::Solution::maxSpending(values);
      REQUIRE(expected == actual);
    }
  }
}
