#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int numRows;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "PAYPALISHIRING",
          .numRows = 3,
          .expected = "PAHNAPLSIIGYIR",
      },
      {
          .s = "PAYPALISHIRING",
          .numRows = 4,
          .expected = "PINALSIGYAHRPI",
      },
      {
          .s = "A",
          .numRows = 1,
          .expected = "A",
      },
  };

  for (const auto &[s, numRows, expected] : test_cases) {
    const auto actual = Solution::convert(s, numRows);
    REQUIRE(expected == actual);
  }
}
