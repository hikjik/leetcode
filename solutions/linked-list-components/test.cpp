#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head = {0, 1, 2, 3},
          .nums{0, 1, 3},
          .expected = 2,
      },
      {
          .head = {0, 1, 2, 3, 4},
          .nums{0, 3, 1, 4},
          .expected = 2,
      },
  };

  for (const auto &[head, nums, expected] : test_cases) {
    const auto actual = Solution::numComponents(head, nums);
    REQUIRE(expected == actual);
  }
}
