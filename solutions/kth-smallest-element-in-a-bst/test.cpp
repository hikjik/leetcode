#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int k,
                   int expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::kthSmallest(root, k));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int k = 1, expected = 1;
    std::vector<std::optional<int>> values{3, 1, 4, std::nullopt, 2};
    CheckSolution(values, k, expected);
  }
  {
    int k = 3, expected = 3;
    std::vector<std::optional<int>> values{
        5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1};
    CheckSolution(values, k, expected);
  }
}
