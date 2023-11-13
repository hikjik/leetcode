#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "lEetcOde",
          .expected = "lEOtcede",
      },
      {
          .s = "lYmpH",
          .expected = "lYmpH",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::sortVowels(s);
    REQUIRE(expected == actual);
  }
}
