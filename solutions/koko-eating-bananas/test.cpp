#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> piles;
    int h;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .piles{3, 6, 7, 11},
          .h = 8,
          .expected = 4,
      },
      {
          .piles{30, 11, 23, 4, 20},
          .h = 5,
          .expected = 30,
      },
      {
          .piles{30, 11, 23, 4, 20},
          .h = 6,
          .expected = 23,
      },
  };

  for (const auto &[piles, h, expected] : test_cases) {
    const auto actual = Solution::minEatingSpeed(piles, h);
    REQUIRE(expected == actual);
  }
}
