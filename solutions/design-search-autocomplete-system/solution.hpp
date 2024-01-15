#pragma once

#include <array>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(NK+Q)
// Space: O(NK)

struct TrieNode {
  std::unordered_map<char, std::unique_ptr<TrieNode>> children;
  std::vector<TrieNode *> top3;
  std::string_view sentence;
  int times = 0;

  TrieNode *getChild(char c) const {
    return children.contains(c) ? children.at(c).get() : nullptr;
  }

  void setChild(char c) { children[c] = std::make_unique<TrieNode>(); }
};

class AutocompleteSystem : private TrieNode {
public:
  // O(NK)
  AutocompleteSystem(const std::vector<std::string> &sentences,
                     const std::vector<int> &times) {
    reset();
    for (int i = 0; i < std::ssize(times); ++i) {
      insert(sentences[i], times[i]);
    }
  }

  // O(1) on average
  std::vector<std::string> input(char c) {
    if (c == '#') {
      insert(currSentence, 1);
      reset();
      return {};
    }

    currSentence += c;
    if (currNode) {
      currNode = currNode->getChild(c);
    }
    if (!currNode) {
      return {};
    }

    std::vector<std::string> top3;
    for (auto *node : currNode->top3) {
      top3.emplace_back(node->sentence);
    }
    return top3;
  }

private:
  std::unordered_set<std::string> sentences;
  std::string currSentence;
  TrieNode *currNode;

  void reset() {
    currNode = getRoot();
    currSentence = "";
  }

  TrieNode *getRoot() { return this; }

  void insert(const std::string &sentence, int times) {
    auto [it, _] = sentences.insert(sentence);
    auto *node = getRoot();
    for (auto c : sentence) {
      if (!node->getChild(c)) {
        node->setChild(c);
      }
      node = node->getChild(c);
    }

    node->times += times;
    node->sentence = *it;
    updateTop(node);
  }

  void updateTop(auto *terminalNode) {
    for (auto *node = getRoot(); auto c : terminalNode->sentence) {
      node = node->getChild(c);
      if (std::ranges::find(node->top3, terminalNode) == node->top3.end()) {
        node->top3.push_back(terminalNode);
      }
      std::ranges::sort(node->top3, [](auto *node1, auto *node2) {
        return std::tie(node1->times, node2->sentence) >
               std::tie(node2->times, node1->sentence);
      });
      if (node->top3.size() > 3) {
        node->top3.pop_back();
      }
    }
  }
};
