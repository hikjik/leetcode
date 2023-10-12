#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int n;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3, 4, 5},
          .n = 2,
          .expected{1, 2, 3, 5},
      },
      {
          .head{1},
          .n = 1,
          .expected{},
      },
      {
          .head{1, 2},
          .n = 1,
          .expected{1},
      },
  };

  for (const auto &[head, n, expected] : test_cases) {
    const List actual = Solution::removeNthFromEnd(Copy(head), n);
    REQUIRE(expected == actual);
  }
}
