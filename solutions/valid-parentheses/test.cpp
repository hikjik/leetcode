#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "()",
          .expected = true,
      },
      {
          .s = "()[]{}",
          .expected = true,
      },
      {
          .s = "(]",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::isValid(s);
    REQUIRE(expected == actual);
  }
}
