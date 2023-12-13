#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aacaba",
          .expected = 2,
      },
      {
          .s = "abcd",
          .expected = 1,
      },
  };

  SECTION("Hash Table") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = hash_table::Solution::numSplits(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sliding Window") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = sliding_window::Solution::numSplits(s);
      REQUIRE(expected == actual);
    }
  }
}
