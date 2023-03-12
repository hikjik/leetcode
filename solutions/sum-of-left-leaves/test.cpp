#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::sumOfLeftLeaves(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    CheckSolution(values, 24);
  }
  {
    std::vector<std::optional<int>> values{1};
    CheckSolution(values, 0);
  }
}
