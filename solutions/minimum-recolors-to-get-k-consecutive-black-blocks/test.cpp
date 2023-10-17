#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string blocks;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .blocks = "WBBWWBBWBW",
          .k = 7,
          .expected = 3,
      },
      {
          .blocks = "WBWBBBW",
          .k = 2,
          .expected = 0,
      },
  };

  for (const auto &[blocks, k, expected] : test_cases) {
    const auto actual = Solution::minimumRecolors(blocks, k);
    REQUIRE(expected == actual);
  }
}
