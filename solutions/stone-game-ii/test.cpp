#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> piles;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .piles{2, 7, 9, 4, 4},
          .expected = 10,
      },
      {
          .piles{1, 2, 3, 4, 5, 100},
          .expected = 104,
      },
  };

  for (const auto &[piles, expected] : test_cases) {
    const auto actual = Solution().stoneGameII(piles);
    REQUIRE(expected == actual);
  }
}
