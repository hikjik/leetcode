#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 38,
          .expected = 2,
      },
      {
          .num = 0,
          .expected = 0,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::addDigits(num);
    REQUIRE(expected == actual);
  }
}
