#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ab#c",
          .t = "ad#c",
          .expected = true,
      },
      {
          .s = "ab##",
          .t = "c#d#",
          .expected = true,
      },
      {
          .s = "a#c",
          .t = "b",
          .expected = false,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::backspaceCompare(s, t);
    REQUIRE(expected == actual);
  }
}
