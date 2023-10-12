#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> stones;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .stones{0, 1, 3, 5, 6, 8, 12, 17},
          .expected = true,
      },
      {
          .stones{0, 1, 2, 3, 4, 8, 9, 11},
          .expected = false,
      },
  };

  for (const auto &[stones, expected] : test_cases) {
    const auto actual = Solution::canCross(stones);
    REQUIRE(expected == actual);
  }
}
