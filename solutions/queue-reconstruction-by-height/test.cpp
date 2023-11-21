#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> people;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}},
          .expected{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}},
      },
      {
          .people{{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}},
          .expected{{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}},
      },
  };

  SECTION("Naive") {
    for (const auto &[people, expected] : test_cases) {
      const auto actual = naive::Solution::reconstructQueue(people);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Ordered Set") {
    for (const auto &[people, expected] : test_cases) {
      const auto actual = oset::Solution::reconstructQueue(people);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick") {
    for (const auto &[people, expected] : test_cases) {
      const auto actual = bit::Solution::reconstructQueue(people);
      REQUIRE(expected == actual);
    }
  }
}
