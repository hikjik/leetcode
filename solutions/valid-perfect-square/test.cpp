#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 16,
          .expected = true,
      },
      {
          .num = 14,
          .expected = false,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::isPerfectSquare(num);
    REQUIRE(expected == actual);
  }
}
