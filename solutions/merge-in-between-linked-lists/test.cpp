#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List list1;
    int a;
    int b;
    List list2;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .list1 = {0, 1, 2, 3, 4, 5},
          .a = 3,
          .b = 4,
          .list2 = {1000000, 1000001, 1000002},
          .expected = {0, 1, 2, 1000000, 1000001, 1000002, 5},
      },
      {
          .list1 = {0, 1, 2, 3, 4, 5, 6},
          .a = 2,
          .b = 5,
          .list2 = {1000000, 1000001, 1000002, 1000003, 1000004},
          .expected = {0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6},
      },
  };

  for (const auto &[list1, a, b, list2, expected] : test_cases) {
    const List actual =
        Solution::mergeInBetween(Copy(list1), a, b, Copy(list2));
    REQUIRE(expected == actual);
  }
}
