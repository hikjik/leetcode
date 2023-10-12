#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "3+2*2",
          .expected = 7,
      },
      {
          .s = " 3/2 ",
          .expected = 1,
      },
      {
          .s = " 3+5 / 2 ",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::calculate(s);
    REQUIRE(expected == actual);
  }
}
