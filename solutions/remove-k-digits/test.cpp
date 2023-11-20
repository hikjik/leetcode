#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "1432219",
          .k = 3,
          .expected = "1219",
      },
      {
          .num = "10200",
          .k = 1,
          .expected = "200",
      },
      {
          .num = "10",
          .k = 2,
          .expected = "0",
      },
      {
          .num = "1234567890",
          .k = 9,
          .expected = "0",
      },
      {
          .num = "123456789",
          .k = 5,
          .expected = "1234",
      },
      {
          .num = "112",
          .k = 1,
          .expected = "11",
      },
  };

  for (const auto &[num, k, expected] : test_cases) {
    const auto actual = Solution::removeKdigits(num, k);
    REQUIRE(expected == actual);
  }
}
