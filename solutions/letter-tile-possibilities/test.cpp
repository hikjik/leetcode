#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string tiles;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tiles = "AAB",
          .expected = 8,
      },
      {
          .tiles = "AAABBC",
          .expected = 188,
      },
      {
          .tiles = "V",
          .expected = 1,
      },
  };

  for (const auto &[tiles, expected] : test_cases) {
    const auto actual = Solution::numTilePossibilities(tiles);
    REQUIRE(expected == actual);
  }
}
