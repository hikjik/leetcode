#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(std::vector<std::optional<int>> values, int diameter) {
  auto root = VectorToTree(values);
  REQUIRE(diameter == Solution::diameterOfBinaryTree(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int diameter = 3;
    std::vector<std::optional<int>> values{1, 2, 3, 4, 5};
    CheckSolution(values, diameter);
  }
  {
    int diameter = 1;
    std::vector<std::optional<int>> values{1, 2};
    CheckSolution(values, diameter);
  }
  {
    int diameter = 0;
    std::vector<std::optional<int>> values{1};
    CheckSolution(values, diameter);
  }
}
