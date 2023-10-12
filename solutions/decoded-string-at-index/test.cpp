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
          .s = "leet2code3",
          .k = 10,
          .expected = "o",
      },
      {
          .s = "ha22",
          .k = 5,
          .expected = "h",
      },
      {
          .s = "a2345678999999999999999",
          .k = 1,
          .expected = "a",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::decodeAtIndex(s, k);
    REQUIRE(expected == actual);
  }
}
