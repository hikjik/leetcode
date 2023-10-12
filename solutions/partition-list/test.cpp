#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int x;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 4, 3, 2, 5, 2},
          .x = 3,
          .expected{1, 2, 2, 4, 3, 5},
      },
      {
          .head{2, 1},
          .x = 2,
          .expected{1, 2},
      },
  };

  for (const auto &[head, x, expected] : test_cases) {
    const auto actual = Solution::partition(head, x);
    REQUIRE(expected == List(Copy(actual)));
  }
}
