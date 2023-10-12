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
          .head{1, 2, 3, 4, 5},
          .expected{5, 4, 3, 2, 1},
      },
      {
          .head{1, 2},
          .expected{2, 1},
      },
      {
          .head{},
          .expected{},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::reverseList(Copy(head));
    REQUIRE(expected == actual);
  }
}
