#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .k = 2,
          .expected{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}},
      },
      {
          .n = 1,
          .k = 1,
          .expected{{1}},
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::combine(n, k);
    REQUIRE(expected == actual);
  }
}
