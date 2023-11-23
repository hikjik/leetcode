#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    List head;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 3,
          .n = 5,
          .head = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0},
          .expected{{3, 0, 2, 6, 8}, {5, 0, -1, -1, 1}, {5, 2, 4, 9, 7}},
      },
      {
          .m = 1,
          .n = 4,
          .head = {0, 1, 2},
          .expected{{0, 1, 2, -1}},
      },
  };

  for (const auto &[m, n, head, expected] : test_cases) {
    const auto actual = Solution::spiralMatrix(m, n, head);
    REQUIRE(expected == actual);
  }
}
