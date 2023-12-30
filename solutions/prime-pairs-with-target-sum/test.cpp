#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .expected{{3, 7}, {5, 5}},
      },
      {
          .n = 2,
          .expected{},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::findPrimePairs(n);
    REQUIRE(expected == actual);
  }
}
