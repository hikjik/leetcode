#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1001",
          .expected = false,
      },
      {
          .s = "110",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::checkOnesSegment(s);
    REQUIRE(expected == actual);
  }
}