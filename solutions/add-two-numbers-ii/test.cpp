#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List l1;
    List l2;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .l1{7, 2, 4, 3},
          .l2{5, 6, 4},
          .expected{7, 8, 0, 7},
      },
      {
          .l1{2, 4, 3},
          .l2{5, 6, 4},
          .expected{8, 0, 7},
      },
      {
          .l1{0},
          .l2{0},
          .expected{0},
      },
  };

  for (const auto &[l1, l2, expected] : test_cases) {
    const List actual = Solution::addTwoNumbers(l1, l2);
    REQUIRE(expected == actual);
  }
}
