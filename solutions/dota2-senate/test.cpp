#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string senate;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .senate = "RD",
          .expected = "Radiant",
      },
      {
          .senate = "RDD",
          .expected = "Dire",
      },
  };

  for (const auto &[senate, expected] : test_cases) {
    const auto actual = Solution::predictPartyVictory(senate);
    REQUIRE(expected == actual);
  }
}
