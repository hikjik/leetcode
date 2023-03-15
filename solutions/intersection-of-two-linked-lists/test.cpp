#include <catch.hpp>

#include <solution.hpp>

ListNode *LinkLists(ListNode *head, ListNode *tail) {
  if (!head) {
    return tail;
  }

  auto node = head;
  while (node->next) {
    node = node->next;
  }
  node->next = tail;

  return head;
}

void CheckSolution(std::vector<int> values_a, std::vector<int> values_b,
                   size_t skip_a, size_t skip_b) {
  std::vector<int> common(values_a.begin() + skip_a, values_a.end());

  auto head_a = VectorToList({values_a.begin(), values_a.begin() + skip_a});
  auto head_b = VectorToList({values_b.begin(), values_b.begin() + skip_b});
  auto tail = VectorToList(common);

  head_a = LinkLists(head_a, tail);
  head_b = LinkLists(head_b, tail);

  auto intersection = Solution::getIntersectionNode(head_a, head_b);
  REQUIRE(EqualList(intersection, tail));

  FreeList(tail);
  while (skip_a--) {
    auto next = head_a->next;
    delete head_a;
    head_a = next;
  }
  while (skip_b--) {
    auto next = head_b->next;
    delete head_b;
    head_b = next;
  }
}

TEST_CASE("Simple") {
  {
    std::vector<int> values_a{4, 1, 8, 4, 5};
    std::vector<int> values_b{5, 6, 1, 8, 4, 5};
    int skip_a = 2, skip_b = 3;
    CheckSolution(values_a, values_b, skip_a, skip_b);
  }
  {
    std::vector<int> values_a{1, 9, 1, 2, 4};
    std::vector<int> values_b{3, 2, 4};
    int skip_a = 3, skip_b = 1;
    CheckSolution(values_a, values_b, skip_a, skip_b);
  }
  {
    std::vector<int> values_a{1, 2, 3, 4, 5};
    std::vector<int> values_b{3, 4, 5};
    int skip_a = 2, skip_b = 0;
    CheckSolution(values_a, values_b, skip_a, skip_b);
  }
  {
    std::vector<int> values_a{2, 6, 4};
    std::vector<int> values_b{1, 5};
    int skip_a = 3, skip_b = 2;
    CheckSolution(values_a, values_b, skip_a, skip_b);
  }
}
