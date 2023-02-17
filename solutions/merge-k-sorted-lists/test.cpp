#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<std::vector<int>> &values,
                   const std::vector<int> &expected) {
  std::vector<ListNode *> lists;
  for (size_t i = 0; i < values.size(); ++i) {
    lists.push_back(VectorToList(values[i]));
  }

  const auto merged_lists = Solution::mergeKLists(lists);
  REQUIRE(expected == ListToVector(merged_lists));

  FreeList(merged_lists);
  for (auto list : lists) {
    FreeList(list);
  }
}

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> values{{1, 4, 5}, {1, 3, 4}, {2, 6}};
    std::vector<int> expected{1, 1, 2, 3, 4, 4, 5, 6};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::vector<int>> values;
    std::vector<int> expected;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::vector<int>> values{{}};
    std::vector<int> expected;
    CheckSolution(values, expected);
  }
}
