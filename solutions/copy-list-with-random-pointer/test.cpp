#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(std::vector<std::pair<int, std::optional<int>>> values) {
  auto head = VectorToList(values);
  auto copy = Solution::copyRandomList(head);

  int n = values.size();
  std::vector<Node *> nodes(n, nullptr);
  auto node = copy;
  for (int i = 0; i < n; ++i) {
    REQUIRE(node);
    REQUIRE(values[i].first == node->val);
    nodes[i] = node;
    node = node->next;
  }
  for (int i = 0; i < n; ++i) {
    if (values[i].second) {
      const auto index = values[i].second.value();
      REQUIRE(nodes[index] == nodes[i]->random);
    } else {
      REQUIRE(nullptr == nodes[i]->random);
    }
  }

  FreeList(head);
  FreeList(copy);
}

TEST_CASE("Simple") {
  {
    std::vector<std::pair<int, std::optional<int>>> values{
        {7, std::nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    CheckSolution(values);
  }
  {
    std::vector<std::pair<int, std::optional<int>>> values{{1, 1}, {2, 1}};
    CheckSolution(values);
  }
  {
    std::vector<std::pair<int, std::optional<int>>> values{
        {3, std::nullopt}, {3, 0}, {3, std::nullopt}};
    CheckSolution(values);
  }
}
