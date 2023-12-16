#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "annabelle",
          .k = 2,
          .expected = true,
      },
      {
          .s = "leetcode",
          .k = 3,
          .expected = false,
      },
      {
          .s = "true",
          .k = 4,
          .expected = true,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::canConstruct(s, k);
    REQUIRE(expected == actual);
  }
}
