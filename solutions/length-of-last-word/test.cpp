#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "Hello World",
          .expected = 5,
      },
      {
          .s = "   fly me   to   the moon  ",
          .expected = 4,
      },
      {
          .s = "luffy is still joyboy",
          .expected = 6,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::lengthOfLastWord(s);
    REQUIRE(expected == actual);
  }
}
