#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    std::string baseStr;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "parker",
          .s2 = "morris",
          .baseStr = "parser",
          .expected = "makkek",
      },
      {
          .s1 = "hello",
          .s2 = "world",
          .baseStr = "hold",
          .expected = "hdld",
      },
      {
          .s1 = "leetcode",
          .s2 = "programs",
          .baseStr = "sourcecode",
          .expected = "aauaaaaada",
      },
  };

  for (const auto &[s1, s2, baseStr, expected] : test_cases) {
    const auto actual = Solution::smallestEquivalentString(s1, s2, baseStr);
    REQUIRE(expected == actual);
  }
}
