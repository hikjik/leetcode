#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root1;
    Tree root2;
    int target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root1 = {2, 1, 4},
          .root2 = {1, 0, 3},
          .target = 5,
          .expected = true,
      },
      {
          .root1 = {0, -10, 10},
          .root2 = {5, 1, 7, 0, 2},
          .target = 18,
          .expected = false,
      },
  };

  SECTION("Binary Search") {
    for (const auto &[root1, root2, target, expected] : test_cases) {
      const auto actual = bs::Solution::twoSumBSTs(root1, root2, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Two Pointers") {
    for (const auto &[root1, root2, target, expected] : test_cases) {
      const auto actual = tp::Solution::twoSumBSTs(root1, root2, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Morris Traversal") {
    for (const auto &[root1, root2, target, expected] : test_cases) {
      const auto actual = morris::Solution::twoSumBSTs(root1, root2, target);
      REQUIRE(expected == actual);
    }
  }
}
