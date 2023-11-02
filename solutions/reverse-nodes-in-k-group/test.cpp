#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int k;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3, 4, 5},
          .k = 2,
          .expected{2, 1, 4, 3, 5},
      },
      {
          .head{1, 2, 3, 4, 5},
          .k = 3,
          .expected{3, 2, 1, 4, 5},
      },
  };

  SECTION("Recursion") {
    for (const auto &[head, k, expected] : test_cases) {
      const List actual = recursive::Solution::reverseKGroup(Copy(head), k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[head, k, expected] : test_cases) {
      const List actual = iterative::Solution::reverseKGroup(Copy(head), k);
      REQUIRE(expected == actual);
    }
  }
}
