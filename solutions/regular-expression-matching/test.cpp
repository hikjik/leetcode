#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string p;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aa",
          .p = "a",
          .expected = false,
      },
      {
          .s = "aa",
          .p = "a*",
          .expected = true,
      },
      {
          .s = "ab",
          .p = ".*",
          .expected = true,
      },
      {
          .s = "aa",
          .p = "a*",
          .expected = true,
      },
  };

  for (const auto &[s, p, expected] : test_cases) {
    const auto actual = Solution::isMatch(s, p);
    REQUIRE(expected == actual);
  }
}
