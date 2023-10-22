#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "111000",
          .expected = false,
      },
      {
          .s = "1101",
          .expected = true,
      },
      {
          .s = "110100010",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::checkZeroOnes(s);
    REQUIRE(expected == actual);
  }
}
