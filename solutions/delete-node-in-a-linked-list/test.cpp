#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int node;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{4, 5, 1, 9},
          .node = 5,
          .expected{4, 1, 9},
      },
      {
          .head{4, 5, 1, 9},
          .node = 1,
          .expected{4, 5, 9},
      },
  };

  for (const auto &[head, node, expected] : test_cases) {
    ListNode *copy = Copy(head);
    Solution::deleteNode(Find(copy, node));
    REQUIRE(expected == List(copy));
  }
}
