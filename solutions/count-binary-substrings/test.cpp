#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "00110011",
          .expected = 6,
      },
      {
          .s = "10101",
          .expected = 4,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countBinarySubstrings(s);
    REQUIRE(expected == actual);
  }
}
