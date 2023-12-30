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
          .n = 2,
          .k = 2,
          .expected = 2,
      },
      {
          .n = 12,
          .k = 3,
          .expected = 3,
      },
      {
          .n = 7,
          .k = 2,
          .expected = 7,
      },
      {
          .n = 4,
          .k = 4,
          .expected = -1,
      },
      {
          .n = 25,
          .k = 3,
          .expected = 25,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::kthFactor(n, k);
    REQUIRE(expected == actual);
  }
}
