#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    long long a;
    long long b;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 12,
          .b = 5,
          .n = 4,
          .expected = 98,
      },
      {
          .a = 6,
          .b = 7,
          .n = 5,
          .expected = 930,
      },
      {
          .a = 1,
          .b = 6,
          .n = 3,
          .expected = 12,
      },
  };

  for (const auto &[a, b, n, expected] : test_cases) {
    const auto actual = Solution::maximumXorProduct(a, b, n);
    REQUIRE(expected == actual);
  }
}
