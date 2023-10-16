#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ilovecodingonleetcode",
          .target = "code",
          .expected = 2,
      },
      {
          .s = "abcba",
          .target = "abc",
          .expected = 1,
      },
      {
          .s = "abbaccaddaeea",
          .target = "aaaaa",
          .expected = 1,
      },
  };

  for (const auto &[s, target, expected] : test_cases) {
    const auto actual = Solution::rearrangeCharacters(s, target);
    REQUIRE(expected == actual);
  }
}
