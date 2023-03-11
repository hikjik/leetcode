#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &values) {
  auto head = VectorToList(values);
  auto root = Solution::sortedListToBST(head);

  REQUIRE(isValidBST(root));
  REQUIRE(isBalanced(root));
  REQUIRE(values == TraverseInOrder(root));

  FreeList(head);
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{-10, -3, 0, 5, 9};
    CheckSolution(values);
  }
  {
    std::vector<int> values{1, 2, 3};
    CheckSolution(values);
  }
  {
    std::vector<int> values{1, 2};
    CheckSolution(values);
  }
  {
    std::vector<int> values{1};
    CheckSolution(values);
  }
  {
    std::vector<int> values;
    CheckSolution(values);
  }
}
