#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 121,
          .expected = true,
      },
      {
          .n = -121,
          .expected = false,
      },
      {
          .n = 10,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isPalindrome(n);
    REQUIRE(expected == actual);
  }
}
