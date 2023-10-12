#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "lee(t(c)o)de)",
          .expected = "lee(t(c)o)de",
      },
      {
          .s = "a)b(c)d",
          .expected = "ab(c)d",
      },
      {
          .s = "))((",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minRemoveToMakeValid(s);
    REQUIRE(expected == actual);
  }
}
