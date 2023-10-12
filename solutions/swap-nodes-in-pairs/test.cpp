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
          .expected{2, 1, 4, 3},
      },
      {
          .head{},
          .expected{},
      },
      {
          .head{1},
          .expected{1},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::swapPairs(Copy(head));
    REQUIRE(expected == actual);
  }
}
