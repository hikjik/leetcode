#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{3, 1},
          .expected{-1, -1},
      },
      {
          .head{5, 3, 1, 2, 5, 1, 2},
          .expected{1, 3},
      },
      {
          .head{1, 3, 2, 2, 3, 2, 2, 2, 7},
          .expected{3, 3},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const auto actual = Solution::nodesBetweenCriticalPoints(head);
    REQUIRE(expected == actual);
  }
}
