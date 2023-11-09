#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aab",
          .expected = 1,
      },
      {
          .s = "a",
          .expected = 0,
      },
      {
          .s = "ab",
          .expected = 1,
      },

  };

  // SECTION("Tabulation") {
  //   for (const auto &[s, expected] : test_cases) {
  //     const auto actual = dp::Solution::minCut(s);
  //     REQUIRE(expected == actual);
  //   }
  // }

  SECTION("Manacher") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = manacher::Solution::minCut(s);
      REQUIRE(expected == actual);
    }
  }
}
