#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int k;
    int n;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .k = 3,
          .n = 7,
          .expected{{1, 2, 4}},
      },
      {
          .k = 3,
          .n = 9,
          .expected{{1, 2, 6}, {1, 3, 5}, {2, 3, 4}},
      },
      {
          .k = 4,
          .n = 1,
          .expected{},
      },
  };

  for (const auto &[k, n, expected] : test_cases) {
    const auto actual = Solution::combinationSum3(k, n);
    REQUIRE(expected == actual);
  }
}
