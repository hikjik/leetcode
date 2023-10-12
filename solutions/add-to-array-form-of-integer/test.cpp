#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> num;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num{1, 2, 0, 0},
          .k = 34,
          .expected{1, 2, 3, 4},
      },
      {
          .num{2, 7, 4},
          .k = 181,
          .expected{4, 5, 5},
      },
      {
          .num{2, 1, 5},
          .k = 806,
          .expected{1, 0, 2, 1},
      },
  };

  for (const auto &[num, k, expected] : test_cases) {
    const auto actual = Solution::addToArrayForm(num, k);
    REQUIRE(expected == actual);
  }
}
