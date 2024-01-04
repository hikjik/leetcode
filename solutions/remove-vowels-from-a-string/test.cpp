#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetcodeisacommunityforcoders",
          .expected = "ltcdscmmntyfrcdrs",
      },
      {
          .s = "aeiou",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::removeVowels(s);
    REQUIRE(expected == actual);
  }
}
