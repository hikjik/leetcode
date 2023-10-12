#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 1,
      },
      {
          .n = 2,
          .expected = 6,
      },
      {
          .n = 3,
          .expected = 90,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countOrders(n);
    REQUIRE(expected == actual);
  }
}
