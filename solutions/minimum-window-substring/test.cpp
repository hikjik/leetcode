#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ADOBECODEBANC",
          .t = "ABC",
          .expected = "BANC",
      },
      {
          .s = "a",
          .t = "a",
          .expected = "a",
      },
      {
          .s = "a",
          .t = "aa",
          .expected = "",
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::minWindow(s, t);
    REQUIRE(expected == actual);
  }
}
