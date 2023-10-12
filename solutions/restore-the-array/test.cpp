#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "1000",
          .k = 10000,
          .expected = 1,
      },
      {
          .s = "1000",
          .k = 10,
          .expected = 0,
      },
      {
          .s = "1317",
          .k = 2000,
          .expected = 8,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::numberOfArrays(s, k);
    REQUIRE(expected == actual);
  }
}
