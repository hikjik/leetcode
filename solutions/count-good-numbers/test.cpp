#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    long long n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 5,
      },
      {
          .n = 4,
          .expected = 400,
      },
      {
          .n = 50,
          .expected = 564908303,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countGoodNumbers(n);
    REQUIRE(expected == actual);
  }
}
