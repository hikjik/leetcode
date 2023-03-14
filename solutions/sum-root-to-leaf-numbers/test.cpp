#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::sumNumbers(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 3};
    CheckSolution(values, 25);
  }
  {
    std::vector<std::optional<int>> values{4, 9, 0, 5, 1};
    CheckSolution(values, 1026);
  }
}
