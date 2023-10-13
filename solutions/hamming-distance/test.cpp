#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    int y;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 1,
          .y = 4,
          .expected = 2,
      },
      {
          .x = 3,
          .y = 1,
          .expected = 1,
      },
  };

  for (const auto &[x, y, expected] : test_cases) {
    const auto actual = Solution::hammingDistance(x, y);
    REQUIRE(expected == actual);
  }
}
