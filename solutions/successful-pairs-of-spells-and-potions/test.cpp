#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> spells;
    std::vector<int> potions;
    long long success;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .spells{5, 1, 3},
          .potions{1, 2, 3, 4, 5},
          .success = 7,
          .expected{4, 0, 3},
      },
      {
          .spells{3, 1, 2},
          .potions{8, 5, 8},
          .success = 16,
          .expected{2, 0, 2},
      },
  };

  for (const auto &[spells, potions, success, expected] : test_cases) {
    const auto actual = Solution::successfulPairs(spells, potions, success);
    REQUIRE(expected == actual);
  }
}
