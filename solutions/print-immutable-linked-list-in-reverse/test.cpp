#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    ImmutableList head;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3, 4},
          .expected{4, 3, 2, 1},
      },
      {
          .head{0, -4, -1, 3, -5},
          .expected{-5, 3, -1, -4, 0},
      },
      {
          .head{-2, 0, 6, 4, 4, -6},
          .expected{-6, 4, 4, 6, 0, -2},
      },
  };

  SECTION("Recursion") {
    for (const auto &[head, expected] : test_cases) {
      recursion::Solution::printLinkedListInReverse(head);
      REQUIRE(expected == head.getPrintResults());
    }
  }

  SECTION("Stack") {
    for (const auto &[head, expected] : test_cases) {
      stack::Solution::printLinkedListInReverse(head);
      REQUIRE(expected == head.getPrintResults());
    }
  }
}
