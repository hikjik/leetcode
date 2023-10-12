#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "rabbbit",
          .t = "rabbit",
          .expected = 3,
      },
      {
          .s = "babgbag",
          .t = "bag",
          .expected = 5,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::numDistinct(s, t);
    REQUIRE(expected == actual);
  }
}
