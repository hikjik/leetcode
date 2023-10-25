#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree tree;
    int target;
  };

  std::vector<TestCase> test_cases{
      {
          .tree = {7, 4, 3, std::nullopt, std::nullopt, 6, 19},
          .target = 3,
      },
      {
          .tree = {7},
          .target = 7,
      },
      {
          .tree = {8, std::nullopt, 6, std::nullopt, 5, std::nullopt, 4,
                   std::nullopt, 3, std::nullopt, 2, std::nullopt, 1},
          .target = 4,
      },
  };

  for (const auto &[tree, target] : test_cases) {
    auto cloned = tree;
    auto *actual = Solution::getTargetCopy(tree, cloned, tree.Find(target));
    REQUIRE(cloned.Find(target) == actual);
  }
}
