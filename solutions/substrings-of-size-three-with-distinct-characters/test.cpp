#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "xyzzaz",
          .expected = 1,
      },
      {
          .s = "aababcabc",
          .expected = 4,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countGoodSubstrings(s);
    REQUIRE(expected == actual);
  }
}
