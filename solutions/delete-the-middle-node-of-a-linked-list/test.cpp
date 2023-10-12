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
          .head{1, 3, 4, 7, 1, 2, 6},
          .expected{1, 3, 4, 1, 2, 6},
      },
      {
          .head{1, 2, 3, 4},
          .expected{1, 2, 4},
      },
      {
          .head{2, 1},
          .expected{2},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::deleteMiddle(Copy(head));
    REQUIRE(expected == actual);
  }
}
