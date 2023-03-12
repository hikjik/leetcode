#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   bool is_valid) {
  auto root = VectorToTree(values);

  REQUIRE(is_valid == Solution::isValidBST(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{2, 1, 3};
    CheckSolution(values, true);
  }
  {
    std::vector<std::optional<int>> values{5, 1, 4, std::nullopt, std::nullopt,
                                           3, 6};
    CheckSolution(values, false);
  }
  {
    std::vector<std::optional<int>> values{5, 4, 6, std::nullopt, std::nullopt,
                                           3, 7};
    CheckSolution(values, false);
  }
  {
    std::vector<std::optional<int>> values{2, 2, 2};
    CheckSolution(values, false);
  }
}
