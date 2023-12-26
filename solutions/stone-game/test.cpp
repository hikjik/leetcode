#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> piles;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .piles{5, 3, 4, 5},
          .expected = true,
      },
      {
          .piles{3, 7, 2, 3},
          .expected = true,
      },
  };

  for (const auto &[piles, expected] : test_cases) {
    const auto actual = Solution::stoneGame(piles);
    REQUIRE(expected == actual);
  }
}
