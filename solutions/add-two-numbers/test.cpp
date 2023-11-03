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
          .l1{2, 4, 3},
          .l2{5, 6, 4},
          .expected{7, 0, 8},
      },
      {
          .l1{0},
          .l2{0},
          .expected{0},
      },
      {
          .l1{9, 9, 9, 9, 9, 9, 9},
          .l2{9, 9, 9, 9},
          .expected{8, 9, 9, 9, 0, 0, 0, 1},
      },
  };

  SECTION("Recursion") {
    for (const auto &[l1, l2, expected] : test_cases) {
      const List actual = recursion::Solution::addTwoNumbers(l1, l2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[l1, l2, expected] : test_cases) {
      const List actual = iterative::Solution::addTwoNumbers(l1, l2);
      REQUIRE(expected == actual);
    }
  }
}
