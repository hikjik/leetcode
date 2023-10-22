#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "PPALLP",
          .expected = true,
      },
      {
          .s = "PPALLL",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::checkRecord(s);
    REQUIRE(expected == actual);
  }
}
