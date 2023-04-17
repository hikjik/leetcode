#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::optional<int>> &flatten_values) {
  auto root = VectorToTree(values);
  auto flatten = VectorToTree(flatten_values);

  Solution::flatten(root);

  REQUIRE(EqualTree(root, flatten));

  FreeTree(root);
  FreeTree(flatten);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 5, 3, 4, std::nullopt, 6};
    std::vector<std::optional<int>> flatten{1, std::nullopt, 2, std::nullopt,
                                            3, std::nullopt, 4, std::nullopt,
                                            5, std::nullopt, 6};
    CheckSolution(values, flatten);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<std::optional<int>> flatten;
    CheckSolution(values, flatten);
  }
  {
    std::vector<std::optional<int>> values{0};
    std::vector<std::optional<int>> flatten{0};
    CheckSolution(values, flatten);
  }
}
