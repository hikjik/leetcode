#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> ranges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .ranges{3, 4, 1, 1, 0, 0},
          .expected = 1,
      },
      {
          .n = 3,
          .ranges{0, 0, 0, 0},
          .expected = -1,
      },
  };

  for (const auto &[n, ranges, expected] : test_cases) {
    const auto actual = Solution::minTaps(n, ranges);
    REQUIRE(expected == actual);
  }
}
