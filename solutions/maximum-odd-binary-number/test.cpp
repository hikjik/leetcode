#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "010",
          .expected = "001",
      },
      {
          .s = "0101",
          .expected = "1001",
      },
      {
          .s = "1",
          .expected = "1",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maximumOddBinaryNumber(s);
    REQUIRE(expected == actual);
  }
}
