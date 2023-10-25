#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .expected = 6,
      },
      {
          .n = 14,
          .expected = 13,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::numberOfMatches(n);
    REQUIRE(expected == actual);
  }
}
