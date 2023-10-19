#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "RLRRLLRLRL",
          .expected = 4,
      },
      {
          .s = "RLRRRLLRLL",
          .expected = 2,
      },
      {
          .s = "LLLLRRRR",
          .expected = 1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::balancedStringSplit(s);
    REQUIRE(expected == actual);
  }
}
