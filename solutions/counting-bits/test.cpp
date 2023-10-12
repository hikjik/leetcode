#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected{0, 1, 1},
      },
      {
          .n = 5,
          .expected{0, 1, 1, 2, 1, 2},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countBits(n);
    REQUIRE(expected == actual);
  }
}
