#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> piles;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .piles{2, 4, 1, 2, 7, 8},
          .expected = 9,
      },
      {
          .piles{2, 4, 5},
          .expected = 4,
      },
      {
          .piles{9, 8, 7, 6, 5, 1, 2, 3, 4},
          .expected = 18,
      },
  };

  SECTION("STL Sort") {
    for (const auto &[piles, expected] : test_cases) {
      const auto actual = stl_sort::Solution::maxCoins(piles);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting Sort") {
    for (const auto &[piles, expected] : test_cases) {
      const auto actual = counting_sort::Solution::maxCoins(piles);
      REQUIRE(expected == actual);
    }
  }
}
