#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "bcabc",
          .expected = "abc",
      },
      {
          .s = "cbacdcbc",
          .expected = "acdb",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::smallestSubsequence(s);
    REQUIRE(expected == actual);
  }
}
