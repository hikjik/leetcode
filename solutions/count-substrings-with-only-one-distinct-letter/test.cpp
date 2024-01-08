#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaaba",
          .expected = 8,
      },
      {
          .s = "aaaaaaaaaa",
          .expected = 55,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countLetters(s);
    REQUIRE(expected == actual);
  }
}
