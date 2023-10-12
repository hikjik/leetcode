#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int val;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 6, 3, 4, 5, 6},
          .val = 6,
          .expected{1, 2, 3, 4, 5},
      },
      {
          .head{},
          .val = 1,
          .expected{},
      },
      {
          .head{7, 7, 7, 7},
          .val = 7,
          .expected{},
      },
  };

  for (const auto &[head, val, expected] : test_cases) {
    const List actual = Solution::removeElements(Copy(head), val);
    REQUIRE(expected == actual);
  }
}
