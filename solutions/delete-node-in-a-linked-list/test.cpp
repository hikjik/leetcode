#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(int value, const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto root = VectorToList(values);

  auto node = root;
  while (node && node->val != value) {
    node = node->next;
  }
  Solution::deleteNode(node);
  REQUIRE(expected == ListToVector(root));
  FreeList(root);
}

TEST_CASE("Simple") {
  {
    int value = 5;
    std::vector<int> values{4, 5, 1, 9};
    std::vector<int> expected{4, 1, 9};
    CheckSolution(value, values, expected);
  }
  {
    int value = 1;
    std::vector<int> values{4, 5, 1, 9};
    std::vector<int> expected{4, 5, 9};
    CheckSolution(value, values, expected);
  }
  {
    int value = 4;
    std::vector<int> values{4, 5, 1, 9};
    std::vector<int> expected{5, 1, 9};
    CheckSolution(value, values, expected);
  }
}
