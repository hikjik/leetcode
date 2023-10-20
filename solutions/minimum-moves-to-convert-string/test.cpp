#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "XXX",
          .expected = 1,
      },
      {
          .s = "XXOX",
          .expected = 2,
      },
      {
          .s = "OOOO",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minimumMoves(s);
    REQUIRE(expected == actual);
  }
}
