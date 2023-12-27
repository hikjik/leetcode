#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abaccdbbd",
          .k = 3,
          .expected = 2,
      },
      {
          .s = "adbcda",
          .k = 2,
          .expected = 0,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::maxPalindromes(s, k);
    REQUIRE(expected == actual);
  }
}
