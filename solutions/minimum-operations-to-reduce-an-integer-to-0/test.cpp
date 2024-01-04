#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 39,
          .expected = 3,
      },
      {
          .n = 54,
          .expected = 3,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::minOperations(n);
    REQUIRE(expected == actual);
  }
}
