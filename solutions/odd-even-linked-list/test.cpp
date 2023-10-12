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
          .expected{1, 3, 5, 2, 4},
      },
      {
          .head{2, 1, 3, 5, 6, 4, 7},
          .expected{2, 3, 6, 7, 1, 5, 4},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::oddEvenList(Copy(head));
    REQUIRE(expected == actual);
  }
}
