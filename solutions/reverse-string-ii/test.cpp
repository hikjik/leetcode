#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcdefg",
          .k = 2,
          .expected = "bacdfeg",
      },
      {
          .s = "abcd",
          .k = 2,
          .expected = "bacd",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::reverseStr(s, k);
    REQUIRE(expected == actual);
  }
}
