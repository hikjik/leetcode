#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values) {
  auto root = VectorToTree(values);
  REQUIRE(values.size() == 1UL * Solution::countNodes(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 3, 4, 5, 6};
    CheckSolution(values);
  }
  {
    std::vector<std::optional<int>> values{1};
    CheckSolution(values);
  }
  {
    std::vector<std::optional<int>> values;
    CheckSolution(values);
  }
}
