#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "a1b2",
          .expected{"a1b2", "a1B2", "A1b2", "A1B2"},
      },
      {
          .s = "3z4",
          .expected{"3z4", "3Z4"},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::letterCasePermutation(s);
    REQUIRE(expected == actual);
  }
}
