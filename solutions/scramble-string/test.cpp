#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "great",
          .s2 = "rgeat",
          .expected = true,
      },
      {
          .s1 = "abcde",
          .s2 = "caebd",
          .expected = false,
      },
      {
          .s1 = "a",
          .s2 = "a",
          .expected = true,
      },
  };

  for (const auto &[s1, s2, expected] : test_cases) {
    const auto actual = Solution().isScramble(s1, s2);
    REQUIRE(expected == actual);
  }
}
