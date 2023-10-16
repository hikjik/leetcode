#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "1210",
          .expected = true,
      },
      {
          .num = "030",
          .expected = false,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::digitCount(num);
    REQUIRE(expected == actual);
  }
}
