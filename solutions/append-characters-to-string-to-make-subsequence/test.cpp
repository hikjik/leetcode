#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "coaching",
          .t = "coding",
          .expected = 4,
      },
      {
          .s = "abcde",
          .t = "a",
          .expected = 0,
      },
      {
          .s = "z",
          .t = "abcde",
          .expected = 5,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::appendCharacters(s, t);
    REQUIRE(expected == actual);
  }
}
