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
          .n = 3,
          .k = 0,
          .expected = 1,
      },
      {
          .n = 3,
          .k = 1,
          .expected = 2,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::kInversePairs(n, k);
    REQUIRE(expected == actual);
  }
}
