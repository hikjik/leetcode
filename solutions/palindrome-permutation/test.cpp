#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "code",
          .expected = false,
      },
      {
          .s = "aab",
          .expected = true,
      },
      {
          .s = "carerac",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::canPermutePalindrome(s);
    REQUIRE(expected == actual);
  }
}
