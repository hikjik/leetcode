#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = 1,
      },
      {
          .n = 4,
          .expected = 2,
      },
      {
          .n = 6,
          .expected = 4,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::reinitializePermutation(n);
    REQUIRE(expected == actual);
  }
}
