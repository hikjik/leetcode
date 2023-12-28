#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaabcccd",
          .k = 2,
          .expected = 4,
      },
      {
          .s = "aabbaa",
          .k = 2,
          .expected = 2,
      },
      {
          .s = "aaaaaaaaaaa",
          .k = 0,
          .expected = 3,
      },
      {
          .s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
          .k = 0,
          .expected = 4,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = memo::Solution::getLengthOfOptimalCompression(s, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = dp::Solution::getLengthOfOptimalCompression(s, k);
      REQUIRE(expected == actual);
    }
  }
}
