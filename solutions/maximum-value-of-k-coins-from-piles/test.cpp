#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> piles;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .piles{{1, 100, 3}, {7, 8, 9}},
          .k = 2,
          .expected = 101,
      },
      {
          .piles{{100},
                 {100},
                 {100},
                 {100},
                 {100},
                 {100},
                 {1, 1, 1, 1, 1, 1, 700}},
          .k = 7,
          .expected = 706,
      },
  };

  for (const auto &[piles, k, expected] : test_cases) {
    const auto actual = Solution::maxValueOfCoins(piles, k);
    REQUIRE(expected == actual);
  }
}
