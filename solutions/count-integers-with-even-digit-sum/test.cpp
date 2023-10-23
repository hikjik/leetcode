#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 4,
          .expected = 2,
      },
      {
          .num = 30,
          .expected = 14,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::countEven(num);
    REQUIRE(expected == actual);
  }
}
