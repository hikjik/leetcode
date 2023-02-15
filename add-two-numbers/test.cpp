#include <catch.hpp>

#include <list_node.hpp>
#include <solution.hpp>

#include <vector>

ListNode *VectorToList(std::vector<int> values) {
  ListNode *head = nullptr;
  for (auto it = values.rbegin(); it != values.rend(); ++it) {
    head = new ListNode(*it, head);
  }
  return head;
}

std::vector<int> ListToVector(ListNode *head) {
  std::vector<int> array;
  while (head) {
    array.push_back(head->val);
    head = head->next;
  }
  return array;
}

void FreeList(ListNode *head) {
  if (!head) {
    return;
  }

  FreeList(head->next);
  delete head;
}

void CheckSolution(const std::vector<int> &first,
                   const std::vector<int> &second,
                   const std::vector<int> &expected) {
  auto first_list = VectorToList(first);
  auto second_list = VectorToList(second);
  auto sum_list = Solution::addTwoNumbers(first_list, second_list);

  REQUIRE(expected == ListToVector(sum_list));

  FreeList(first_list);
  FreeList(second_list);
  FreeList(sum_list);
}

TEST_CASE("Simple") {
  {
    std::vector<int> first{2, 4, 3};
    std::vector<int> second{5, 6, 4};
    std::vector<int> expected{7, 0, 8};
    CheckSolution(first, second, expected);
  }
  {
    std::vector<int> first{0};
    std::vector<int> second{0};
    std::vector<int> expected{0};
    CheckSolution(first, second, expected);
  }
  {
    std::vector<int> first{9, 9, 9, 9, 9, 9, 9};
    std::vector<int> second{9, 9, 9, 9};
    std::vector<int> expected{8, 9, 9, 9, 0, 0, 0, 1};
    CheckSolution(first, second, expected);
  }
}
