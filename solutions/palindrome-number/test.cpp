#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 121,
          .expected = true,
      },
      {
          .x = -121,
          .expected = false,
      },
      {
          .x = 10,
          .expected = false,
      },
  };

  for (const auto &[x, expected] : test_cases) {
    const auto actual = Solution::isPalindrome(x);
    REQUIRE(expected == actual);
  }
}
