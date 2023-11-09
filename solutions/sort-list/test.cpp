#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{4, 2, 1, 3},
          .expected{1, 2, 3, 4},
      },
      {
          .head{-1, 5, 3, 4, 0},
          .expected{-1, 0, 3, 4, 5},
      },
      {
          .head{},
          .expected{},
      },
  };

  SECTION("Recursive") {
    for (const auto &[head, expected] : test_cases) {
      const List actual = recursive::Solution::sortList(Copy(head));
      REQUIRE(expected == actual);
    }
  }
}
