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
          .expected{4, 5, 1, 2, 3},
      },
      {
          .head{0, 1, 2},
          .k = 4,
          .expected{2, 0, 1},
      },
  };

  for (const auto &[head, k, expected] : test_cases) {
    const List actual = Solution::rotateRight(Copy(head), k);
    REQUIRE(expected == actual);
  }
}
