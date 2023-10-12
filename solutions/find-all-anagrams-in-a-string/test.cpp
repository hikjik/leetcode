#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string p;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "cbaebabacd",
          .p = "abc",
          .expected{0, 6},
      },
      {
          .s = "abab",
          .p = "ab",
          .expected{0, 1, 2},
      },
  };

  for (const auto &[s, p, expected] : test_cases) {
    const auto actual = Solution::findAnagrams(s, p);
    REQUIRE(expected == actual);
  }
}
