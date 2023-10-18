#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int money;
    int children;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .money = 20,
          .children = 3,
          .expected = 1,
      },
      {
          .money = 16,
          .children = 2,
          .expected = 2,
      },
  };

  for (const auto &[money, children, expected] : test_cases) {
    const auto actual = Solution::distMoney(money, children);
    REQUIRE(expected == actual);
  }
}
