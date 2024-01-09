#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int m;
    int n;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
          .m = 2,
          .n = 3,
          .expected = {1, 2, 6, 7, 11, 12},
      },
      {
          .head = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
          .m = 1,
          .n = 3,
          .expected = {1, 5, 9},
      },
  };

  for (const auto &[head, m, n, expected] : test_cases) {
    const List actual = Solution::deleteNodes(Copy(head), m, n);
    REQUIRE(expected == actual);
  }
}
