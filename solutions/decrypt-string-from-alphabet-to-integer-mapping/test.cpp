#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "10#11#12",
          .expected = "jkab",
      },
      {
          .s = "1326#",
          .expected = "acz",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::freqAlphabets(s);
    REQUIRE(expected == actual);
  }
}
