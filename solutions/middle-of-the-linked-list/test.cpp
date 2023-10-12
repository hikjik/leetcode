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
          .expected{3, 4, 5},
      },
      {
          .head{1, 2, 3, 4, 5, 6},
          .expected{4, 5, 6},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const auto actual = Solution::middleNode(head);
    REQUIRE(expected == List(Copy(actual)));
  }
}
