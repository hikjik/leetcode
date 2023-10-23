#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 2932,
          .expected = 52,
      },
      {
          .num = 4009,
          .expected = 13,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::minimumSum(num);
    REQUIRE(expected == actual);
  }
}
