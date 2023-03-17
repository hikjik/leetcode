#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &first,
                   const std::vector<std::optional<int>> &second,
                   bool expected) {
  auto p = VectorToTree(first);
  auto q = VectorToTree(second);
  REQUIRE(expected == Solution::isSameTree(p, q));

  FreeTree(p);
  FreeTree(q);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> first{1, 2, 3};
    std::vector<std::optional<int>> second{1, 2, 3};
    CheckSolution(first, second, true);
  }
  {
    std::vector<std::optional<int>> first{1, 2};
    std::vector<std::optional<int>> second{1, std::nullopt, 2};
    CheckSolution(first, second, false);
  }
  {
    std::vector<std::optional<int>> first{1, 2, 1};
    std::vector<std::optional<int>> second{1, 1, 2};
    CheckSolution(first, second, false);
  }
}
