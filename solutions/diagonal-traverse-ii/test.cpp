#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{{1, 2, 3}, {4}, {5, 6}},
          .expected{1, 4, 2, 5, 3, 6},
      },
      {
          .nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .expected{1, 4, 2, 7, 5, 3, 8, 6, 9},
      },
      {
          .nums{
              {1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}},
          .expected{1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16},
      },
  };

  SECTION("Hash Table") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = hash_table::Solution::findDiagonalOrder(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("BFS") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = bfs::Solution::findDiagonalOrder(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = optimized::Solution::findDiagonalOrder(nums);
      REQUIRE(expected == actual);
    }
  }
}
