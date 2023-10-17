#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    char expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abccbaacz",
          .expected = 'c',
      },
      {
          .s = "abcdd",
          .expected = 'd',
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::repeatedCharacter(s);
    REQUIRE(expected == actual);
  }
}
