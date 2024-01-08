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
          .s = "ab",
          .t = "acb",
          .expected = true,
      },
      {
          .s = "",
          .t = "",
          .expected = false,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::isOneEditDistance(s, t);
    REQUIRE(expected == actual);
  }
}
