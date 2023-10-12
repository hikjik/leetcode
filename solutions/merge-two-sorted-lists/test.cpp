#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List list1;
    List list2;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .list1{1, 2, 4},
          .list2{1, 3, 4},
          .expected{1, 1, 2, 3, 4, 4},
      },
      {
          .list1{},
          .list2{},
          .expected{},
      },
      {
          .list1{},
          .list2{0},
          .expected{0},
      },
  };

  for (const auto &[list1, list2, expected] : test_cases) {
    const List actual = Solution::mergeTwoLists(list1, list2);
    REQUIRE(expected == actual);
  }
}
