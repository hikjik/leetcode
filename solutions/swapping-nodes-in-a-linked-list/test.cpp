#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(int k, const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  Solution::swapNodes(head, k);
  REQUIRE(expected == ListToVector(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 4, 3, 2, 5};
    CheckSolution(k, values, expected);
  }
  {
    int k = 5;
    std::vector<int> values{7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
    std::vector<int> expected{7, 9, 6, 6, 8, 7, 3, 0, 9, 5};
    CheckSolution(k, values, expected);
  }
}
