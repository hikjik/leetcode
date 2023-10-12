#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1 + 1",
          .expected = 2,
      },
      {
          .s = " 2-1 + 2 ",
          .expected = 3,
      },
      {
          .s = "(1+(4+5+2)-3)+(6+8)",
          .expected = 23,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::calculate(s);
    REQUIRE(expected == actual);
  }
}
