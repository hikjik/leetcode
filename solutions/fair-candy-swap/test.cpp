#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> aliceSizes;
    std::vector<int> bobSizes;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .aliceSizes{1, 1},
          .bobSizes{2, 2},
          .expected{1, 2},
      },
      {
          .aliceSizes{1, 2},
          .bobSizes{2, 3},
          .expected{1, 2},
      },
      {
          .aliceSizes{2},
          .bobSizes{1, 3},
          .expected{2, 3},
      },
  };

  for (const auto &[aliceSizes, bobSizes, expected] : test_cases) {
    const auto actual = Solution::fairCandySwap(aliceSizes, bobSizes);
    REQUIRE(expected == actual);
  }
}
