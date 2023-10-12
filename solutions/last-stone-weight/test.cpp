#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> stones;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .stones{2, 7, 4, 1, 8, 1},
          .expected = 1,
      },
      {
          .stones{1},
          .expected = 1,
      },
  };

  for (const auto &[stones, expected] : test_cases) {
    const auto actual = Solution::lastStoneWeight(stones);
    REQUIRE(expected == actual);
  }
}
