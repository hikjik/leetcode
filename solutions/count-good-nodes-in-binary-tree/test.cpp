#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::goodNodes(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{3, 1, 4, 3, std::nullopt, 1, 5};
    int expected = 4;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{3, 3, std::nullopt, 4, 2};
    int expected = 3;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1};
    int expected = 1;
    CheckSolution(values, expected);
  }
}
