#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numBottles;
    int numExchange;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numBottles = 9,
          .numExchange = 3,
          .expected = 13,
      },
      {
          .numBottles = 15,
          .numExchange = 4,
          .expected = 19,
      },
  };

  for (const auto &[numBottles, numExchange, expected] : test_cases) {
    const auto actual = Solution::numWaterBottles(numBottles, numExchange);
    REQUIRE(expected == actual);
  }
}
