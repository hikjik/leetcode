#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "52",
          .expected = "5",
      },
      {
          .num = "4206",
          .expected = "",
      },
      {
          .num = "35427",
          .expected = "35427",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::largestOddNumber(num);
    REQUIRE(expected == actual);
  }
}
