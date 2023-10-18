#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 11891,
          .expected = 99009,
      },
      {
          .num = 90,
          .expected = 99,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::minMaxDifference(num);
    REQUIRE(expected == actual);
  }
}
