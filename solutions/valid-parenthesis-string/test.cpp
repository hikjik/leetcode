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
          .s = "(*)",
          .expected = true,
      },
      {
          .s = "(*))",
          .expected = true,
      },
  };

  SECTION("STACK") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = stack::Solution::checkValidString(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("MEMORY OPTIMIZED") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = opt::Solution::checkValidString(s);
      REQUIRE(expected == actual);
    }
  }
}
