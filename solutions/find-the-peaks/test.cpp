#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> mountain;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mountain{2, 4, 4},
          .expected{},
      },
      {
          .mountain{1, 4, 3, 8, 5},
          .expected{1, 3},
      },
  };

  for (const auto &[mountain, expected] : test_cases) {
    const auto actual = Solution::findPeaks(mountain);
    REQUIRE(expected == actual);
  }
}
