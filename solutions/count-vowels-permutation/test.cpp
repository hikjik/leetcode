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
          .expected = 5,
      },
      {
          .n = 2,
          .expected = 10,
      },
      {
          .n = 5,
          .expected = 68,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countVowelPermutation(n);
    REQUIRE(expected == actual);
  }
}
