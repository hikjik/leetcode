#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> colors;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .colors{1, 1, 1, 6, 1, 1, 1},
          .expected = 3,
      },
      {
          .colors{1, 8, 3, 8, 3},
          .expected = 4,
      },
      {
          .colors{0, 1},
          .expected = 1,
      },
  };

  for (const auto &[colors, expected] : test_cases) {
    const auto actual = Solution::maxDistance(colors);
    REQUIRE(expected == actual);
  }
}
