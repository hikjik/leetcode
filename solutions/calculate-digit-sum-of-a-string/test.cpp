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
          .s = "11111222223",
          .k = 3,
          .expected = "135",
      },
      {
          .s = "00000000",
          .k = 3,
          .expected = "000",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::digitSum(s, k);
    REQUIRE(expected == actual);
  }
}
