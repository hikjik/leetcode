#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> price;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .price{13, 5, 1, 8, 21, 2},
          .k = 3,
          .expected = 8,
      },
      {
          .price{1, 3, 1},
          .k = 2,
          .expected = 2,
      },
      {
          .price{7, 7, 7, 7},
          .k = 2,
          .expected = 0,
      },
  };

  for (const auto &[price, k, expected] : test_cases) {
    const auto actual = Solution::maximumTastiness(price, k);
    REQUIRE(expected == actual);
  }
}
