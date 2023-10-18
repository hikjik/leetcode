#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 4325,
          .expected = 59,
      },
      {
          .num = 687,
          .expected = 75,
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::splitNum(num);
    REQUIRE(expected == actual);
  }
}
