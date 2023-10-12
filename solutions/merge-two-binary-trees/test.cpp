#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root1;
    Tree root2;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root1{1, 3, 2, 5},
          .root2{2, 1, 3, std::nullopt, 4, std::nullopt, 7},
          .expected{3, 4, 5, 5, 4, std::nullopt, 7},
      },
      {
          .root1{1},
          .root2{1, 2},
          .expected{2, 2},
      },
  };

  for (const auto &[root1, root2, expected] : test_cases) {
    const Tree actual = Solution::mergeTrees(root1, root2);
    REQUIRE(expected == actual);
  }
}
