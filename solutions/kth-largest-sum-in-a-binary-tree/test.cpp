#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {5, 8, 9, 2, 1, 3, 7, 4, 6},
          .k = 2,
          .expected = 13,
      },
      {
          .root = {1, 2, std::nullopt, 3},
          .k = 1,
          .expected = 3,
      },
  };

  SECTION("Priority Queue + BFS") {
    for (const auto &[root, k, expected] : test_cases) {
      const auto actual = pq::Solution::kthLargestLevelSum(root, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("NthElement + BFS") {
    for (const auto &[root, k, expected] : test_cases) {
      const auto actual = bfs::Solution::kthLargestLevelSum(root, k);
      REQUIRE(expected == actual);
    }
  }
  SECTION("NthElement + DFS") {
    for (const auto &[root, k, expected] : test_cases) {
      const auto actual = dfs::Solution::kthLargestLevelSum(root, k);
      REQUIRE(expected == actual);
    }
  }
}
