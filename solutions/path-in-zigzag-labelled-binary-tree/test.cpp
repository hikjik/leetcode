#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int label;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .label = 14,
          .expected{1, 3, 4, 14},
      },
      {
          .label = 26,
          .expected{1, 2, 6, 10, 26},
      },
  };

  for (const auto &[label, expected] : test_cases) {
    const auto actual = Solution::pathInZigZagTree(label);
    REQUIRE(expected == actual);
  }
}
