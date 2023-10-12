#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string goal;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ab",
          .goal = "ba",
          .expected = true,
      },
      {
          .s = "ab",
          .goal = "ab",
          .expected = false,
      },
      {
          .s = "aa",
          .goal = "aa",
          .expected = true,
      },
  };

  for (const auto &[s, goal, expected] : test_cases) {
    const auto actual = Solution::buddyStrings(s, goal);
    REQUIRE(expected == actual);
  }
}
