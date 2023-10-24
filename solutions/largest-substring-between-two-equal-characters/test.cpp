#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aa",
          .expected = 0,
      },
      {
          .s = "abca",
          .expected = 2,
      },
      {
          .s = "cbzxy",
          .expected = -1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maxLengthBetweenEqualCharacters(s);
    REQUIRE(expected == actual);
  }
}
