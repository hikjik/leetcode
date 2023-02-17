#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &first,
                   const std::vector<int> &second,
                   const std::vector<int> &expected) {
  auto first_list = VectorToList(first);
  auto second_list = VectorToList(second);
  auto merged_list = Solution::mergeTwoLists(first_list, second_list);

  REQUIRE(expected == ListToVector(merged_list));

  FreeList(first_list);
  FreeList(second_list);
  FreeList(merged_list);
}

TEST_CASE("Simple") {
  {
    std::vector<int> first{1, 2, 4};
    std::vector<int> second{1, 3, 4};
    std::vector<int> expected{1, 1, 2, 3, 4, 4};
    CheckSolution(first, second, expected);
  }
  {
    std::vector<int> first{};
    std::vector<int> second{};
    std::vector<int> expected{};
    CheckSolution(first, second, expected);
  }
  {
    std::vector<int> first{};
    std::vector<int> second{0};
    std::vector<int> expected{0};
    CheckSolution(first, second, expected);
  }
}
