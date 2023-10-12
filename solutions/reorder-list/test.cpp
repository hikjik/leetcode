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
          .head{1, 2, 3, 4},
          .expected{1, 4, 2, 3},
      },
      {
          .head{1, 2, 3, 4, 5},
          .expected{1, 5, 2, 4, 3},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    auto copy = Copy(head);
    Solution::reorderList(copy);
    REQUIRE(expected == List(copy));
  }
}
