#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<List> lists;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .lists{{1, 4, 5}, {1, 3, 4}, {2, 6}},
          .expected{1, 1, 2, 3, 4, 4, 5, 6},
      },
      {
          .lists{},
          .expected{},
      },
      {
          .lists{{}},
          .expected{},
      },
  };

  for (const auto &[lists, expected] : test_cases) {
    std::vector<ListNode *> copies;
    for (const auto &list : lists) {
      copies.push_back(Copy(list));
    }
    const List actual = Solution::mergeKLists(copies);
    REQUIRE(expected == actual);
  }
}
