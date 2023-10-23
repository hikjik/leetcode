#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abacbc",
          .expected = true,
      },
      {
          .s = "aaabb",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::areOccurrencesEqual(s);
    REQUIRE(expected == actual);
  }
}
