#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int purchaseAmount;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .purchaseAmount = 9,
          .expected = 90,
      },
      {
          .purchaseAmount = 15,
          .expected = 80,
      },
      {
          .purchaseAmount = 11,
          .expected = 90,
      },
  };

  for (const auto &[purchaseAmount, expected] : test_cases) {
    const auto actual = Solution::accountBalanceAfterPurchase(purchaseAmount);
    REQUIRE(expected == actual);
  }
}
