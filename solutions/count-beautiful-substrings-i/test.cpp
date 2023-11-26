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
          .s = "baeyh",
          .k = 2,
          .expected = 2,
      },
      {
          .s = "abba",
          .k = 1,
          .expected = 3,
      },
      {
          .s = "bcdf",
          .k = 1,
          .expected = 0,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::beautifulSubstrings(s, k);
    REQUIRE(expected == actual);
  }
}
