#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> capacity;
    std::vector<int> rocks;
    int additionalRocks;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .capacity{2, 3, 4, 5},
          .rocks{1, 2, 4, 4},
          .additionalRocks = 2,
          .expected = 3,
      },
      {
          .capacity{10, 2, 2},
          .rocks{2, 2, 0},
          .additionalRocks = 100,
          .expected = 3,
      },
  };

  for (const auto &[capacity, rocks, additionalRocks, expected] : test_cases) {
    const auto actual = Solution::maximumBags(capacity, rocks, additionalRocks);
    REQUIRE(expected == actual);
  }
}
