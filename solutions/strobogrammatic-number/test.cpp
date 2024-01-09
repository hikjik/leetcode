#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = "69",
          .expected = true,
      },
      {
          .num = "88",
          .expected = true,
      },
      {
          .num = "962",
          .expected = false,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::isStrobogrammatic(num);
    REQUIRE(expected == actual);
  }
}
