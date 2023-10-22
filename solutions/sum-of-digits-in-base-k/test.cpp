#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 34,
          .k = 6,
          .expected = 9,
      },
      {
          .n = 10,
          .k = 10,
          .expected = 1,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::sumBase(n, k);
    REQUIRE(expected == actual);
  }
}
