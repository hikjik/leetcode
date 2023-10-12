#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>
#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{-10, -3, 0, 5, 9},
          .expected{0, -3, 9, -10, std::nullopt, 5},
      },
      {
          .head{},
          .expected{},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const Tree actual = Solution::sortedListToBST(head);

    REQUIRE(actual.IsValidBST());
    REQUIRE(actual.IsBalanced());
    REQUIRE(expected.Traverse(Tree::Order::kInOrder) ==
            actual.Traverse(Tree::Order::kInOrder));
  }
}
