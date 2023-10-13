#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 16,
          .expected = true,
      },
      {
          .n = 5,
          .expected = false,
      },
      {
          .n = 1,
          .expected = true,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isPowerOfFour(n);
    REQUIRE(expected == actual);
  }
}
