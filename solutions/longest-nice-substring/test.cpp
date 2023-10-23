#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "YazaAay",
          .expected = "aAa",
      },
      {
          .s = "Bb",
          .expected = "Bb",
      },
      {
          .s = "c",
          .expected = "",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::longestNiceSubstring(s);
    REQUIRE(expected == actual);
  }
}
