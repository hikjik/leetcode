#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcbdd",
          .expected = true,
      },
      {
          .s = "bcbddxy",
          .expected = false,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::checkPartitioning(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Manacher") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = manacher::Solution::checkPartitioning(s);
      REQUIRE(expected == actual);
    }
  }
}
