#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int left;
    int right;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3, 4, 5},
          .left = 2,
          .right = 4,
          .expected{1, 4, 3, 2, 5},
      },
      {
          .head{5},
          .left = 1,
          .right = 1,
          .expected{5},
      },
  };

  for (const auto &[head, left, right, expected] : test_cases) {
    const List actual = Solution::reverseBetween(Copy(head), left, right);
    REQUIRE(expected == actual);
  }
}
