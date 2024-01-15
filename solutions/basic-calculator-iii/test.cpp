#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1+1",
          .expected = 2,
      },
      {
          .s = "6-4/2",
          .expected = 4,
      },
      {
          .s = "2*(5+5*2)/3+(6/2+8)",
          .expected = 21,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::calculate(s);
    REQUIRE(expected == actual);
  }
}
