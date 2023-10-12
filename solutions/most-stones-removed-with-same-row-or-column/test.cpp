#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> stones;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .stones{{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}},
          .expected = 5,
      },
      {
          .stones{{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}},
          .expected = 3,
      },
      {
          .stones{{0, 0}},
          .expected = 0,
      },
  };

  for (const auto &[stones, expected] : test_cases) {
    const auto actual = Solution::removeStones(stones);
    REQUIRE(expected == actual);
  }
}
