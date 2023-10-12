#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int k;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3, 4, 5},
          .k = 2,
          .expected{1, 4, 3, 2, 5},
      },
      {
          .head{7, 9, 6, 6, 7, 8, 3, 0, 9, 5},
          .k = 5,
          .expected{7, 9, 6, 6, 8, 7, 3, 0, 9, 5},
      },
  };

  for (const auto &[head, k, expected] : test_cases) {
    const List actual = Solution::swapNodes(Copy(head), k);
    REQUIRE(expected == actual);
  }
}
