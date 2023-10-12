#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int target;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .target = 5,
          .k = 2,
          .expected{7, 4, 1},
      },
      {
          .root{1},
          .target = 1,
          .k = 3,
          .expected{},
      },
  };

  for (const auto &[root, target, k, expected] : test_cases) {
    const auto actual = Solution::distanceK(root, root.Find(target), k);
    REQUIRE(expected == actual);
  }
}
