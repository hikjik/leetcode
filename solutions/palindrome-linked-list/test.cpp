#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 2, 1},
          .expected = true,
      },
      {
          .head{1, 2},
          .expected = false,
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const auto actual = Solution::isPalindrome(head);
    REQUIRE(expected == actual);
  }
}
