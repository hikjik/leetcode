#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 13,
          .expected{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9},
      },
      {
          .n = 2,
          .expected{1, 2},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::lexicalOrder(n);
    REQUIRE(expected == actual);
  }
}
