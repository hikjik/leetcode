#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "3[a]2[bc]",
          .expected = "aaabcbc",
      },
      {
          .s = "3[a2[c]]",
          .expected = "accaccacc",
      },
      {
          .s = "2[abc]3[cd]ef",
          .expected = "abcabccdcdcdef",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::decodeString(s);
    REQUIRE(expected == actual);
  }
}
