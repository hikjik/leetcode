#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    int x;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "10010111001",
          .s2 = "11101011110",
          .x = 1,
          .expected = 4,
      },
      {
          .s1 = "1100011000",
          .s2 = "0101001010",
          .x = 2,
          .expected = 4,
      },
      {
          .s1 = "101101",
          .s2 = "000000",
          .x = 6,
          .expected = 4,
      },
      {
          .s1 = "110111",
          .s2 = "100000",
          .x = 2,
          .expected = 3,
      },
      {
          .s1 = "10110",
          .s2 = "00011",
          .x = 4,
          .expected = -1,
      },
      {
          .s1 = "11001",
          .s2 = "11001",
          .x = 4,
          .expected = 0,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s1, s2, x, expected] : test_cases) {
      const auto actual = memo::Solution::minOperations(s1, s2, x);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s1, s2, x, expected] : test_cases) {
      const auto actual = dp::Solution::minOperations(s1, s2, x);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[s1, s2, x, expected] : test_cases) {
      const auto actual = optimized::Solution::minOperations(s1, s2, x);
      REQUIRE(expected == actual);
    }
  }
}
