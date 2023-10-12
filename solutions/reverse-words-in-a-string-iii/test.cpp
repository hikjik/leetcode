#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "Let's take LeetCode contest",
          .expected = "s'teL ekat edoCteeL tsetnoc",
      },
      {
          .s = "God Ding",
          .expected = "doG gniD",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::reverseWords(s);
    REQUIRE(expected == actual);
  }
}
