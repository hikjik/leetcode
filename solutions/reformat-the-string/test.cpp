#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "a0b1c2",
          .expected = "0a1b2c",
      },
      {
          .s = "a0b1c2d",
          .expected = "a0b1c2d",
      },
      {
          .s = "leetcode",
          .expected = "",
      },
      {
          .s = "1229857369",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::reformat(s);

    REQUIRE(expected == actual);
  }
}
