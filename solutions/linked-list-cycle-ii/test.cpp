#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

ListNode *Advance(ListNode *head, int n) {
  auto node = head;
  for (int i = 0; i < n; ++i) {
    node = node->next;
  }
  return node;
}

int Length(ListNode *head) {
  int length = 0;
  for (auto node = head; node; node = node->next) {
    ++length;
  }
  return length;
}

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int pos;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{3, 2, 0, -4},
          .pos = 1,
          .expected{2, 0, -4},
      },
      {
          .head{1, 2},
          .pos = 0,
          .expected{1, 2},
      },
      {
          .head{1},
          .pos = -1,
          .expected{},
      },
  };

  for (const auto &[head, pos, expected] : test_cases) {
    List copy(head);

    ListNode *tail = nullptr;
    if (pos != -1) {
      tail = Advance(copy, Length(copy) - 1);
      tail->next = Advance(copy, pos);
    }

    const auto actual = Solution::detectCycle(copy);

    if (pos != -1) {
      tail->next = nullptr;
    }

    REQUIRE(expected == List(Copy(actual)));
  }
}
