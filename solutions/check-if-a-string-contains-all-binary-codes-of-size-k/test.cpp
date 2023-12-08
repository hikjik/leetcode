#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "00110110",
          .k = 2,
          .expected = true,
      },
      {
          .s = "0110",
          .k = 1,
          .expected = true,
      },
      {
          .s = "0110",
          .k = 2,
          .expected = false,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::hasAllCodes(s, k);
    REQUIRE(expected == actual);
  }
}
