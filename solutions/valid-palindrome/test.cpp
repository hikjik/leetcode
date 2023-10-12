#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "A man, a plan, a canal: Panama",
          .expected = true,
      },
      {
          .s = "race a car",
          .expected = false,
      },
      {
          .s = " ",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::isPalindrome(s);
    REQUIRE(expected == actual);
  }
}
