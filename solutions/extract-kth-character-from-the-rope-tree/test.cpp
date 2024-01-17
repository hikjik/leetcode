#include <catch.hpp>

#include <solution.hpp>

#include <queue>
#include <variant>

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

RopeTreeNode *buildTree(
    const std::vector<std::variant<std::monostate, std::string, int>> &vals) {
  std::vector<RopeTreeNode *> nodes;
  for (const auto &val : vals) {
    std::visit(
        overloaded{
            [&](int x) { nodes.push_back(new RopeTreeNode(x)); },
            [&](const std::string &s) { nodes.push_back(new RopeTreeNode(s)); },
            [&](std::monostate) { nodes.push_back(nullptr); },
        },
        val);
  }

  auto length = [](RopeTreeNode *node) {
    return node ? node->len + node->val.size() : 0;
  };

  const int n = nodes.size();
  for (int i = 0, j = 1; i < n && j < n; ++i) {
    if (!nodes[i]) {
      continue;
    }
    if (length(nodes[i]) != length(nodes[i]->left) + length(nodes[i]->right)) {
      nodes[i]->left = nodes[j++];
    }
    if (length(nodes[i]) != length(nodes[i]->left) + length(nodes[i]->right)) {
      nodes[i]->right = nodes[j++];
    }
  }

  return nodes.front();
}

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::variant<std::monostate, std::string, int>> vals;
    int k;
    char expected;
  };

  std::vector<TestCase> test_cases{
      {
          .vals{10, 4, "abcpoe", "g", "rta"},
          .k = 6,
          .expected = 'b',
      },
      {
          .vals{12, 6, 6, "abc", "efg", "hij", "klm"},
          .k = 3,
          .expected = 'c',
      },
      {
          .vals{"ropetree"},
          .k = 3,
          .expected = 'p',
      },
      {
          .vals{2, std::monostate{}, "im"},
          .k = 1,
          .expected = 'i',
      },
  };

  SECTION("Recursive") {
    for (const auto &[vals, k, expected] : test_cases) {
      auto *root = buildTree(vals);
      const auto actual = recursive::Solution::getKthCharacter(root, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[vals, k, expected] : test_cases) {
      auto *root = buildTree(vals);
      const auto actual = iterative::Solution::getKthCharacter(root, k);
      REQUIRE(expected == actual);
    }
  }
}
