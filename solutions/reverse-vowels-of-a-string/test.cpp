#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "hello",
          .expected = "holle",
      },
      {
          .s = "leetcode",
          .expected = "leotcede",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::reverseVowels(s);
    REQUIRE(expected == actual);
  }
}
