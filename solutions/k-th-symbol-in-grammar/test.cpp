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
          .n = 1,
          .k = 1,
          .expected = 0,
      },
      {
          .n = 2,
          .k = 1,
          .expected = 0,
      },
      {
          .n = 2,
          .k = 2,
          .expected = 1,
      },
      {
          .n = 3,
          .k = 1,
          .expected = 0,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::kthGrammar(n, k);
    REQUIRE(expected == actual);
  }
}
