#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> amount;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .amount{1, 4, 2},
          .expected = 4,
      },
      {
          .amount{5, 4, 4},
          .expected = 7,
      },
      {
          .amount{5, 0, 0},
          .expected = 5,
      },
  };

  for (const auto &[amount, expected] : test_cases) {
    const auto actual = Solution::fillCups(amount);
    REQUIRE(expected == actual);
  }
}
