#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaabbb",
          .expected = true,
      },
      {
          .s = "abab",
          .expected = false,
      },
      {
          .s = "bbb",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::checkString(s);
    REQUIRE(expected == actual);
  }
}
