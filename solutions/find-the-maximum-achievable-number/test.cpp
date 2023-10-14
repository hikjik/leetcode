#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    int t;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 4,
          .t = 1,
          .expected = 6,
      },
      {
          .num = 3,
          .t = 2,
          .expected = 7,
      },
  };

  for (const auto &[num, t, expected] : test_cases) {
    const auto actual = Solution::theMaximumAchievableX(num, t);
    REQUIRE(expected == actual);
  }
}
