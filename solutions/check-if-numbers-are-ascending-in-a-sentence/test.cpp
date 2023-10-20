#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles",
          .expected = true,
      },
      {
          .s = "hello world 5 x 5",
          .expected = false,
      },
      {
          .s = "sunset is at 7 51 pm overnight lows will be in the low 50 and "
               "60 s",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::areNumbersAscending(s);
    REQUIRE(expected == actual);
  }
}
