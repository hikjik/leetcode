#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int target,
                   const std::vector<std::vector<int>> &paths) {
  auto root = VectorToTree(values);

  REQUIRE(paths == Solution::pathSum(root, target));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int target = 22;
    std::vector<std::optional<int>> values{
        5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt,
        5, 1};
    std::vector<std::vector<int>> paths{{5, 4, 11, 2}, {5, 8, 4, 5}};
    CheckSolution(values, target, paths);
  }
  {
    int target = 5;
    std::vector<std::optional<int>> values{1, 2, 3};
    std::vector<std::vector<int>> paths;
    CheckSolution(values, target, paths);
  }
  {
    int target = 0;
    std::vector<std::optional<int>> values{1, 2};
    std::vector<std::vector<int>> paths;
    CheckSolution(values, target, paths);
  }
  {
    int target = 0;
    std::vector<std::optional<int>> values{1};
    std::vector<std::vector<int>> paths;
    CheckSolution(values, target, paths);
  }
  {
    int target = 1;
    std::vector<std::optional<int>> values{1};
    std::vector<std::vector<int>> paths{{1}};
    CheckSolution(values, target, paths);
  }
  {
    int target = 0;
    std::vector<std::optional<int>> values;
    std::vector<std::vector<int>> paths;
    CheckSolution(values, target, paths);
  }
}
