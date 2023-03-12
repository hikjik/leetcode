#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int target,
                   int cnt) {
  auto root = VectorToTree(values);
  REQUIRE(cnt == Solution::pathSum(root, target));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int target = 8;
    int cnt = 3;
    std::vector<std::optional<int>> values{
        10, 5, -3, 3, 2, std::nullopt, 11, 3, -2, std::nullopt, 1};
    CheckSolution(values, target, cnt);
  }
  {
    int target = 22;
    std::vector<std::optional<int>> values{
        5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt,
        5, 1};
    int cnt = 3;
    CheckSolution(values, target, cnt);
  }
  {
    int target = 0;
    std::vector<std::optional<int>> values{1};
    int cnt = 0;
    CheckSolution(values, target, cnt);
  }
  {
    int target = 1;
    std::vector<std::optional<int>> values{1};
    int cnt = 1;
    CheckSolution(values, target, cnt);
  }
  {
    int target = 0;
    std::vector<std::optional<int>> values;
    int cnt = 0;
    CheckSolution(values, target, cnt);
  }
}
