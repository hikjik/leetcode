#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}},
      },
      {
          .n = 1,
          .expected{{1}},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::generateMatrix(n);
    REQUIRE(expected == actual);
  }
}
