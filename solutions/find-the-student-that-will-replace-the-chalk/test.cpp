#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> chalk;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .chalk{5, 1, 5},
          .k = 22,
          .expected = 0,
      },
      {
          .chalk{3, 4, 1, 2},
          .k = 25,
          .expected = 1,
      },
  };

  for (const auto &[chalk, k, expected] : test_cases) {
    const auto actual = Solution::chalkReplacer(chalk, k);
    REQUIRE(expected == actual);
  }
}
