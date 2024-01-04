#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> workers;
    std::vector<std::vector<int>> bikes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .workers{{0, 0}, {2, 1}},
          .bikes{{1, 2}, {3, 3}},
          .expected = 6,
      },
      {
          .workers{{0, 0}, {1, 1}, {2, 0}},
          .bikes{{1, 0}, {2, 2}, {2, 1}},
          .expected = 4,
      },
      {
          .workers{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}},
          .bikes{{0, 999}, {1, 999}, {2, 999}, {3, 999}, {4, 999}},
          .expected = 4995,
      },
  };

  SECTION("Memoization") {
    for (const auto &[workers, bikes, expected] : test_cases) {
      const auto actual = memo::Solution::assignBikes(workers, bikes);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[workers, bikes, expected] : test_cases) {
      const auto actual = dp::Solution::assignBikes(workers, bikes);
      REQUIRE(expected == actual);
    }
  }
}
